#include "ExitButton.h"
#include "wx/stdpaths.h"
#include "wx/filename.h"

ExitButton::ExitButton()
{
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\Exit-Button-Icon-new.png");
	wxImage image(fileLocation, wxBITMAP_TYPE_PNG);

	this->width = image.GetWidth();
	this->height = image.GetHeight();
	this->x = 95;
	this->y = 460;

	this->exitButtonImage = new wxBitmap(image);

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\Exit-Button-Icon-new-hover.png");
	wxImage image2(fileLocation, wxBITMAP_TYPE_PNG);

	this->exitButtonImageHover = new wxBitmap(image2);
}


ExitButton::~ExitButton()
{
	
}

bool ExitButton::checkMouse(int x, int y)
{
	return false;
}

void ExitButton::DrawButton(wxPaintDC & pdc)
{
}

void ExitButton::DrawButtonHover(wxPaintDC & pdc)
{
}
