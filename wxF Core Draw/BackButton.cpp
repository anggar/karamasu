#include "BackButton.h"
#include "wx/stdpaths.h"
#include "wx/filename.h"

BackButton::BackButton(int type)
{
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();

	if (type == 1) {
		fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\Back-Button-Icon-new.png");
		wxImage image(fileLocation, wxBITMAP_TYPE_PNG);

		this->width = image.GetWidth();
		this->height = image.GetHeight();
		this->x = 95;
		this->y = 500;

		this->buttonImage = new wxBitmap(image);

		fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\Back-Button-Icon-new-hover.png");
		wxImage image2(fileLocation, wxBITMAP_TYPE_PNG);

		this->buttonImageHover = new wxBitmap(image2);
	}
	else {
		fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\Back-Button-GamePlay.png");
		wxImage image(fileLocation, wxBITMAP_TYPE_PNG);

		this->width = image.GetWidth();
		this->height = image.GetHeight();
		this->x = 10;
		this->y = 15;

		this->buttonImage = new wxBitmap(image);

		fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\Back-Button-GamePlay-hover.png");
		wxImage image2(fileLocation, wxBITMAP_TYPE_PNG);

		this->buttonImageHover = new wxBitmap(image2);
	}
	
}


BackButton::~BackButton()
{
}

bool BackButton::checkMouse(int x, int y)
{
	return false;
}

void BackButton::DrawButton(wxPaintDC & pdc)
{
}
