#include "MainWindow.h"
#include "wx/stdpaths.h"
#include "wx/filename.h"

BEGIN_EVENT_TABLE(MainWindow, wxWindow)
	EVT_PAINT(MainWindow::OnPaint)
	EVT_LEFT_DOWN(MainWindow::OnMouseLeftDown)
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

void MainWindow::LoadPlayButton()
{
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\Play-Button-Icon-new.png");
	wxImage image(fileLocation, wxBITMAP_TYPE_PNG);

	this->playButton1 = new wxBitmap(image);
}

void MainWindow::LoadAboutButton()
{
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\About-Button-Icon-new.png");
	wxImage image(fileLocation, wxBITMAP_TYPE_PNG);

	this->aboutButton1 = new wxBitmap(image);
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
	this->LoadPlayButton();
	this->LoadAboutButton();
}

void MainWindow::OnMouseLeftDown(wxMouseEvent & event)
{
	
}

void MainWindow::OnPaint(wxPaintEvent & event)
{
	wxPaintDC pdc(this);
	if (backgroundMenu != nullptr) {
		pdc.DrawBitmap(*backgroundMenu, wxPoint(0, 0), true);
	}
	if (logo != nullptr) {
		pdc.DrawBitmap(*logo, wxPoint(30, 50), true); // y = 37
	}
	if (this->playButton1 != nullptr) {
		pdc.DrawBitmap(*playButton1, wxPoint(95, 200), true);
	}
	if (this->aboutButton1 != nullptr) {
		pdc.DrawBitmap(*aboutButton1, wxPoint(95, 410), true);
	}

	//this->playButton = new wxButton(this, 1002, wxT("PLAY"), wxPoint(125, 350), wxDefaultSize); // y - 30 390
	////this->aboutButton = new wxButton(this, wxID_ANY, wxT("ABOUT"), wxPoint(125, 425), wxDefaultSize);
	//this->aboutButton = new wxButton(this, 1001, wxT("ABOUT"), wxPoint(125, 395), wxDefaultSize); // y 425
}

MainWindow::~MainWindow()
{
}
