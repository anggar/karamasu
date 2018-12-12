#pragma once
#include "Button.h"
class AboutButton :
	public Button
{

public:
	/*wxBitmap *aboutButtonImage;
	wxBitmap *aboutButtonImageHover;*/

	AboutButton();
	~AboutButton();
	virtual bool checkMouse(int x, int y);
	virtual void DrawButton(wxPaintDC &pdc);

};

