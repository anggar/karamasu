#include "ExitButton.h"
#include "wx/stdpaths.h"
#include "wx/filename.h"

ExitButton::ExitButton()
{
	
}

ExitButton::ExitButton(wxWindow * parent)
{
	this->parent = parent;
	this->LoadImages();
}


ExitButton::~ExitButton()
{
	
}

void ExitButton::LoadImages()
{
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\Exit-Button-Icon-new.png");
	wxImage image(fileLocation, wxBITMAP_TYPE_PNG);

	this->buttonImage = new wxBitmap(image);

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\Exit-Button-Icon-new-hover.png");
	wxImage image2(fileLocation, wxBITMAP_TYPE_PNG);

	this->buttonImageHover = new wxBitmap(image2);
}
