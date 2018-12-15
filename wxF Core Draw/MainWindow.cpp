#include "MainWindow.h"
#include "wx/stdpaths.h"
#include "wx/arrimpl.cpp"
#include "wx/filename.h"
#define TIMER_ID 2000
typedef unsigned int uint;

WX_DEFINE_OBJARRAY(FlowerArray);

BEGIN_EVENT_TABLE(MainWindow, wxWindow)
	EVT_PAINT(MainWindow::OnPaint)
	EVT_TIMER(TIMER_ID, MainWindow::OnTimer)
	EVT_BUTTON(1001, MainWindow::OnPlayClick)
	EVT_BUTTON(1002, MainWindow::OnAboutClick)
	EVT_BUTTON(1003, MainWindow::OnExitClick)
	EVT_BUTTON(1004, MainWindow::OnHowClick)
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
	: wxWindow(parent, wxID_ANY), switchFrame(parent)
{
	this->SetBackgroundColour(wxColour(*wxWHITE));

	// -- CREATING IMAGE HANDLER -- //
	wxImageHandler *pngHandler = new wxPNGHandler;
	wxImageHandler *jpgHandler = new wxJPEGHandler;
	wxImage::AddHandler(pngHandler);
	wxImage::AddHandler(jpgHandler);

	// -- DEFINING THE BUTTON CLASS -- //
	this->play = new PlayButton(this);
	this->about = new AboutButton(this);
	this->exit = new ExitButton(this);
	this->how = new HowToPlayButton(this);

	// -- LOAD THE LOGO AND THE BACKGROUND -- //
	this->LoadBackgroundMenu();
	this->LoadImageLogo();

	// -- CREATE THE BUTTON -- //
	play->SetButton(95, 190, 1001);
	about->SetButton(95, 450, 1002);
	how->SetButton(95, 400, 1004);
	exit->SetButton(95, 500, 1003);

	PlaySound(TEXT("BG-Music3.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	temp = new Flower(10, 500, 3, 2);
	this->flowerContainer.Add(temp);
	temp = new Flower(10, 10, -2, 3);
	this->flowerContainer.Add(temp);
	temp = new Flower(300, 10, 3, 3);
	this->flowerContainer.Add(temp);
	temp = new Flower(300, 500, -3, 2);
	this->flowerContainer.Add(temp);

	timer = new wxTimer(this, TIMER_ID);
	//timer->Start(60);
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

	for (uint i = 0; i < flowerContainer.GetCount(); i++) {
		Flower *temp1 = flowerContainer[i];
		if (temp1 != nullptr) {
			temp1->Draw(pdc);
		}
	}

	if (logo != nullptr) {
		pdc.DrawBitmap(*logo, wxPoint(30, 50), true); // y = 37
	}
}

void MainWindow::OnPlayClick(wxCommandEvent & event)
{
	switchFrame->ShowGameWindow();
}

void MainWindow::OnAboutClick(wxCommandEvent & event)
{
	wxMessageBox(wxT("Karamasu Version 1.0\n\nThis game was developed by Bayu Laksana and Anggar.\nCopyright 2018. "), wxT("About"));
	//this->switchFrame->Close(true);
}

void MainWindow::OnExitClick(wxCommandEvent & event)
{
	this->switchFrame->Close(true);
}

void MainWindow::OnHowClick(wxCommandEvent & event)
{
	this->switchFrame->ShowHowToPlayWIndow();
}

void MainWindow::OnTimer(wxTimerEvent & event)
{
	for (uint i = 0; i < flowerContainer.GetCount(); i++) {
		Flower *temp1 = flowerContainer[i];
		if (temp1 != nullptr) {
			temp1->Move(GetClientSize().GetWidth(), GetClientSize().GetHeight());
		}
	}
	Refresh();
	Update();
}

MainWindow::~MainWindow()
{
	
}
