#pragma once
#include <wx/string.h>
#include "wx/dynarray.h"

class Kanji
{
public:
	Kanji(wxString utf, wxString meaning);
	~Kanji();
	wxString GetChar();
	void SetChar(wxString utf);
	void RandomKanjiFromRadical(wxString radical);
	void RandomKanji();
private:
	static int SetRandomKanji(void *k, int argc, char **argv, char **azColName);
	wxString utf;
	wxString meaning;
};

