#pragma once
#include "wx/wx.h"

class MainWindow;
class GameWindow;
class HowToPlayWindow;

class SwitchFrame :
	public wxFrame
{
private:
	wxBoxSizer *boxSizer;
	MainWindow *mainWindow;
	GameWindow *GameWindows;
	HowToPlayWindow *HowWindow;

	void fitWindowSize();

public:
	SwitchFrame(const wxString &title);
	void InitComponents();
	void ShowMainWindow();
	void ShowGameWindow();
	void ShowHowToPlayWIndow();
	~SwitchFrame();
};

