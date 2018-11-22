#include "wx/wx.h"
#include "gameFrame.h"

class MainApp : public wxApp {
public:
	virtual bool OnInit();
};

DECLARE_APP(MainApp)
IMPLEMENT_APP(MainApp)

bool MainApp::OnInit() {
	gameFrame *frame = new gameFrame(wxT("THE GAME"));
	frame->Show(true);
	return true;
}

