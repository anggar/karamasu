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

MainWindow::MainWindow(SwitchFrame * parent)
	: wxWindow(parent, wxID_ANY), parentFrame(parent)
{
	this->SetBackgroundColour(wxColour(*wxWHITE));

	wxImageHandler *pngHandler = new wxPNGHandler;
	wxImageHandler *jpgHandler = new wxJPEGHandler;

	wxImage::AddHandler(pngHandler);
	wxImage::AddHandler(jpgHandler);

	wxClientDC dc(this);

	// -- DEFINING THE BUTTON -- //
	this->playBtn = new PlayButton();
	this->aboutBtn = new AboutButton();

	// -- LOAD THE LOGO AND THE BACKGROUND -- //
	this->LoadBackgroundMenu();
	this->LoadImageLogo();
}

void MainWindow::OnMouseLeftDown(wxMouseEvent & event)
{
	int mouseX = event.GetX(), mouseY = event.GetY();

	// -- Check if the mouse in the Play Button position -- //
	if (playBtn != nullptr) {
		if (playBtn->checkMouse(mouseX, mouseY))
			parentFrame->ShowGameWindow();
			//wxMessageOutputDebug().Printf("%s", "Play button clicked");
	}

	// -- Check if the mouse in the About Button position -- //
	if (aboutBtn != nullptr) {
		if (aboutBtn->checkMouse(mouseX, mouseY))
			wxMessageBox(wxT("Karamasu The Game"), wxT("About this Game"));
			//wxMessageOutputDebug().Printf("%s", "About button clicked");
	}	
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
	if (playBtn != nullptr) {
		playBtn->DrawButton(pdc);
	}
	if (aboutBtn != nullptr) {
		aboutBtn->DrawButton(pdc);
	}
}

MainWindow::~MainWindow()
{
}
