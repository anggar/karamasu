#pragma once
#include "wx/wx.h"
#include "SwitchFrame.h"
#include "sqlite3.h"

class BoxArray;
class RadicalArray;

class GameWindow
	: public wxWindow
{
public:
	GameWindow(SwitchFrame *parent);
	void OnMouseEvent(wxMouseEvent &event);
	void OnTimer(wxTimerEvent &event);
	void OnPaint(wxPaintEvent &event);
	void StartTimer();

	~GameWindow();
private:
	wxTimer *timer;
	wxBitmap *backgroundImage = nullptr;
	
	BoxArray *boxes;
	void LoadImageBackground();
	void UpdateScore(int num);
	char scoreArr[4] = { '0','0','0','0' };
	int score = 0;
	static const int TIME_LIMIT = 300;
 	wxDECLARE_EVENT_TABLE();
};

