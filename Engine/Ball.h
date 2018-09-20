#pragma once
#include "Vec2.h"
#include "Graphics.h"
#include "Rectf.h"
class Ball
{
public:
	Ball(const Vec2& pos, const Vec2& vel);
	void Draw(Graphics& gfx) const;
	void Update(float dt);
	int DoWallCollision(const Rectf& walls);
	void ReboundX();
	void ReboundY();
	Rectf GetRect() const;
	Vec2 GetVelocity() const;
	Vec2 GetPosition() const;
	void SetDirection(const Vec2& dir);
	void Reset();
private:
	Vec2 pos;
	const Vec2 startingPos;
	Vec2 startingVel;
	Vec2 vel;
	static constexpr float radius = 7.0f;
	float speed = 400.0f;
};