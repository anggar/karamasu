#include "gameFrame.h"
#include "gameWindow.h"


gameFrame::gameFrame(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title)
{
	this->InitComponents();
}

void gameFrame::InitComponents() {
	this->canvas = new gameWindow(this);
	this->SetInitialSize(wxSize(360, 640));
	this->SetSizeHints(wxSize(360, 640), wxSize(360, 640));
}


gameFrame::~gameFrame()
{
}
