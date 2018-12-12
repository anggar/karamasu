#include "HowToPlayButton.h"
#include "wx/stdpaths.h"
#include "wx/filename.h"

bool HowToPlayButton::checkMouse(int x, int y)
{
	return false;
}

void HowToPlayButton::DrawButton(wxPaintDC & pdc)
{
}

HowToPlayButton::HowToPlayButton()
{
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\HowToPlay-Button-Icon-new.png");
	wxImage image(fileLocation, wxBITMAP_TYPE_PNG);

	this->width = image.GetWidth();
	this->height = image.GetHeight();
	this->x = 95;
	this->y = 400;

	this->buttonImage = new wxBitmap(image);

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\HowToPlay-Button-Icon-new-hover.png");
	wxImage image2(fileLocation, wxBITMAP_TYPE_PNG);

	this->buttonImageHover = new wxBitmap(image2);

}


HowToPlayButton::~HowToPlayButton()
{
}
