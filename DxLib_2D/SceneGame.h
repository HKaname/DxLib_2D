#pragma once
#include "BaseScene.h"
#include "Player.h"
#include "DxLib.h"

class GameScene : public BaseScene {
private:
	int backgroundImage;  // **�w�i�摜�n���h��**
	std::unique_ptr<Player> player;

public:
	GameScene(SceneManager* manager) : BaseScene(manager), backgroundImage(-1) {}

	void Init() override {
		printf("�Q�[���V�[���J�n\n");
		player = std::make_unique<Player>();  // **�v���C���[�𐶐�**
	}

	void Update() override {
		if (CheckHitKey(KEY_INPUT_ESCAPE)) {
			sceneManager->ChangeSceneByName("Title");
		}
		player->Update();
	}

	void Draw() override {
		player->Draw();
		DrawString(200, 250, "Esc�L�[�Ń^�C�g���֖߂�", GetColor(255, 255, 255));
	}

	void Uninit() override {
		printf("�Q�[���V�[���I��\n");
	}
};
