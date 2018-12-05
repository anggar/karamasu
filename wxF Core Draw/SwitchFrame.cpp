#include "SwitchFrame.h"
#include "MainWindow.h"
#include "GameWindow.h"

void SwitchFrame::fitWindowSize()
{
	this->boxSizer->Fit(this);
	this->boxSizer->SetSizeHints(this);
	this->SetSize(wxSize(360, 640));
	this->SetSizeHints(wxSize(360, 640), wxSize(360, 640));
	this->Layout();
}

SwitchFrame::SwitchFrame(const wxString & title)
	: wxFrame(NULL, wxID_ANY, title)
{
	this->InitComponents();
}

void SwitchFrame::InitComponents()
{
	boxSizer = new wxBoxSizer(wxVERTICAL);

	this->mainWindow = new MainWindow(this);
	this->mainWindow->Show(false);
	this->boxSizer->Add(mainWindow, 1, wxEXPAND, 0);

	this->GameWindows = new GameWindow(this);
	this->GameWindows->Show(false);
	this->boxSizer->Add(GameWindows, 1, wxEXPAND, 0);

	SetSizer(boxSizer);

	ShowMainWindow();
}

void SwitchFrame::ShowMainWindow()
{
	this->mainWindow->Show(true);
	this->GameWindows->Show(false);

	fitWindowSize();
}

void SwitchFrame::ShowGameWindow()
{
	this->mainWindow->Show(false);
	this->GameWindows->Show(true);

	fitWindowSize();
}

SwitchFrame::~SwitchFrame()
{
}
