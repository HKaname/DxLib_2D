#pragma once
#include "BaseComponent.h"

class Transform : public BaseComponent {
public:
	float x, y;

	Transform(Entity* owner, float x = 0, float y = 0)
		: BaseComponent(owner), x(x), y(y) {
	}

	void Move(float dx, float dy) {
		x += dx;
		y += dy;
	}
};
