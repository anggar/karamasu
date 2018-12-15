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
	back = new BackButton(2);
	backButton = new wxBitmapButton(this, 1001, *(back->buttonImage), wxPoint(back->x, back->y), wxDefaultSize, wxBORDER_NONE);
	backButton->SetBitmapCurrent(*(back->buttonImageHover));

	pause = new PauseButton();
	pauseButton = new wxBitmapButton(this, 1002, *(pause->buttonImage), wxPoint(pause->x, pause->y), wxDefaultSize, wxBORDER_NONE);
	pauseButton->SetBitmapCurrent(*(pause->buttonImageHover));

	wxClientDC dc(this);

	Kanji::SetRandomRadical();
	
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
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	fileLocation = wxFileName(fileLocation).GetPath() + wxT("\\..\\Asset\\BG_YAMA_01.jpg");
	wxImage image(fileLocation, wxBITMAP_TYPE_JPEG);

	this->backgroundImage = new wxBitmap(image);
}

void GameWindow::UpdateScore(int num)
{
	if (num > 9999) UpdateScore(9999);
	if (0 <= num && num < 10) {
		scoreArr[0] = scoreArr[1] = scoreArr[2] = '0';
		scoreArr[3] = char((num % 10) + 48);
		return;
	}
	if (10 <= num && num < 100) {
		scoreArr[0] = scoreArr[1] = '0';
		scoreArr[3] = char((num % 10) + 48);
		num /= 10;
		scoreArr[2] = char((num % 10) + 48);
		return;
	}
	if (100 <= num && num < 1000) {
		scoreArr[0] = '0';
		scoreArr[3] = char((num % 10) + 48);
		num /= 10;
		scoreArr[2] = char((num % 10) + 48);
		num /= 10;
		scoreArr[1] = char((num % 10) + 48);
		num /= 10;
		return;
	}
	if (1000 <= num && num < 10000) {
		scoreArr[3] = char((num % 10) + 48);
		num /= 10;
		scoreArr[2] = char((num % 10) + 48);
		num /= 10;
		scoreArr[1] = char((num % 10) + 48);
		num /= 10;
		scoreArr[0] = char((num % 10) + 48);
		num /= 10;
		return;
	}
}

GameWindow::~GameWindow()
{
}
 
void GameWindow::OnTimer(wxTimerEvent &event) {
		
	wxClientDC dc(this);

	dc.SetPen(*wxBLACK_PEN);
	dc.SetBrush(*wxWHITE_BRUSH);
	dc.DrawRoundedRectangle(wxPoint(10 + 110, 15), wxSize(105, 60), 5);
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
	pdc.SetPen(*wxBLACK_PEN);
	pdc.SetFont(wxFont(24, wxFONTFAMILY_DEFAULT, wxNORMAL, wxNORMAL, false, wxT("MS Gothic")));

	pdc.SetBrush(*wxWHITE_BRUSH);
	for (int i = 0; i < 3; i++) {
		pdc.DrawRoundedRectangle(wxPoint(10+110*i, 420), wxSize(105, 60), 5);
	}

	pdc.SetBrush(wxBrush(wxColour(0xAE, 0xE2, 0x83, 50), wxBRUSHSTYLE_CROSSDIAG_HATCH));
	for (int i = 0; i < 3; i++) {
		pdc.DrawRoundedRectangle(wxPoint(10+110*i, 420), wxSize(105, 60), 5);
		pdc.DrawText(Kanji::radicalSelection->at(i), wxPoint(48+110*i, 432));
	}
	
	// -- DRAWING THE SCORE -- //
	pdc.SetBrush(*wxWHITE_BRUSH);
	pdc.SetFont(wxFont(15, wxFONTFAMILY_DEFAULT, wxNORMAL, wxNORMAL, false, wxT("Road Rage")));
	pdc.DrawRoundedRectangle(wxPoint(10, 500),wxSize(325, 80),5);
	pdc.DrawText(wxT("SCORE"), wxPoint(140, 505));
	
	wxString n = "";
	n += char(scoreArr[0]);
	n += char(scoreArr[1]);
	n += char(scoreArr[2]);
	n += char(scoreArr[3]);
	pdc.SetFont(wxFont(17, wxFONTFAMILY_DEFAULT, wxNORMAL, wxBOLD, false, wxT("Impact")));
	pdc.DrawText(n, wxPoint(145, 535));
}

void GameWindow::OnBackClick(wxCommandEvent & event)
{
	this->timer->Stop();
	this->TIME_LIMIT = 300;
	this->switchFrame->ShowMainWindow();
}

void GameWindow::OnPauseClick(wxCommandEvent & event)
{
}

void GameWindow::StartTimer()
{
	this->timer->Start(1000);
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
		if(curstate !=  2) curstate = 1;
		this->boxes->Item(pos_x).Item(pos_y).ChangeState(curstate);
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (this->boxes->Item(i).Item(j).GetState() != prevBoxes[i][j].GetState()) {
				RefreshRect(wxRect(wxPoint(10 + 55*i, 80 + 55*j), wxSize(50, 50)), false);
			}
		}
	}
}
