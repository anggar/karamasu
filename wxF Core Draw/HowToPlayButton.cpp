#include "HowToPlayButton.h"
#include "wx/stdpaths.h"
#include "wx/filename.h"

void HowToPlayButton::LoadImages()
{
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\HowToPlay-Button-Icon-new.png");
	wxImage image(fileLocation, wxBITMAP_TYPE_PNG);

	this->buttonImage = new wxBitmap(image);

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\HowToPlay-Button-Icon-new-hover.png");
	wxImage image2(fileLocation, wxBITMAP_TYPE_PNG);

	this->buttonImageHover = new wxBitmap(image2);
}

HowToPlayButton::HowToPlayButton()
{

}

HowToPlayButton::HowToPlayButton(wxWindow * parent)
{
	this->parent = parent;
	this->LoadImages();
}


HowToPlayButton::~HowToPlayButton()
{
}
