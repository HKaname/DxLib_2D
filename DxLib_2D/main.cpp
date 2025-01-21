#include  "DxLib.h"

const char* TITLE = "Test";
const int WIN_WIDTH = 1280;
const int WIN_HEIGHT = 780;

// ÉvÉçÉOÉâÉÄÇÕ WinMain Ç©ÇÁénÇ‹ÇËÇ‹Ç∑
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

	const int speed = 5;
	int x = 100;
	int y = 100;
	const int size = 50;

	char keys[256];

	while (true)
	{
		ClearDrawScreen();

		GetHitKeyStateAll(keys);

		if (keys[KEY_INPUT_A])
		{
			x -= speed;
		}
		else if (keys[KEY_INPUT_D])
		{
			x += speed;
		}

		if (keys[KEY_INPUT_W])
		{
			y -= speed;
		}
		else if (keys[KEY_INPUT_S])
		{
			y += speed;
		}

		DrawBox(x, y, x + size, y + size, GetColor(255, 255, 255), true);
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