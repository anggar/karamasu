#include "PauseButton.h"
#include "wx/stdpaths.h"
#include "wx/filename.h"

PauseButton::PauseButton()
{
	
}

PauseButton::PauseButton(wxWindow * parent)
{
	this->parent = parent;
	this->LoadImages();
}

PauseButton::~PauseButton()
{
	
}

void PauseButton::LoadImages()
{
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\Pause-Button-GamePlay.png");
	wxImage image(fileLocation, wxBITMAP_TYPE_PNG);

	this->buttonImage = new wxBitmap(image);

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\Pause-Button-GamePlay-hover.png");
	wxImage image2(fileLocation, wxBITMAP_TYPE_PNG);

	this->buttonImageHover = new wxBitmap(image2);
}
