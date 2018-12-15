#pragma once
#include "wx/wx.h"
#include "SwitchFrame.h"
#include "sqlite3.h"
#include "BackButton.h"
#include "PauseButton.h"

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
	void OnBackClick(wxCommandEvent &event);
	void OnPauseClick(wxCommandEvent &event);
	void StartTimer();

	~GameWindow();
private:
	wxTimer *timer;
	wxBitmap *backgroundImage = nullptr;
	SwitchFrame *switchFrame;
	Button *back;
	Button *pause;
	wxBitmapButton *backButton;
	wxBitmapButton *pauseButton;
	
	BoxArray *boxes;
	void LoadImageBackground();
	void UpdateScore(int num);
	char scoreArr[4] = { '0','0','0','0' };
	int score = 0;
	int TIME_LIMIT = 300;
	int timerCount;
 	wxDECLARE_EVENT_TABLE();
};

