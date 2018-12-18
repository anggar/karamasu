#pragma once
#include "wx/wx.h"
#include "wx/dcclient.h"
#include "wx/dcbuffer.h"
#include "wx/listimpl.cpp"
#include "Kanji.h"

WX_DECLARE_LIST(int, BoxList);

class Box
{
public:
	Box(Kanji *kanji, int type, int posx, int posy, int state);
	void Draw(wxPaintDC &dc);
	bool Intersect(int x, int y);

	void Hover();
	void Connect(Box *other);
	void CreateConnection();

	wxPoint GetDistance(Box *other);
	int GetDistanceSum(Box *other);
	int GetState();
	wxPoint GetCanvasPosition();
	wxString GetRadical();
	void ChangeKanji();
	void ChangeState(int state);
	static void PopulateIndex();
	static void ResetBoxState();

	static wxString curRadical;
	static int boxIndex[36];
	static BoxList* boxList;
	static int conn;

	~Box();
private:
	int state;
	wxPoint position;
	Kanji *kkanji;
	int type = 0;
};

