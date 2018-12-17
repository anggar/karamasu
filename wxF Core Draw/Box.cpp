#include "Box.h"

WX_DEFINE_LIST(BoxList);

wxString Box::curRadical = wxT("");
BoxList* Box::boxList = new BoxList();
int Box::boxIndex[36] = { 0 };
int Box::conn = 0;

Box::Box(Kanji *kanji, int type, int posx, int posy, int state)
	: kkanji(kanji), type(type), position(wxPoint(posx, posy)), state(state)
{
}

void Box::ChangeState(int state) {	
	this->state = state;
}

int Box::GetState() {
	return this->state;
}

wxPoint Box::GetCanvasPosition()
{
	return wxPoint(10 + 55*this->position.x, 90 + 55*this->position.y);
}

wxString Box::GetRadical()
{
	return this->kkanji->GetRadical();
}

void Box::PopulateIndex()
{
	for (int i = 0; i < 36; i++) {
		boxIndex[i] = i;
	}
}

void Box::ResetBoxState()
{
	conn = 0;
	curRadical = wxT("");
	boxList->Clear();
}

void Box::Draw(wxPaintDC &dc) {
	switch (this->state) {
	case 0:
		dc.SetBrush(*wxWHITE_BRUSH);
		break;
	case 1:
		dc.SetBrush(wxBrush(wxColour(0xFF, 0xDA, 0x95), wxBRUSHSTYLE_SOLID));
		break;
	case 2:
		dc.SetBrush(wxBrush(wxColour(0xFF, 0x7C, 0x7C), wxBRUSHSTYLE_SOLID));
		break;
	}

	dc.SetPen(wxPen(wxColour(*wxBLACK), 3, wxPENSTYLE_SOLID));
	dc.DrawRectangle(wxPoint(10 + 55 * position.x, 90 + 55 * position.y), wxSize(50, 50));

	dc.SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxNORMAL, wxNORMAL, false, wxT("MS Gothic"), wxFONTENCODING_UTF8));

	dc.DrawText(this->kkanji->GetChar(), wxPoint(10 + 55 * position.x + 10, 90 + 55 * position.y + 10));
}

// Convention, other for before
void Box::Connect(Box *other)
{
	if (other->kkanji->GetRadical() == this->curRadical &&
		this->GetDistanceSum(other) == 1) {
		boxList->Append(&boxIndex[this->position.x*6 + this->position.y]);
		this->ChangeState(2);
		conn++;
	}
}

bool Box::Intersect(int x, int y)
{
	if (this->GetCanvasPosition().x < x && this->GetCanvasPosition().x + 50 > x &&
		this->GetCanvasPosition().y < y && this->GetCanvasPosition().y + 50 > y) {
		wxMessageOutputDebug().Printf("Mouse in a Box %s %s", this->position.x, this->position.y);
		return true;
	}

	return false;
}

void Box::Hover()
{
	this->ChangeState(1);
}

void Box::CreateConnection()
{
	this->curRadical = this->kkanji->GetRadical();
	this->ChangeState(2);
	boxList->Append(&boxIndex[position.x * 6 + position.y]);
}

wxPoint Box::GetDistance(Box *other)
{
	return wxPoint(this->position.x - other->position.x, 
				this->position.y - other->position.y);
}

int Box::GetDistanceSum(Box * other)
{
	wxPoint temp = this->GetDistance(other);
	return abs(temp.x) + abs(temp.y);
}

Box::~Box()
{
}
