#include "GameWindow.h"
#include "Box.h"
#include "Kanji.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include <wx/arrimpl.cpp>
#include <vector>
#include "sqlite3.h"
#include "wx/dcbuffer.h"
#define TIMER_ID 1945

WX_DECLARE_OBJARRAY(Box, BoxArr);
WX_DECLARE_OBJARRAY(BoxArr, BoxArray);
WX_DEFINE_OBJARRAY(BoxArr);
WX_DEFINE_OBJARRAY(BoxArray);

WX_DECLARE_OBJARRAY(Kanji, RadicalArray);

BEGIN_EVENT_TABLE(GameWindow, wxWindow)
	EVT_PAINT(GameWindow::OnPaint)
	EVT_TIMER(TIMER_ID, GameWindow::OnTimer)
	EVT_MOUSE_EVENTS(GameWindow::OnMouseEvent)
	EVT_BUTTON(1001, GameWindow::OnBackClick)
	EVT_BUTTON(1002, GameWindow::OnPauseClick)
END_EVENT_TABLE()

GameWindow::GameWindow(SwitchFrame *parent)
	: wxWindow(parent, wxID_ANY), switchFrame(parent)
{
	this->SetBackgroundColour(wxColour(*wxLIGHT_GREY));
	
	// -- CREATING HANDLER -- //
	wxImageHandler *pngHandler = new wxPNGHandler;
	wxImageHandler *jpgHandler = new wxJPEGHandler;
	wxImage::AddHandler(pngHandler);
	wxImage::AddHandler(jpgHandler);

	// -- Back Button -- //
	back = new BackButton(this, 2);
	back->SetButton(10, 15, 1001);

	pause = new PauseButton(this);
	pause->SetButton(230, 15, 1002);

	wxClientDC dc(this);

	Kanji::SetRandomRadical();
	Box::PopulateIndex();
	
	this->LoadImageBackground();
	
	timer = new wxTimer(this, TIMER_ID);

	this->boxes = new BoxArray();

	BoxArr temparr;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			temparr.Add(new Box(new Kanji(), 0, i, j, 0));
		}
		boxes->Add(temparr);
		temparr.Clear();
	}
	
}

void GameWindow::LoadImageBackground() {
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\BG_GRAD_02.jpg");
	wxImage image(fileLocation, wxBITMAP_TYPE_JPEG);

	this->backgroundImage = new wxBitmap(image);
	
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\TimerBox.png");
	wxImage timerBG(fileLocation, wxBITMAP_TYPE_PNG);

	this->timerBackground = new wxBitmap(timerBG); 
}

void GameWindow::UpdateScore(int num)
{
	if (this->score + num > 9999) {
		this->score = 9999;
	}
	else {
		this->score += num;
	}
}

GameWindow::~GameWindow()
{
}
 
void GameWindow::OnTimer(wxTimerEvent &event) {
		
	wxClientDC dc(this);

	if (TIME_LIMIT <= 0) {
		this->switchFrame->ShowTimeOver(this->score);
	}

	dc.SetPen(*wxBLACK_PEN);
	dc.DrawBitmap(*timerBackground, wxPoint(10 + 110, 15), true);
	dc.SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxNORMAL, wxNORMAL, false, wxT("Impact")));
	dc.DrawText(wxString::Format(wxT("%02d : %02d"), (TIME_LIMIT)/60, (TIME_LIMIT)%60), wxPoint(137, 28));
	TIME_LIMIT--;
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

	// DRAWING THE RADICAL HELPER
	pdc.SetPen(wxPen(wxColour(*wxBLACK), 3, wxPENSTYLE_SOLID));
	pdc.SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxNORMAL, wxNORMAL, false, wxT("MS Gothic")));

	pdc.SetBrush(*wxWHITE_BRUSH);
	for (int i = 0; i < 3; i++) {
		pdc.DrawRectangle(wxPoint(10+110*i, 420), wxSize(105, 60));
	}

	pdc.SetBrush(wxBrush(wxColour(0xAE, 0xE2, 0x83, 50), wxBRUSHSTYLE_CROSSDIAG_HATCH));
	for (int i = 0; i < 3; i++) {
		pdc.DrawRectangle(wxPoint(10+110*i, 420), wxSize(105, 60));
		pdc.DrawText(Kanji::radicalSelection->at(i), wxPoint(48+110*i, 432));
	}
	
	// -- DRAWING THE SCORE -- //
	pdc.SetPen(*wxBLACK_PEN);
	pdc.SetBrush(*wxWHITE_BRUSH);
	pdc.SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxNORMAL, wxNORMAL, false, wxT("Road Rage")));
	pdc.DrawRoundedRectangle(wxPoint(10, 500),wxSize(325, 90),5);
	pdc.DrawText("SCORE", wxPoint(140, 505));
	
	pdc.SetFont(wxFont(17, wxFONTFAMILY_DEFAULT, wxNORMAL, wxBOLD, false, wxT("Impact")));
	pdc.DrawText(wxString::Format(wxT("%04d"), this->score), wxPoint(145, 535));
}

void GameWindow::OnBackClick(wxCommandEvent & event)
{
	this->timer->Stop();
	this->TIME_LIMIT = 300;
	this->switchFrame->ShowMainWindow();
}

void GameWindow::OnPauseClick(wxCommandEvent & event)
{
	wxClientDC dc(this);
	dc.SetBrush(wxBrush(wxColour(0xFF, 0x7C, 0x7C),wxBRUSHSTYLE_SOLID));
	
	this->pauseState ^= 1;

	switch (this->pauseState) {
	case 0:
		timer->Start(1000);
		Refresh();
		break;
	case 1:
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				dc.DrawRectangle(wxPoint(10 + 55 * i, 90 + 55 * j), wxSize(50, 50));
			}
		}
		timer->Stop();
		break;
	}
}

void GameWindow::ResetGameState()
{
	Kanji::SetRandomRadical();
	for(int i=0; i<6; i++){
		for (int j = 0; j < 6; j++) {
			this->boxes->Item(i).Item(j).ChangeKanji();
		}
	}

	this->score = 0;
	this->TIME_LIMIT = 300;
	this->timer->Start(1000);
}

void GameWindow::OnMouseEvent(wxMouseEvent &event) {
	wxClientDC dc(this);
	int curstate = 0;

	if (pauseState == 1)
		return;

	BoxArray prevBoxes = *(this->boxes);

	int pos_x = (event.GetX() - 10) / 55;
	int pos_y = (event.GetY() - 90) / 55;

	if (event.Dragging() || event.LeftDown()) {
		curstate = 2;
	}
	else if(event.LeftUp()) {
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				if (Box::conn >= 3 && this->boxes->Item(i).Item(j).GetState() == 2) {
					UpdateScore(5);
					this->boxes->Item(i).Item(j).ChangeKanji();
					Refresh();
				} 
				this->boxes->Item(i).Item(j).ChangeState(0);
			}
		}

		Box::ResetBoxState();
	}

	if ((pos_x < 6 && pos_x >= 0) && (pos_y < 6 && pos_y >= 0)) {
		if (event.GetY() < 90) curstate = 0;

		// Hover
		if (curstate != 2) {
			this->boxes->Item(pos_x).Item(pos_y).Hover();
		}
		else if (curstate != prevBoxes[pos_x][pos_y].GetState()) { // curstate expected to be 2
			auto *boxxi = Box::boxList->GetLast();

			int boxxx = -1, boxxy = -1;
			if (boxxi) {
				boxxx = *boxxi->GetData() / 6;
				boxxy = *boxxi->GetData() % 6;
			}

			if (Box::curRadical == wxT("")) {
				this->boxes->Item(pos_x).Item(pos_y).CreateConnection();
			}

			if (boxxx != -1 && boxxy != -1 && 
				this->boxes->Item(pos_x).Item(pos_y).GetDistanceSum(
				&(this->boxes->Item(boxxx).Item(boxxy))) == 1 && 
				Box::curRadical == this->boxes->Item(pos_x).Item(pos_y).GetRadical()) {
				this->boxes->Item(pos_x).Item(pos_y).ChangeState(2);
				this->boxes->Item(pos_x).Item(pos_y).Connect(
					&(this->boxes->Item(boxxx).Item(boxxy)));
			}
		}
	}

	// Refresh for changed states
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (((pos_x != i) || (pos_y != j)) && this->boxes->Item(i).Item(j).GetState() == 1)
				this->boxes->Item(i).Item(j).ChangeState(0);

			if (this->boxes->Item(i).Item(j).GetState() != prevBoxes[i][j].GetState()) {
				RefreshRect(wxRect(wxPoint(10 + 55 * i, 90 + 55 * j), wxSize(50, 50)), false);
			}
		}
	}
}