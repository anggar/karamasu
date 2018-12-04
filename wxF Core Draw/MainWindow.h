#pragma once
#include "wx/wx.h"
#include "SwitchFrame.h"

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
	SwitchFrame *parentFrame;

public:
	MainWindow(SwitchFrame *parent);
	void PlayButtonClick(wxCommandEvent &event);
	void OnPaint(wxPaintEvent &event);
	void AboutButtonClick(wxCommandEvent &event);
	~MainWindow();
	wxDECLARE_EVENT_TABLE();
};

