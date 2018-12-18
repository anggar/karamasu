#pragma once
#include "wx/wx.h"
#include "BackButton.h"
#include "SwitchFrame.h"

class TimeOverWindow : public wxWindow
{
public:
	TimeOverWindow(SwitchFrame *parent);
	~TimeOverWindow();
	void OnBackClick(wxCommandEvent &event);
	void OnPaint(wxPaintEvent &event);
	void SetScore(int num);
	wxDECLARE_EVENT_TABLE();

private:
	wxBitmap *bg;
	Button *back;
	SwitchFrame *switchFrame;
	int score;
};

