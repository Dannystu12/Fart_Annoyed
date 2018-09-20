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
	void Reset();
private:
	static constexpr Color wingColor = { 210, 255, 210 };
	static constexpr Color color = {200, 220, 200};
	static constexpr float wingWidth = 6.0f;
	static constexpr float speed = 360.0f;


	static constexpr float maximumExitRatio = 2.6f;
	static constexpr float fixedZoneWidthRatio = 0.2f;

	const float halfWidth;
	const float halfHeight;

	const float exitXFactor;
	const float fixedZoneHalfWidth;
	const float fixedZoneExitX;

	Vec2 pos;
	const Vec2 startingPos;
	bool cooldown = false;
};