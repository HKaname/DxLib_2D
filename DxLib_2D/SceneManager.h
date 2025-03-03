#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include "BaseScene.h"

class SceneManager {
private:
	std::unique_ptr<BaseScene> currentScene;

public:
	void ChangeScene(std::unique_ptr<BaseScene> newScene) {
		if (currentScene) {
			currentScene->Uninit();
		}
		currentScene = std::move(newScene);
		currentScene->Init();
	}

	void ChangeSceneByName(const std::string& sceneName);

	void Update() {
		if (currentScene) currentScene->Update();
	}

	void Draw() {
		if (currentScene) currentScene->Draw();
	}
};
