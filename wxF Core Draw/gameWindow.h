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
	void ResetGameState();

	~GameWindow();
private:
	wxTimer *timer;
	wxBitmap *backgroundImage = nullptr;
	wxBitmap *timerBackground = nullptr;
	SwitchFrame *switchFrame;
	Button *back;
	Button *pause;
	
	BoxArray *boxes;
	void LoadImageBackground();
	void UpdateScore(int num);
	int score = 0;
	int TIME_LIMIT = 300;
	int pauseState = 0;
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	wxDECLARE_EVENT_TABLE();
};

