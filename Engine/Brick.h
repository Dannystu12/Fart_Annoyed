#pragma once
#include "Rectf.h"
#include "Colors.h"
#include "Graphics.h"
#include "Ball.h"

class Brick
{
public:
	Brick() = default;
	Brick(const Rectf& rect, Color c);
	void Draw(Graphics& gfx) const;
	bool DoBallCollision(Ball& ball);
private:
	Rectf rect;
	Color c;
	bool isDestroyed = false;
};