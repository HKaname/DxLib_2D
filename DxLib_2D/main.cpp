#include <cmath>
#include "DxLib.h"
#include "Entity.h"
#include "SpriteRenderer.h"
#include "Transform.h"

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

	if (DxLib_Init() == -1)
		return -1;

	// プレイヤー情報
	const int speed = 5;
	int playerX = (WIN_WIDTH / 2) - (196 / 2);
	int playerY = (WIN_HEIGHT / 2) - (245 / 2);
	int playerSize = 50;
	Entity player;
	player.AddComponent<Transform>(playerX, playerY);
	player.AddComponent<SpriteRenderer>("Assets/Texture/test.png");

	// コンポーネントの初期化
	player.Init();

	char keys[256];

	while (true)
	{
		GetHitKeyStateAll(keys);
		ClearDrawScreen();

		ScreenFlip();
		WaitTimer(20);
		if (ProcessMessage() == -1)
			break;
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			break;
	}

	DxLib_End();
	return 0;
}