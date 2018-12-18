#pragma once
#include "wx/wx.h"

class MainWindow;
class GameWindow;
class HowToPlayWindow;
class TimeOverWindow;

class SwitchFrame :
	public wxFrame
{
private:
	wxBoxSizer *boxSizer;
	MainWindow *mainWindow;
	GameWindow *GameWindows;
	HowToPlayWindow *HowWindow;
	TimeOverWindow *timeOver;

	void fitWindowSize();

public:
	SwitchFrame(const wxString &title);
	void InitComponents();
	void ShowMainWindow();
	void ShowGameWindow();
	void ShowHowToPlayWIndow();
	void ShowTimeOver(int numScore);
	~SwitchFrame();
};

