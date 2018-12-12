#pragma once
#include "wx/wx.h"

class Button
{
public:
	wxBitmap *buttonImage;
	wxBitmap *buttonImageHover;

	Button();
	~Button();
	virtual bool checkMouse(int x, int y) = 0;
	virtual void DrawButton(wxPaintDC &pdc) = 0;
	
	int width, height, x, y;
};

