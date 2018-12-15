#pragma once
#include "Button.h"

class ExitButton :
	public Button
{
public:
	
	ExitButton();
	ExitButton(wxWindow *parent);
	~ExitButton();
	virtual void LoadImages();
};

