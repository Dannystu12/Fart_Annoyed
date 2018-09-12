#pragma once
#include "Colors.h"
#include "Vec2.h"
#include "Graphics.h"
#include "Ball.h"
#include "Keyboard.h"

class Paddle 
{
public:
	Paddle(const Vec2& pos, float halfWidth, float halfHeight);
	void Draw(Graphics& gfx) const;
	bool DoBallCollision(Ball& ball) const;
	void DoWallCollision(const Rectf& walls);
	void Update(const Keyboard& kbd, float dt);
	Rectf GetRect() const;
private:
	Color color = Colors::White;
	const float halfWidth;
	const float halfHeight;
	Vec2 pos;
	static constexpr float speed = 300.0f;
};