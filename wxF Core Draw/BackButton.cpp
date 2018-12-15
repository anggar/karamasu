#include "BackButton.h"
#include "wx/stdpaths.h"
#include "wx/filename.h"

BackButton::BackButton()
{
}

BackButton::BackButton(wxWindow * parent, int type)
{
	this->parent = parent;
	this->type = type;
	this->LoadImages();
}

BackButton::~BackButton()
{
}

void BackButton::LoadImages()
{
	if (type == 1) {
		fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\Back-Button-Icon-new.png");
		wxImage image(fileLocation, wxBITMAP_TYPE_PNG);

		this->buttonImage = new wxBitmap(image);

		fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\Back-Button-Icon-new-hover.png");
		wxImage image2(fileLocation, wxBITMAP_TYPE_PNG);

		this->buttonImageHover = new wxBitmap(image2);
	}
	else {
		fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\Back-Button-GamePlay.png");
		wxImage image(fileLocation, wxBITMAP_TYPE_PNG);

		this->buttonImage = new wxBitmap(image);

		fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\Back-Button-GamePlay-hover.png");
		wxImage image2(fileLocation, wxBITMAP_TYPE_PNG);

		this->buttonImageHover = new wxBitmap(image2);
	}
}
