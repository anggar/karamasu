#pragma once
#include "wx/wx.h"
#include "SwitchFrame.h"

class Button
{
public:
	Button();
	~Button();
	virtual bool checkMouse(int x, int y) = 0;
	virtual void DrawButton(wxPaintDC &pdc) = 0;
	virtual void DrawButtonHover(wxPaintDC &pdc) = 0;
	SwitchFrame *appFrame;
	
	int width, height, x, y;
};

