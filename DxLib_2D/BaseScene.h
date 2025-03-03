#pragma once

class SceneManager; // �O���錾

class BaseScene {
protected:
	SceneManager* sceneManager; // �V�[���}�l�[�W���ւ̎Q��

public:
	BaseScene(SceneManager* manager) : sceneManager(manager) {}
	virtual ~BaseScene() = default;

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Uninit() = 0;

	SceneManager* GetSceneManager() { return sceneManager; }
};
