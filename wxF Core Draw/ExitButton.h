#pragma once
#include "Button.h"

class ExitButton :
	public Button
{
public:
	wxBitmap *exitButtonImage;
	wxBitmap *exitButtonImageHover;
	
	ExitButton();
	~ExitButton();
	virtual bool checkMouse(int x, int y);
	virtual void DrawButton(wxPaintDC &pdc);
	virtual void DrawButtonHover(wxPaintDC &pdc);
};

