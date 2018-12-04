#pragma once
#include "wx/wx.h"

class MainWindow;
class GameWindow;

class SwitchFrame :
	public wxFrame
{
private:
	wxBoxSizer *boxSizer;
	MainWindow *mainWindow;
	GameWindow *GameWindows;

	void fitWindowSize();

public:
	SwitchFrame(const wxString &title);
	void InitComponents();
	void ShowMainWindow();
	void ShowGameWindow();
	~SwitchFrame();
};

