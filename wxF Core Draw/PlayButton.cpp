#include "PlayButton.h"
#include "wx/stdpaths.h"
#include "wx/filename.h"

PlayButton::PlayButton()
{
	
}

PlayButton::PlayButton(wxWindow * parent)
{
	this->parent = parent;
	this->LoadImages();
}

PlayButton::~PlayButton()
{
}


void PlayButton::LoadImages()
{
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\Play-Button-Icon-new.png");
	wxImage image(fileLocation, wxBITMAP_TYPE_PNG);

	this->buttonImage = new wxBitmap(image);

	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\Play-Button-Icon-new-hover.png");
	wxImage image2(fileLocation, wxBITMAP_TYPE_PNG);

	this->buttonImageHover = new wxBitmap(image2);
}
