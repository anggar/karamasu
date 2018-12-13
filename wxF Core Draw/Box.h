#pragma once
#include "wx/wx.h"
#include "wx/dcclient.h"
#include "wx/dcbuffer.h"
#include "Kanji.h"

class Box
{
public:
	Box(Kanji *kanji, int type, int posx, int posy, int state);
	void Draw(wxPaintDC &dc);
	void Draw(wxBufferedPaintDC &dc);
	void ChangeState(int state);
	int GetState();

	~Box();
private:
	int state;
	wxPoint position;
	Kanji *kkanji;
	int type = 0;
};

