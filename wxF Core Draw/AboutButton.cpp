#include "AboutButton.h"
#include "wx/stdpaths.h"
#include "wx/filename.h"

AboutButton::AboutButton()
{
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\About-Button-Icon-new.png");
	wxImage image(fileLocation, wxBITMAP_TYPE_PNG);

	this->width = image.GetWidth();
	this->height = image.GetHeight();
	this->x = 95;
	this->y = 410;

	this->aboutButtonImage = new wxBitmap(image);

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\About-Button-Icon-new-hover.png");
	wxImage image2(fileLocation, wxBITMAP_TYPE_PNG);

	this->aboutButtonImageHover = new wxBitmap(image2);
}


AboutButton::~AboutButton()
{
}

bool AboutButton::checkMouse(int x, int y)
{
	if (this->x <= x && x <= this->x + this->width) {
		if (this->y <= y && y <= this->y + this->height) {
			return true;
		}
	}
	return false;
}

void AboutButton::DrawButton(wxPaintDC & pdc)
{
	pdc.DrawBitmap(*aboutButtonImage, wxPoint(this->x, this->y), true);
}

void AboutButton::DrawButtonHover(wxPaintDC & pdc)
{
}
