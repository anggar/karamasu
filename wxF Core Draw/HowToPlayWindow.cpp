#include "HowToPlayWindow.h"
#include "wx/stdpaths.h"
#include "wx/filename.h"

BEGIN_EVENT_TABLE(HowToPlayWindow, wxWindow)
	EVT_PAINT(HowToPlayWindow::OnPaint)
	EVT_BUTTON(1001, HowToPlayWindow::OnBackClick)
END_EVENT_TABLE()

HowToPlayWindow::HowToPlayWindow(SwitchFrame * parent)
	: wxWindow(parent, wxID_ANY), switchFrame(parent)
{
	this->SetBackgroundColour(wxColour(*wxWHITE));

	// -- CREATING IMAGE HANDLER -- //
	wxImageHandler *pngHandler = new wxPNGHandler;
	wxImageHandler *jpgHandler = new wxJPEGHandler;
	wxImage::AddHandler(pngHandler);
	wxImage::AddHandler(jpgHandler);

	// -- LOAD THE LOGO AND THE BACKGROUND -- //
	this->LoadImages();
	this->LoadLogo();

	back = new BackButton();

	this->backButton = new wxBitmapButton(this, 1001, *(back->buttonImage), wxPoint(back->x, back->y), wxDefaultSize, wxBORDER_NONE);
	this->backButton->SetBitmapCurrent(*(back->buttonImageHover));
}

HowToPlayWindow::~HowToPlayWindow()
{
}

void HowToPlayWindow::LoadImages()
{
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\BG_YAMA_03.jpg");
	wxImage image(fileLocation, wxBITMAP_TYPE_JPEG);

	this->backgroundImg = new wxBitmap(image);
	
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\HowToPlaySprites.png");
	wxImage image2(fileLocation, wxBITMAP_TYPE_PNG);

	this->sprites = new wxBitmap(image2);
}

void HowToPlayWindow::OnPaint(wxPaintEvent & event)
{
	wxPaintDC pdc(this);

	if (backgroundImg != nullptr) {
		pdc.DrawBitmap(*backgroundImg, wxPoint(0, 0), true);
	}

	if (sprites != nullptr) {
		pdc.DrawBitmap(*sprites, wxPoint(13, 50), true);
	}
}

void HowToPlayWindow::LoadLogo()
{
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\Logo2.png");
	wxImage image(fileLocation, wxBITMAP_TYPE_PNG);

	this->logoImg = new wxBitmap(image);
}

void HowToPlayWindow::OnBackClick(wxCommandEvent & event)
{
	switchFrame->ShowMainWindow();
}
