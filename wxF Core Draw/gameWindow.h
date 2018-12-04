#pragma once
#include "wx/wx.h"
#include "SwitchFrame.h"

class GameWindow
	: public wxWindow
{
public:
	GameWindow(SwitchFrame *parent);
	void onMouseEvent(wxMouseEvent &event);
	void OnPaint(wxPaintEvent &event);
	~GameWindow();
private:
	wxBitmap *backgroundImage = nullptr;
	void LoadImageBackground();
	wxDECLARE_EVENT_TABLE();
};

