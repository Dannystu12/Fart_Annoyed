#include "Walls.h"
#include <assert.h>

Walls::Walls(const Rectf& innerBounds, float thickness, Color baseColor)
	:
	innerBounds(innerBounds),
	thickness(thickness),
	beveler(baseColor)
{
	assert(innerBounds.GetExpanded(thickness).IsContainedBy(Graphics::GetScreenRect()));
}

const Rectf& Walls::GetInnerBounds() const
{
	return innerBounds;
}

void Walls::Draw(Graphics& gfx) const
{
	beveler.DrawBevelFrame(innerBounds.GetExpanded(thickness), int(thickness / 2), gfx);
}
