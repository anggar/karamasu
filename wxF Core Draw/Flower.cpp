#include "Flower.h"
#include "wx/stdpaths.h"
#include "wx/filename.h"

Flower::Flower()
{
	 
}

Flower::Flower(int x, int y, int xMove, int yMove)
{
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\Flower1.png");
	wxImage image(fileLocation, wxBITMAP_TYPE_PNG);
	
	this->x = x;
	this->y = y;
	this->width = image.GetWidth();
	this->height = image.GetHeight();
	this->xAmount = xMove;
	this->yAmount = yMove;
	this->flowerImage = new wxBitmap(image);
	
}


Flower::~Flower()
{

}

void Flower::Move(int maxWX, int maxWY)
{
	if (x + width >= maxWX || x <= 0) {
		xDirection *= -1;
	}
	this->x += xDirection * xAmount;
	if (y + height >= maxWY || y <= 0) {
		yDirection *= -1;
	}
	this->y += yDirection * yAmount;
}

void Flower::Draw(wxPaintDC & pdc)
{
	pdc.DrawBitmap(*flowerImage, wxPoint(this->x, this->y), true);
}

void Flower::collide(int xLeft, int yUp, int xRight, int yDown)
{
	
}
