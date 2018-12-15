#pragma once
#include "wx/wx.h"
#include "SwitchFrame.h"
#include "BackButton.h"

class HowToPlayWindow : public wxWindow
{
public:
	HowToPlayWindow(SwitchFrame *parent);
	~HowToPlayWindow();
	void LoadImages();
	void OnPaint(wxPaintEvent &event);
	void LoadLogo();
	void OnBackClick(wxCommandEvent &event);
	wxDECLARE_EVENT_TABLE();

private:
	SwitchFrame *switchFrame;
	wxBitmap *backgroundImg;
	wxBitmap *logoImg;
	wxBitmap *sprites;

	Button *back;

};

