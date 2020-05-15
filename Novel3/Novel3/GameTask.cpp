#include "GameTask.h"
#include "DxLib.h"
#include"Key.h"
#include"comon.h"

 GameTask::GameTask()
{
	SystemInit();

	fontSize1 = CreateFontToHandle(NULL, 100, 100);// X:16,Y:32

}

GameTask::~GameTask()
{
	
}

int GameTask::GameTitle()
{
	DrawString(0, 0, "title", 0xffff);

	titleImage = LoadGraph("image/’ÊŠw˜H(’‹).jpg");

	DrawGraph(0, 0, titleImage, true);

	DrawStringToHandle(200, 200, "INCONTRO",
		GetColor(255, 125, 0), fontSize1);// 

	return 0;
}

int GameTask::GameClear()
{
	return 0;
}

int GameTask::GameMain()
{
	
	DrawString(0, 0, "main", 0xffff);


	return 0;
}
int GameTask::SystemInit()
{
	ChangeWindowMode(true);
	SetWindowText("WINDOW_NAME");
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	if (DxLib_Init() == -1)return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	SetUseZBuffer3D(true);	// ZÊŞ¯Ì§‚ğ—LŒø‚É‚·‚é
	SetWriteZBuffer3D(true);// ZÊŞ¯Ì§‚Ö‚Ì‘‚«‚İ‚ğ—LŒø‚É‚·‚é

	//WaitKey();

	gameMode = GAME_TITLE;


	return 1;
}

void GameTask::ChengeGameMode(GAME_MODE name)
{
	gameMode = name;
}

int GameTask::GameUpdate(void)
{
	switch (gameMode)
	{
	case GAME_TITLE:
		GameTitle();
		break;
	case GAME_MAIN:
		GameMain();
		break;
	case GAME_CLEAR:
		GameClear();
		break;
		break;
	}

	return 0;
}