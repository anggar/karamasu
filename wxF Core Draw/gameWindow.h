#pragma once
#include "wx/wx.h"
#include "gameFrame.h"

class gameWindow
	: public wxWindow
{
public:
	gameWindow(gameFrame *parent);
	void onMouseLeftUp(wxMouseEvent &event);
	void onMouseLeftDown(wxMouseEvent &event);
	void onMouseMotion(wxMouseEvent &event);
	~gameWindow();
private:
	wxDECLARE_EVENT_TABLE();
};

