#pragma once
#include "wx/wx.h"
#include "MainFrame.h"

class MainWindow :
	public wxWindow
{
private:
	wxBitmap *logo;
	wxBitmap *backgroundMenu;
	wxButton *playButton;
	//wxButton *exitButton;
	wxButton *aboutButton;
	void LoadImageLogo();
	void LoadBackgroundMenu();

public:
	MainWindow(MainFrame *parent);
	void OnPaint(wxPaintEvent &event);
	void AboutButtonClick(wxCommandEvent &event);
	~MainWindow();
	wxDECLARE_EVENT_TABLE();
};

