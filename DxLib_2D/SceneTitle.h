#pragma once
#include "BaseScene.h"
#include "DxLib.h"

class TitleScene : public BaseScene {
private:
	int titleImage;  // **画像ハンドル**

public:
	TitleScene(SceneManager* manager) : BaseScene(manager), titleImage(-1) {}

	void Init() override
	{
	}

	void Update() override {
		if (CheckHitKey(KEY_INPUT_RETURN)) {
			sceneManager->ChangeSceneByName("Game");
		}
	}

	void Draw() override {
		DrawString(200, 200, "タイトル", GetColor(255, 255, 255));
		DrawString(200, 250, "Enterキーで開始", GetColor(255, 255, 255));
	}

	void Uninit() override
	{
	}
};
