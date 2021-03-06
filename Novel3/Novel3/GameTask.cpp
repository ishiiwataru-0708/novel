#include "GameTask.h"
#include "DxLib.h"
#include"Key.h"
#include"comon.h"
#include"User.h"
#include"Text.h"

 GameTask::GameTask()
{
	SystemInit();

	mouse = new MouseClass;

	fontSize1 = CreateFontToHandle(NULL, 100, 100);
	fontSize2 = CreateFontToHandle(NULL, 25, 25);
}

GameTask::~GameTask()
{
	delete(mouse);
}

int GameTask::GameTitle()
{
	
	titleImage = LoadGraph("image/通学路(昼).jpg");

	
	DrawGraph(0, 0, titleImage, true);//画像の表示

	DrawString(100, 0, "title", 0xffff);

	return 0;
}

int GameTask::GameClear()
{
	DrawString(0, 0, "CLear", 0xffff);
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

	SetUseZBuffer3D(true);	// Zﾊﾞｯﾌｧを有効にする
	SetWriteZBuffer3D(true);// Zﾊﾞｯﾌｧへの書き込みを有効にする

	//WaitKey();

	gameMode = GAME_TITLE;


	return 1;
}

void GameTask::ChengeGameMode(GAME_MODE name)
{
	gameMode = name;
}

/*int GameTask::GameUpdate(void)
{
	//変数宣言
	bool EndFlag = 0;


/*	mouse->SetHitMouse();
	switch (gameMode)
	{
	case GAME_TITLE:
		GameTitle();
		if (mouse->GetState(MOUSE::LEFT) == true)
		{
			gameMode = GAME_MAIN;
		}
		break;
	case GAME_MAIN:
	   GameMain();
		break;
	case GAME_CLEAR:
		GameClear();
		break;
	}

	return 0;*/
//}*/