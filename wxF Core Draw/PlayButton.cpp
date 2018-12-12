#include "PlayButton.h"
#include "wx/stdpaths.h"
#include "wx/filename.h"

PlayButton::PlayButton()
{
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\Play-Button-Icon-new.png");
	wxImage image(fileLocation, wxBITMAP_TYPE_PNG);

	this->width = image.GetWidth();
	this->height = image.GetHeight();
	this->x = 95;
	this->y = 190;

	this->buttonImage = new wxBitmap(image);

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\Play-Button-Icon-new-hover.png");
	wxImage image2(fileLocation, wxBITMAP_TYPE_PNG);

	this->buttonImageHover = new wxBitmap(image2);
}

PlayButton::~PlayButton()
{
}

bool PlayButton::checkMouse(int x, int y)
{
	if (this->x <= x && x <= this->x + this->width) {
		if (this->y <= y && y <= this->y + this->height) {
			return true;
		}
	}
	return false;
}

void PlayButton::DrawButton(wxPaintDC & pdc)
{
	pdc.DrawBitmap(*(buttonImage), wxPoint(this->x, this->y), true);
}
