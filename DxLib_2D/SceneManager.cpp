#include "SceneManager.h"
#include "SceneTitle.h"
#include "SceneGame.h"

void SceneManager::ChangeSceneByName(const std::string& sceneName) {
	if (sceneName == "Title") {
		ChangeScene(std::make_unique<TitleScene>(this));
	}
	else if (sceneName == "Game") {
		ChangeScene(std::make_unique<GameScene>(this));
	}
}
