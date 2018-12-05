#pragma once
#include "Button.h"
class AboutButton :
	public Button
{
private:
	wxBitmap *aboutButtonImage;

public:
	AboutButton();
	~AboutButton();
	virtual bool checkMouse(int x, int y);
	virtual void DrawButton(wxPaintDC &pdc);
};

