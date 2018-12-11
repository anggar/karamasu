#include "Kanji.h"
#include <string>
#include <vector>
#include "sqlite3.h"
#include <wx/arrimpl.cpp>

std::vector<wxString> * Kanji::radicalSelection = new std::vector<wxString>;
	
Kanji::Kanji()
{
	char sql[200];
	int idx = rand() % LIMIT;

	wxString rad = radicalSelection->at(idx);
	char unrep[4];
	memcpy(unrep, rad.mb_str(wxConvUTF8).data(), LIMIT);
	sprintf(sql, "SELECT kan, meaning FROM KanjiRadical WHERE rad = CAST(x'%hhX%hhX%hhX' AS TEXT) ORDER BY RANDOM() LIMIT 1;", unrep[0], unrep[1], unrep[2]);
	
	LoadDB(Kanji::SetRandomKanji, sql, this);
}

Kanji::Kanji(wxString utf)
	: utf(utf)
{
}

Kanji::Kanji(wxString utf, wxString meaning)
	: utf(utf), meaning(meaning)
{
}

wxString Kanji::GetChar() {
	return this->utf;
}

void Kanji::SetChar(wxString utf) {
	this->utf = utf;
}

int Kanji::SetRandomRadical() {
	std::vector<wxString> *radicalSelection = new std::vector<wxString>;
	LoadDB(Kanji::SetRadicalSelection, "SELECT rad FROM KanjiRadical GROUP BY rad HAVING COUNT(*) > 36 ORDER BY RANDOM() LIMIT 4;");
	return 0;
}


int Kanji::SetRadicalSelection(void *k, int argc, char **argv, char **azColName) {
	char unicodeRep[4];

	for (int i = 0; i < argc; i++) {
		if (strcmp(azColName[i], "rad") == 0) {
			memcpy(unicodeRep, argv[i], 4);
			radicalSelection->push_back(wxString::FromUTF8(unicodeRep));
		}
	}


	return 0;
}

int Kanji::SetRandomKanji(void *k, int argc, char **argv, char **azColName) {
	char unicodeRep[4];

	Kanji *ref = static_cast<Kanji*>(k);

	for (int i = 0; i < argc; i++) {
		if (strcmp(azColName[i], "kan") == 0) {
			memcpy(unicodeRep, argv[i], 4);
			ref->SetChar(wxString::FromUTF8(unicodeRep));
		}
	}

	return 0;
}

void Kanji::LoadDB(int f(void *, int, char**, char **), char* sql, void* ref) {
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;

	rc = sqlite3_open("Kanji.db", &db);

	if (rc)
		sqlite3_close(db);

	rc = sqlite3_exec(db, sql, f, ref, &zErrMsg);
	if (rc != SQLITE_OK) {
		sqlite3_free(zErrMsg);
	}

	sqlite3_close(db);
}

void Kanji::LoadDB(int f(void *, int, char**, char **), char* sql) {
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;

	rc = sqlite3_open("Kanji.db", &db);

	if (rc)
		sqlite3_close(db);

	rc = sqlite3_exec(db, sql, f, NULL, &zErrMsg);
	if (rc != SQLITE_OK) {
		sqlite3_free(zErrMsg);
	}

	sqlite3_close(db);
}

Kanji::~Kanji()
{
}
