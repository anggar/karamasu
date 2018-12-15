#pragma once
#include "wx/wx.h"
#include "wx/sound.h"
#include "SwitchFrame.h"
#include "Button.h"
#include "PlayButton.h"
#include "AboutButton.h"
#include "Flower.h"
#include "ExitButton.h"
#include "HowToPlayButton.h"

WX_DECLARE_OBJARRAY(Flower*, FlowerArray);

class MainWindow :
	public wxWindow
{
private:
	FlowerArray flowerContainer;
	Flower *temp;
	wxBitmap *logo;
	wxBitmap *backgroundMenu;
	
	void LoadImageLogo();
	void LoadBackgroundMenu();
	
	SwitchFrame *switchFrame;

	Button *play;
	Button *about;
	Button *exit;
	Button *how;

	wxTimer *timer;

public:
	MainWindow(SwitchFrame *parent);
	void OnMouseLeftDown(wxMouseEvent &event);
	void OnPaint(wxPaintEvent &event);
	void OnPlayClick(wxCommandEvent &event);
	void OnAboutClick(wxCommandEvent &event);
	void OnExitClick(wxCommandEvent &event);
	void OnHowClick(wxCommandEvent &event);
	void OnTimer(wxTimerEvent &event);
	~MainWindow();
	wxDECLARE_EVENT_TABLE();
};

