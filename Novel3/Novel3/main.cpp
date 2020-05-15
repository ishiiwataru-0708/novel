#include <DxLib.h>
#include"GameTask.h"

class GameTask;
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_
	HINSTANCE hPrevIntance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	GameTask* gameTask; //ゲームタスク管理変数
	gameTask = new GameTask();

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) != 1)
	{
		ClsDrawScreen();

		gameTask->GameUpdate();

		ScreenFlip();
	}
	DxLib_End();
	return 0;

}