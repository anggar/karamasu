#pragma once
#include "wx/wx.h"
#include "SwitchFrame.h"
#include "Button.h"
#include "PlayButton.h"
#include "AboutButton.h"

class MainWindow :
	public wxWindow
{
private:
	wxBitmap *logo;
	wxBitmap *backgroundMenu;
	
	void LoadImageLogo();
	void LoadBackgroundMenu();
	
	SwitchFrame *parentFrame;

	Button *playBtn;
	Button *aboutBtn;
	//wxTimer *timer;

public:
	MainWindow(SwitchFrame *parent);
	void OnMouseLeftDown(wxMouseEvent &event);
	void OnPaint(wxPaintEvent &event);
	~MainWindow();
	wxDECLARE_EVENT_TABLE();
};

