#pragma once
#include "framework.h"

class Drawable
{
public:
	int x, y, w, h;
	int srcx, srcy, hw, hh, sc, cc, ec;
	bool loop;
	int xspeed, yspeed;
	CImage image;
	CString path;

	Drawable(CString path, int x, int y, int w, int h);
	void draw(HDC context);
	void animate();
};