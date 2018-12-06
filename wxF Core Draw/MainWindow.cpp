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

	wxClientDC dc(this);

	// -- DEFINING THE BUTTON CLASS -- //
	this->play = new PlayButton();
	this->about = new AboutButton();
	this->exit = new ExitButton();

	// -- LOAD THE LOGO AND THE BACKGROUND -- //
	this->LoadBackgroundMenu();
	this->LoadImageLogo();

	// -- CREATE THE BUTTON -- //
	PlayButton *playCast = (PlayButton*) play;
	AboutButton *aboutCast = (AboutButton*) about;
	ExitButton *exitCast = (ExitButton*) exit;
	
	this->playButton = new wxBitmapButton(this, 1001, *(playCast->playButtonImage), wxPoint(playCast->x, playCast->y), wxDefaultSize, wxBORDER_NONE);
	this->playButton->SetBitmapCurrent(*(playCast->playButtonImageHover));

	this->aboutButton = new wxBitmapButton(this, 1002, *(aboutCast->aboutButtonImage), wxPoint(aboutCast->x, aboutCast->y), wxDefaultSize, wxBORDER_NONE);
	this->aboutButton->SetBitmapCurrent(*(aboutCast->aboutButtonImageHover));

	this->exitButton = new wxBitmapButton(this, 1003, *(exitCast->exitButtonImage), wxPoint(exitCast->x, exitCast->y), wxDefaultSize, wxBORDER_NONE);
	this->exitButton->SetBitmapCurrent(*(exitCast->exitButtonImageHover));

	PlaySound(TEXT("BG-Music2.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	temp = new Flower(10, 500, 3, 2);
	this->flowerContainer.Add(temp);
	temp = new Flower(10, 10, -2, 3);
	this->flowerContainer.Add(temp);
	temp = new Flower(300, 10, 3, 3);
	this->flowerContainer.Add(temp);
	temp = new Flower(300, 500, -3, 2);
	this->flowerContainer.Add(temp);

	timer = new wxTimer(this, TIMER_ID);
	timer->Start(20);
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
	wxMessageBox(wxT("Karamasu The Game"), wxT("About"));
	//this->switchFrame->Close(true);
}

void MainWindow::OnExitClick(wxCommandEvent & event)
{
	/*wxMessageDialog *exitDialog;
	exitDialog = new wxMessageDialog(this, wxT("Are you sure want to exit the game?"), wxT("Karamasu"), wxYES | wxNO);
	if (exitDialog->ShowModal() == wxYES) {
		this->switchFrame->Close(true);
	}
	exitDialog->Show*/
	this->switchFrame->Close(true);
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
}

MainWindow::~MainWindow()
{
	
}
