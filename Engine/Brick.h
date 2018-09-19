#pragma once
#include "Rectf.h"
#include "Colors.h"
#include "Graphics.h"
#include "Ball.h"
#include "Beveler.h"

class Brick
{
public:
	Brick() = default;
	Brick(const Rectf& rect, Color c);
	void Draw(Graphics& gfx) const;
	bool CheckBallCollision(const Ball& ball) const;
	void ExecuteBallCollision(Ball& ball);
	Vec2 GetCenter() const;
private:
	Rectf rect;
	bool isDestroyed = false;
	static constexpr float padding = 0.5f;
	static constexpr float bevelSize = 3.0f;
	Beveler beveler;
};