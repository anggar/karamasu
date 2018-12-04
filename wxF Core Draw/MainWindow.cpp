#include "MainWindow.h"
#include "wx/stdpaths.h"
#include "wx/filename.h"

BEGIN_EVENT_TABLE(MainWindow, wxWindow)
	EVT_PAINT(MainWindow::OnPaint)
	EVT_BUTTON(1001, MainWindow::AboutButtonClick)
	EVT_BUTTON(1002, MainWindow::PlayButtonClick)
END_EVENT_TABLE()

void MainWindow::LoadImageLogo()
{
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\Logo2.png");
	wxImage image(fileLocation, wxBITMAP_TYPE_PNG);

	this->logo = new wxBitmap(image);
}

void MainWindow::LoadBackgroundMenu()
{
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\BG_YAMA_01.jpg");
	wxImage image(fileLocation, wxBITMAP_TYPE_JPEG);

	this->backgroundMenu = new wxBitmap(image);
}

MainWindow::MainWindow(SwitchFrame * parent)
	: wxWindow(parent, wxID_ANY), parentFrame(parent)
{
	this->SetBackgroundColour(wxColour(*wxWHITE));

	wxImageHandler *pngHandler = new wxPNGHandler;
	wxImageHandler *jpgHandler = new wxJPEGHandler;

	wxImage::AddHandler(pngHandler);
	wxImage::AddHandler(jpgHandler);

	wxClientDC dc(this);

	this->LoadBackgroundMenu();
	this->LoadImageLogo();
}

void MainWindow::PlayButtonClick(wxCommandEvent & event)
{
	this->parentFrame->ShowGameWindow();
}

void MainWindow::OnPaint(wxPaintEvent & event)
{
	wxPaintDC pdc(this);
	if (backgroundMenu != nullptr) {
		pdc.DrawBitmap(*backgroundMenu, wxPoint(0, 0), true);
	}
	if (logo != nullptr) {
		pdc.DrawBitmap(*logo, wxPoint(30, 200), true); // y = 37
	}

	this->playButton = new wxButton(this, 1002, wxT("PLAY"), wxPoint(125, 350), wxDefaultSize); // y - 30 390
	//this->aboutButton = new wxButton(this, wxID_ANY, wxT("ABOUT"), wxPoint(125, 425), wxDefaultSize);
	this->aboutButton = new wxButton(this, 1001, wxT("ABOUT"), wxPoint(125, 395), wxDefaultSize); // y 425
}

void MainWindow::AboutButtonClick(wxCommandEvent & event)
{
	wxMessageBox(wxT("Karamasu Version 1.0\nMade By Anggar and Bayu\n"));
}

MainWindow::~MainWindow()
{
}
