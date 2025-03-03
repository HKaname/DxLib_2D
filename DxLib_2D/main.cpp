#include <cmath>
#include "DxLib.h"
#include "Entity.h"
#include "SpriteRenderer.h"
#include "Transform.h"
#include "SceneManager.h"
#include "SceneTitle.h"
#include <memory>

const char* TITLE = "Test";
const int WIN_WIDTH = 1280;
const int WIN_HEIGHT = 780;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);
	SetWindowSizeChangeEnableFlag(false, false);
	SetMainWindowText(TITLE);
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);
	SetWindowSizeExtendRate(1, 0);
	SetBackgroundColor(35, 35, 35);
	SetDrawScreen(DX_SCREEN_BACK);
	DxLib_Init();

	if (DxLib_Init() == -1)
		return -1;

	SceneManager sceneManager;
	sceneManager.ChangeScene(std::make_unique<TitleScene>(&sceneManager));

	char keys[256];

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		GetHitKeyStateAll(keys);

		sceneManager.Update();
		sceneManager.Draw();
	}

	DxLib_End();
	return 0;
}