#include "MainFrame.h"
#include "MainWindow.h"


void MainFrame::InitComponents()
{
	this->mainMenuWindow = new MainWindow(this);
	this->SetInitialSize(wxSize(360, 640));
	this->SetSizeHints(wxSize(360, 640), wxSize(360, 640));
}

MainFrame::MainFrame(const wxString & title)
	: wxFrame(NULL, wxID_ANY, title)
{
	this->InitComponents();
}

MainFrame::~MainFrame()
{
}
