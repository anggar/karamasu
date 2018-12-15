#pragma once
#include "Button.h"

class PauseButton :
	public Button
{
public:
	PauseButton();
	~PauseButton();
	virtual bool checkMouse(int x, int y);
	virtual void DrawButton(wxPaintDC &pdc);
};

