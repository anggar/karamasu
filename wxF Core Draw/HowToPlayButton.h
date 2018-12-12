#pragma once
#include "Button.h"
class HowToPlayButton :
	public Button
{
public:
	/*wxBitmap *howToPlayButtonImage;
	wxBitmap *howToPlayButtonImageHover;
	*/
	virtual bool checkMouse(int x, int y);
	virtual void DrawButton(wxPaintDC &pdc);

	HowToPlayButton();
	~HowToPlayButton();
};

