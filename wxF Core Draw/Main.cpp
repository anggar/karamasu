#include "wx/wx.h"
#include "gameFrame.h"
#include "MainFrame.h"

class MainApp : public wxApp {
public:
	virtual bool OnInit();
};

DECLARE_APP(MainApp)
IMPLEMENT_APP(MainApp)

bool MainApp::OnInit() {
	
	//gameFrame *frame = new gameFrame(wxT("THE GAME"));
	MainFrame *frame = new MainFrame(wxT("THE GAME"));
	frame->Show(true);
	return true;
}

