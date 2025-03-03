#pragma once
#include "Entity.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "PlayerController.h"

class Player : public Entity {
public:
	Player() {
		auto transform = AddComponent<Transform>(300, 200);
		AddComponent<SpriteRenderer>(transform, "Assets/Texture/Player.png");
		AddComponent<PlayerController>(transform);
	}
};
