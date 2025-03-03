#pragma once
#include "BaseComponent.h"
#include "Transform.h"
#include "DxLib.h"

class PlayerController : public BaseComponent {
private:
	Transform* transform;
	float speed;

public:
	PlayerController(Entity* owner, Transform* transform, float speed = 5.0f)
		: BaseComponent(owner), transform(transform), speed(speed)
	{
	}

	void Update() override {
		if (CheckHitKey(KEY_INPUT_LEFT))  transform->Move(-speed, 0);
		if (CheckHitKey(KEY_INPUT_RIGHT)) transform->Move(speed, 0);
		if (CheckHitKey(KEY_INPUT_UP))    transform->Move(0, -speed);
		if (CheckHitKey(KEY_INPUT_DOWN))  transform->Move(0, speed);
	}
};
