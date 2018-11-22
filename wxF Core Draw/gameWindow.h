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
	void OnPaint(wxPaintEvent &event);
	~gameWindow();
private:
	wxBitmap *backgroundImage = nullptr;
	void LoadImageBackground();
	wxDECLARE_EVENT_TABLE();
};

