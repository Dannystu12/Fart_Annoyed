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
	bool DoBallCollision(Ball& ball);
	void DoWallCollision(const Rectf& walls);
	void Update(const Keyboard& kbd, float dt);
	Rectf GetRect() const;
	void ResetCooldown();
private:
	static constexpr Color color = Colors::White;
	static constexpr Color wingColor = Colors::Red;
	static constexpr float wingWidth = 18.0f;
	const float halfWidth;
	const float halfHeight;
	static constexpr float fixedZoneHalfWidth = 15.0f;
	Vec2 pos;
	static constexpr float speed = 300.0f;
	bool cooldown = false;
	static constexpr float exitXFactor = 0.045f;
};