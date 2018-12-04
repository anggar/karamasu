#include "Kanji.h"

Kanji::Kanji(char utf, wxString meaning)
	: utf(utf), meaning(meaning)
{
}

wxString Kanji::GetChar() {
	return wxString(this->utf);
}

Kanji::~Kanji()
{
}
