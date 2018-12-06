#pragma once
#include "wx/wx.h"
#include "wx/sound.h"
#include "SwitchFrame.h"
#include "Button.h"
#include "PlayButton.h"
#include "AboutButton.h"
#include "Flower.h"

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

	wxBitmapButton *playButton;
	wxBitmapButton *aboutButton;

	wxTimer *timer;

public:
	MainWindow(SwitchFrame *parent);
	void OnMouseLeftDown(wxMouseEvent &event);
	void OnPaint(wxPaintEvent &event);
	void OnPlayClick(wxCommandEvent &event);
	void OnAboutClick(wxCommandEvent &event);
	void OnTimer(wxTimerEvent &event);
	~MainWindow();
	wxDECLARE_EVENT_TABLE();
};

