#pragma once
#include "BaseScene.h"
#include "Player.h"
#include "DxLib.h"

class GameScene : public BaseScene {
private:
	int backgroundImage;  // **背景画像ハンドル**
	std::unique_ptr<Player> player;

public:
	GameScene(SceneManager* manager) : BaseScene(manager), backgroundImage(-1) {}

	void Init() override {
		printf("ゲームシーン開始\n");
		player = std::make_unique<Player>();  // **プレイヤーを生成**
	}

	void Update() override {
		if (CheckHitKey(KEY_INPUT_ESCAPE)) {
			sceneManager->ChangeSceneByName("Title");
		}
		player->Update();
	}

	void Draw() override {
		player->Draw();
		DrawString(200, 250, "Escキーでタイトルへ戻る", GetColor(255, 255, 255));
	}

	void Uninit() override {
		printf("ゲームシーン終了\n");
	}
};
