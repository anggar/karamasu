#include "PauseButton.h"
#include "wx/stdpaths.h"
#include "wx/filename.h"

PauseButton::PauseButton()
{
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\Pause-Button-GamePlay.png");
	wxImage image(fileLocation, wxBITMAP_TYPE_PNG);

	this->width = image.GetWidth();
	this->height = image.GetHeight();
	this->x = 230;
	this->y = 15;

	this->buttonImage = new wxBitmap(image);

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\Pause-Button-GamePlay-hover.png");
	wxImage image2(fileLocation, wxBITMAP_TYPE_PNG);

	this->buttonImageHover = new wxBitmap(image2);
}

PauseButton::~PauseButton()
{
	
}

bool PauseButton::checkMouse(int x, int y)
{
	return false;
}

void PauseButton::DrawButton(wxPaintDC & pdc)
{
}
