#pragma once
#include "wx/wx.h"
#include "wx/stdpaths.h"
#include "wx/filename.h"

class Button
{
protected:
	wxBitmap *buttonImage;
	wxBitmap *buttonImageHover;
	wxBitmapButton *button;
	int width, height, x, y;
	wxWindow *parent;
	wxStandardPaths &stdPaths = wxStandardPaths::Get();
	wxString fileLocation = stdPaths.GetExecutablePath();
	virtual void LoadImages() = 0;

public:

	Button();
	Button(wxWindow *window);
	~Button();
	
	void SetButton(int x, int y, int ID);
};

