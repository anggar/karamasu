#pragma once
#include "Button.h"

class PauseButton :
	public Button
{
public:
	PauseButton();
	PauseButton(wxWindow *parent);
	~PauseButton();
	virtual void LoadImages();
};

