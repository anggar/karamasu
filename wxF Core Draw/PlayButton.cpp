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
	this->y = 200;

	this->playButtonImage = new wxBitmap(image);
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
	pdc.DrawBitmap(*playButtonImage, wxPoint(this->x, this->y), true);
}
