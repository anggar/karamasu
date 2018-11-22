#include "gameWindow.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>


BEGIN_EVENT_TABLE(gameWindow, wxWindow)
	EVT_PAINT(gameWindow::OnPaint)
	EVT_LEFT_DOWN(gameWindow::onMouseLeftDown)
	EVT_LEFT_UP(gameWindow::onMouseLeftUp)
	EVT_MOTION(gameWindow::onMouseMotion)
END_EVENT_TABLE()


gameWindow::gameWindow(gameFrame *parent)
	: wxWindow(parent, wxID_ANY)
{
	this->SetBackgroundColour(wxColour(*wxLIGHT_GREY));
	
	wxImageHandler *jpegHandler = new wxJPEGHandler();
	wxImage::AddHandler(jpegHandler);

	wxClientDC dc(this);

	this->LoadImageBackground();
}

void gameWindow::LoadImageBackground() {
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\BG_YAMA_01.jpg");
	wxImage image(fileLocation, wxBITMAP_TYPE_JPEG);

	this->backgroundImage = new wxBitmap(image);
}

gameWindow::~gameWindow()
{
}
 
void gameWindow::OnPaint(wxPaintEvent &event) {
	wxPaintDC pdc(this);

	if (backgroundImage != nullptr)
		pdc.DrawBitmap(*backgroundImage, wxPoint(0, 0), true);
}

void gameWindow::onMouseLeftDown(wxMouseEvent &event) {
}

void gameWindow::onMouseLeftUp(wxMouseEvent &event) {
}

void gameWindow::onMouseMotion(wxMouseEvent &event) {
	wxClientDC dc(this);
	dc.SetPen(wxPen(wxColour(*wxRED)));
	dc.DrawPoint(event.GetPosition());
	dc.SetPen(wxPen(wxNullPen));
}
