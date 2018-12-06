#include "GameWindow.h"
#include "Box.h"
#include "Kanji.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/arrimpl.cpp>
#define TIMER_ID 1945

WX_DECLARE_OBJARRAY(Box, BoxArr);
WX_DECLARE_OBJARRAY(BoxArr, BoxArray);
WX_DEFINE_OBJARRAY(BoxArr);
WX_DEFINE_OBJARRAY(BoxArray);

BEGIN_EVENT_TABLE(GameWindow, wxWindow)
	EVT_PAINT(GameWindow::OnPaint)
	EVT_TIMER(TIMER_ID, GameWindow::OnTimer)
	EVT_MOUSE_EVENTS(GameWindow::OnMouseEvent)
END_EVENT_TABLE()

GameWindow::GameWindow(SwitchFrame *parent)
	: wxWindow(parent, wxID_ANY)
{
	this->SetBackgroundColour(wxColour(*wxLIGHT_GREY));
	
	wxImageHandler *jpegHandler = new wxJPEGHandler();
	wxImage::AddHandler(jpegHandler);

	wxClientDC dc(this);

	this->LoadImageBackground();

	this->boxes = new BoxArray();

	Kanji *teskanji = new Kanji('A', "rain");

	BoxArr temparr;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			temparr.Add(new Box(teskanji, 0, i, j, 0));
		}
		boxes->Add(temparr);
		temparr.Clear();
	}
}

void GameWindow::LoadImageBackground() {
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\BG_YAMA_01.jpg");
	wxImage image(fileLocation, wxBITMAP_TYPE_JPEG);

	this->backgroundImage = new wxBitmap(image);
}

GameWindow::~GameWindow()
{
}
 
void GameWindow::OnTimer(wxTimerEvent &event) {
	static int counter = 0;
	wxMessageOutputDebug().Printf("%d", counter++);

	Refresh();
}

void GameWindow::OnPaint(wxPaintEvent &event) {
	wxPaintDC pdc(this);

	if (backgroundImage != nullptr)
		pdc.DrawBitmap(*backgroundImage, wxPoint(0, 0), true);

	for (int i = 0; i < 6; i++) {
		auto temp = boxes->Item(i);
		for (int j = 0; j < 6; j++) {
			temp.Item(j).Draw(pdc);
		}
	}
}

void GameWindow::OnMouseEvent(wxMouseEvent &event) {
	wxClientDC dc(this);
	int curstate = 0;

	dc.SetBrush(*wxWHITE_BRUSH);

	BoxArray prevBoxes = *(this->boxes);

	int pos_x = (event.GetPosition().x - 10) / 55;
	int pos_y = (event.GetPosition().y - 80) / 55;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			this->boxes->Item(i).Item(j).ChangeState(0);
		}
	}

	if (event.Moving()) {
		curstate = 0;
	}
	else if (event.Dragging() || event.LeftDown()) {
		curstate = 2;
	}

	if ((pos_x < 6 && pos_x >= 0) && (pos_y < 6 && pos_y >= 0)) {
		//dc.DrawRoundedRectangle(wxPoint(10 + 55 * pos_x, 80 + 55 * pos_y), wxSize(50, 50), 5);

		if(curstate !=  2) curstate = 1;
		this->boxes->Item(pos_x).Item(pos_y).ChangeState(curstate);
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (this->boxes->Item(i).Item(j).GetState() != prevBoxes[i][j].GetState()) {
				Refresh();
			}
		}
	}
	/*if (event.Moving()) {
		dc.SetBrush(*wxBLUE_BRUSH);
		dc.FloodFill(event.GetPosition(), *wxWHITE, wxFLOOD_SURFACE);
	}
	else if (event.Dragging() || event.LeftDown()) {
		dc.SetBrush(*wxRED_BRUSH);
		dc.FloodFill(event.GetPosition(), *wxWHITE, wxFLOOD_SURFACE);
	}*/

	/*
	dc.SetPen(wxPen(wxColour(*wxRED)));
	dc.DrawPoint(event.GetPosition());
	dc.SetPen(wxPen(wxNullPen));*/
}
