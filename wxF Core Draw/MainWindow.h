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
	wxBitmap *playButton1;
	wxBitmap *aboutButton1;
	wxButton *aboutButton;
	void LoadImageLogo();
	void LoadBackgroundMenu();
	void LoadPlayButton();
	void LoadAboutButton();
	SwitchFrame *parentFrame;

public:
	MainWindow(SwitchFrame *parent);
	void OnMouseLeftDown(wxMouseEvent &event);
	void OnPaint(wxPaintEvent &event);
	~MainWindow();
	wxDECLARE_EVENT_TABLE();
};

