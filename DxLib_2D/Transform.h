#pragma once
#include "BaseComponent.h"

class Transform : public BaseComponent {
public:
	float x, y;
	float scaleX, scaleY;
	float rotation;

	Transform(Entity* owner, float x = 0, float y = 0)
		: BaseComponent(owner), x(x), y(y), scaleX(1.0f), scaleY(1.0f), rotation(0) {
	}

	void Move(float dx, float dy) {
		x += dx;
		y += dy;
	}
};
