#pragma once
#include "Button.h"

class PlayButton :
	public Button
{
private:
	wxBitmap *playButtonImage;

public:
	PlayButton();
	~PlayButton();
	virtual bool checkMouse(int x, int y);
	virtual void DrawButton(wxPaintDC &pdc);
};

