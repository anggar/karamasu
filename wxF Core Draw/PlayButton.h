#pragma once
#include "Button.h"

class PlayButton :
	public Button
{
private:
	

public:
	wxBitmap *playButtonImage;
	wxBitmap *playButtonImageHover;

	PlayButton();
	~PlayButton();
	virtual bool checkMouse(int x, int y);
	virtual void DrawButton(wxPaintDC &pdc);
	virtual void DrawButtonHover(wxPaintDC &pdc);
};

