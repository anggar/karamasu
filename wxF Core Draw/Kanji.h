#pragma once
#include <string>
#include "wx/dynarray.h"

using std::string;

class Kanji
{
public:
	Kanji(char utf, string meaning);
	~Kanji();

private:
	char utf;
	string meaning;
};

