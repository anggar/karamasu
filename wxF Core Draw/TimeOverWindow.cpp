#include "TimeOverWindow.h"
#include "wx/stdpaths.h"
#include "wx/filename.h"

BEGIN_EVENT_TABLE(TimeOverWindow, wxWindow)
	EVT_PAINT(TimeOverWindow::OnPaint)
	EVT_BUTTON(1001, TimeOverWindow::OnBackClick)
END_EVENT_TABLE()

TimeOverWindow::TimeOverWindow(SwitchFrame *parent)
	: wxWindow(parent, wxID_ANY), switchFrame(parent)
{
	this->SetBackgroundColour(wxColour(*wxWHITE));

	// -- CREATING IMAGE HANDLER -- //
	wxImageHandler *pngHandler = new wxPNGHandler;
	wxImageHandler *jpgHandler = new wxJPEGHandler;
	wxImage::AddHandler(pngHandler);
	wxImage::AddHandler(jpgHandler);

	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\TimeOverSprites.png");
	wxImage image(fileLocation, wxBITMAP_TYPE_PNG);

	this->bg = new wxBitmap(image);

	back = new BackButton(this, 1);
	back->SetButton(95, 500, 1001);
}


TimeOverWindow::~TimeOverWindow()
{
}

void TimeOverWindow::OnBackClick(wxCommandEvent & event)
{
	this->switchFrame->ShowMainWindow();
}

void TimeOverWindow::OnPaint(wxPaintEvent & event)
{
	wxPaintDC pdc(this);

	pdc.DrawBitmap(*bg, wxPoint(0, 0), true);
	pdc.SetFont(wxFont(23, wxFONTFAMILY_DEFAULT, wxNORMAL, wxBOLD, false, wxT("Impact")));
	pdc.DrawText(wxString::Format(wxT("%04d"), this->score), wxPoint(145, 300));
}

void TimeOverWindow::SetScore(int num)
{
	this->score = num;
}
