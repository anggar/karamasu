#include "GameWindow.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>

BEGIN_EVENT_TABLE(GameWindow, wxWindow)
	EVT_PAINT(GameWindow::OnPaint)
	EVT_MOUSE_EVENTS(GameWindow::onMouseEvent)
END_EVENT_TABLE()

GameWindow::GameWindow(SwitchFrame *parent)
	: wxWindow(parent, wxID_ANY)
{
	this->SetBackgroundColour(wxColour(*wxLIGHT_GREY));
	
	wxImageHandler *jpegHandler = new wxJPEGHandler();
	wxImage::AddHandler(jpegHandler);

	wxClientDC dc(this);

	this->LoadImageBackground();
}

void GameWindow::LoadImageBackground() {
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\BG_YAMA_01.jpg");
	wxImage image(fileLocation, wxBITMAP_TYPE_JPEG);

	this->backgroundImage = new wxBitmap(image);
}

GameWindow::~GameWindow()
{
}
 
void GameWindow::OnPaint(wxPaintEvent &event) {
	wxPaintDC pdc(this);

	if (backgroundImage != nullptr)
		pdc.DrawBitmap(*backgroundImage, wxPoint(0, 0), true);

}

void GameWindow::onMouseEvent(wxMouseEvent &event) {
	wxClientDC dc(this);
	dc.SetBrush(*wxWHITE_BRUSH);

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			dc.DrawRoundedRectangle(wxPoint(10 + 55 * i, 80 + 55*j), wxSize(50, 50), 5);
		}
	}	
	/*int pos_x = (event.GetPosition().x - 10) / 55;
	int pos_y = (event.GetPosition().y - 80) / 55;

	if ((pos_x < 6 && pos_x >= 0) && (pos_y < 6 && pos_y >= 0)) {
		dc.SetBrush(*wxBLUE_BRUSH);
		dc.DrawRoundedRectangle(wxPoint(10 + 55 * pos_x, 80 + 55 * pos_y), wxSize(50, 50), 5);
	}*/

	if (event.Moving()) {
		dc.SetBrush(*wxBLUE_BRUSH);
		dc.FloodFill(event.GetPosition(), *wxWHITE, wxFLOOD_SURFACE);
	}
	else if (event.Dragging() || event.LeftDown()) {
		dc.SetBrush(*wxRED_BRUSH);
		dc.FloodFill(event.GetPosition(), *wxWHITE, wxFLOOD_SURFACE);
	}

	/*
	dc.SetPen(wxPen(wxColour(*wxRED)));
	dc.DrawPoint(event.GetPosition());
	dc.SetPen(wxPen(wxNullPen));*/
}
