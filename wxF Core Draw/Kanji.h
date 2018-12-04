#pragma once
#include <wx/string.h>
#include "wx/dynarray.h"

class Kanji
{
public:
	Kanji(char utf, wxString meaning);
	~Kanji();
	wxString GetChar();

private:
	char utf;
	wxString meaning;
};

