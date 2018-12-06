#pragma once
#include "wx/wx.h"

class Flower
{
public:
	Flower();
	Flower(int x, int y, int xMove, int yMove);
	~Flower();
	void Move(int maxWX, int maxWY);
	void Draw(wxPaintDC &pdc);
	void collide(int xLeft, int yUp, int xRight, int yDown);

private:
	int x, y;
	int xDirection = 1, yDirection = 1;
	int width, height;
	int xAmount, yAmount;
	wxBitmap *flowerImage;
};

