#pragma once
#include "Button.h"
class AboutButton :
	public Button
{

public:
	AboutButton();
	AboutButton(wxWindow *parent);
	~AboutButton();
	virtual void LoadImages();
};

