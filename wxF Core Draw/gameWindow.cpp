#include "gameWindow.h"

BEGIN_EVENT_TABLE(gameWindow, wxWindow)
	EVT_LEFT_DOWN(gameWindow::onMouseLeftDown)
	EVT_LEFT_UP(gameWindow::onMouseLeftUp)
	EVT_MOTION(gameWindow::onMouseMotion)
END_EVENT_TABLE()


gameWindow::gameWindow(gameFrame *parent)
	: wxWindow(parent, wxID_ANY)
{
	this->SetBackgroundColour(wxColour(*wxLIGHT_GREY));

	wxClientDC dc(this);
}


gameWindow::~gameWindow()
{
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
