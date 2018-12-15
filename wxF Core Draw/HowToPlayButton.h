#pragma once
#include "Button.h"
class HowToPlayButton :
	public Button
{
public:
	HowToPlayButton();
	HowToPlayButton(wxWindow *parent);
	~HowToPlayButton();
	virtual void LoadImages();
};

