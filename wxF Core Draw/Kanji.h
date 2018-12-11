#pragma once
#include "wx/wx.h"
#include <wx/string.h>
#include "wx/dynarray.h"
#include <vector>

class Kanji
{
public:
	Kanji();
	Kanji(wxString utf);
	Kanji(wxString utf, wxString meaning);
	~Kanji();
	wxString GetChar();
	void SetChar(wxString utf);
	static int SetRandomRadical();
	void RandomKanjiFromRadical(wxString radical);
	static std::vector<wxString> *radicalSelection;
private:
	static int SetRandomKanji(void *k, int argc, char **argv, char **azColName);
	static int SetRadicalSelection(void *k, int argc, char **argv, char **azColName);
	void LoadDB(int f(void *, int, char**, char **), char* sql, void *ref);
	static void LoadDB(int f(void *, int, char**, char **), char* sql);

	static const int LIMIT = 3;
	wxString utf;
	wxString radical;
	wxString meaning;
};