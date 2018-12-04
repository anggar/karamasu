#include "SwitchFrame.h"
#include "wx/wxprec.h"

#ifndef WX_PRECOMP
	#include "wx/wx.h"
#endif

class MainApp : public wxApp {
public:
	virtual bool OnInit();
};

DECLARE_APP(MainApp)
IMPLEMENT_APP(MainApp)

bool MainApp::OnInit() {
	
	SwitchFrame *frame = new SwitchFrame(wxT("THE GAME"));
	frame->Show(true);
	frame->ShowGameWindow();
	return true;
}

