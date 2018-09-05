#pragma once
#include "Rectf.h"
#include "Colors.h"
#include "Graphics.h"

class Brick
{
public:
	Brick(const Rectf& rect, Color c);
	void Draw(Graphics& gfx) const;
private:
	Rectf rect;
	Color c;
	bool isDestroyed = false;
};