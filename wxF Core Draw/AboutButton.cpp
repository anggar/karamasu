#include "AboutButton.h"
#include "wx/stdpaths.h"
#include "wx/filename.h"

AboutButton::AboutButton()
{
	
}

AboutButton::AboutButton(wxWindow * parent)
{
	this->parent = parent;
	this->LoadImages();
}


AboutButton::~AboutButton()
{
}

void AboutButton::LoadImages()
{
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\About-Button-Icon-new.png");
	wxImage image(fileLocation, wxBITMAP_TYPE_PNG);

	this->buttonImage = new wxBitmap(image);

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\About-Button-Icon-new-hover.png");
	wxImage image2(fileLocation, wxBITMAP_TYPE_PNG);

	this->buttonImageHover = new wxBitmap(image2);
}
