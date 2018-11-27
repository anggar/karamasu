#pragma once
#include "wx/wx.h"

class MainWindow;

class MainFrame :
	public wxFrame
{
private:
	MainWindow *mainMenuWindow;
	void InitComponents();

public:
	MainFrame(const wxString &title);
	~MainFrame();
};

