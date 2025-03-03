#pragma once

class SceneManager; // 前方宣言

class BaseScene {
protected:
	SceneManager* sceneManager; // シーンマネージャへの参照

public:
	BaseScene(SceneManager* manager) : sceneManager(manager) {}
	virtual ~BaseScene() = default;

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Uninit() = 0;

	SceneManager* GetSceneManager() { return sceneManager; }
};
