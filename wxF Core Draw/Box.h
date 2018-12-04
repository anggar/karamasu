#pragma once
#include "wx/wx.h"
#include "wx/dcclient.h"
#include "Kanji.h"

class Box
{
public:
	Box(Kanji *kanji, int type, int posx, int posy, int state);
	void Draw(wxPaintDC &dc, const wxBrush &br);
	void ChangeState(int state);

	~Box();
private:
	int state;
	wxPoint position;
	Kanji *kkanji;
	int type = 0;
};

