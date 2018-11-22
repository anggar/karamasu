#pragma once
#include "wx/wx.h"

class gameWindow;

class gameFrame
	: public wxFrame
{
private:
	gameWindow *canvas;
	void InitComponents();
public:
	gameFrame(const wxString& title);
	~gameFrame();
};

