#include "Kanji.h"
#include <string>
#include <vector>
#include "sqlite3.h"

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

void Kanji::RandomKanji() {
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;

	rc = sqlite3_open("Kanji.db", &db);

	if (rc) 
		sqlite3_close(db);

	rc = sqlite3_exec(db, "SELECT kan, meaning FROM KanjiRadical ORDER BY RANDOM() LIMIT 1;", Kanji::SetRandomKanji, this, &zErrMsg);
	if (rc != SQLITE_OK) {
		sqlite3_free(zErrMsg);
	}

	sqlite3_close(db);
}

Kanji::~Kanji()
{
}
