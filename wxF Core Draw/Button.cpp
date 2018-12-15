#include "Button.h"

Button::Button()
{
	
}

Button::Button(wxWindow * window)
{
}


Button::~Button()
{
}

void Button::SetButton(int x, int y, int ID)
{
	this->x = x;
	this->y = y;
	this->button = new wxBitmapButton(this->parent, ID, *(buttonImage), wxPoint(this->x, this->y), wxDefaultSize, wxBORDER_NONE);
	this->button->SetBitmapCurrent(*buttonImageHover);
}
