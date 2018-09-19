#pragma once

#include "Rectf.h"
#include "Beveler.h"
#include "Graphics.h"

class Walls
{
public:
	Walls(const Rectf& innerBounds, float thickness, Color baseColor);
	const Rectf& GetInnerBounds() const;
	void Draw(Graphics& gfx) const;
private:
	const Rectf innerBounds;
	const float thickness;
	Beveler beveler;
};