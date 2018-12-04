#pragma once
#include "wx/wx.h"
#include "wx/dcclient.h"
#include "Kanji.h"

class Box
{
public:
	Box(Kanji kanji, int type = 0);
	void Draw(wxPaintDC &dc);
	~Box();
private:
	wxPoint position;
	Kanji kanji;
	int type = 0;
};

