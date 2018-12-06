#pragma once
#include "wx/wx.h"
#include "SwitchFrame.h"
#include "sqlite3.h"

class BoxArray;

class GameWindow
	: public wxWindow
{
public:
	GameWindow(SwitchFrame *parent);
	void OnMouseEvent(wxMouseEvent &event);
	void OnTimer(wxTimerEvent &event);
	void OnPaint(wxPaintEvent &event);
	~GameWindow();
private:
	wxTimer *timer;
	wxBitmap *backgroundImage = nullptr;
	
	BoxArray *boxes;

	void LoadKanji(int category, int datalen);

	void LoadImageBackground();
	
	wxDECLARE_EVENT_TABLE();
};

