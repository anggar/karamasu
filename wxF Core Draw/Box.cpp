#include "Box.h"

Box::Box(Kanji *kanji, int type, int posx, int posy, int state)
	: kkanji(kanji), type(type), position(wxPoint(posx, posy)), state(state)
{
}

void Box::ChangeState(int state) {
	this->state = state;
}

int Box::GetState() {
	return state;
}

void Box::Draw(wxPaintDC &dc) {
	switch (this->state) {
	case 0:
		dc.SetBrush(*wxWHITE_BRUSH);
		break;
	case 1:
		dc.SetBrush(*wxBLUE_BRUSH);
		break;
	case 2:
		dc.SetBrush(*wxRED_BRUSH);
		break;
	}

	dc.SetPen(*wxBLACK_PEN);

	dc.DrawRoundedRectangle(wxPoint(10 + 55 * position.x, 80 + 55 * position.y), wxSize(50, 50), 5);

	dc.SetFont(wxFont(20, wxFONTFAMILY_SWISS, wxNORMAL, wxBOLD, false, wxT("Calibri"), wxFONTENCODING_UTF8));

	dc.DrawText(this->kkanji->GetChar(), wxPoint(10 + 55 * position.x, 80 + 55 * position.y));
}

Box::~Box()
{
}
