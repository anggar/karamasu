#pragma once
#include "Button.h"

class BackButton :
	public Button
{
private:
	int type;

public:
	BackButton();
	BackButton(wxWindow *parent, int type);
	~BackButton();
	virtual void LoadImages();
};

