#pragma once
#include "wx/wx.h"

class gameWindow;

class gameFrame
	: public wxFrame
{
private:
	gameWindow *canvas;
	void InitComponents();
	void OnButtonClick(wxCommandEvent &event) {

	}
public:
	gameFrame(const wxString& title);
	~gameFrame();
};

