#include "Box.h"

Box::Box(Kanji kanji, int type)
	: kanji(kanji), type(type)
{
}

void Box::Draw(wxPaintDC &dc) {
	dc.SetBrush(*wxBLUE_BRUSH);
	dc.SetPen(*wxBLACK_PEN);

	dc.DrawRoundedRectangle(wxPoint(10 + 55 * position.x, 80 + 55 * position.y), wxSize(50, 50), 5);

	dc.DrawText(this->kanji.GetChar(), wxPoint(10 + 55 * position.x, 80 + 55 * position.y));
}

Box::~Box()
{
}
