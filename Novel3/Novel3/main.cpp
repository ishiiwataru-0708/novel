#include <DxLib.h>
#include"comon.h"
#include"User.h"
#include"Text.h"
#include"Page.h"
#include"GameTask.h"
#include"function.h"
#include"Key.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_
	HINSTANCE hPrevIntance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	/*GameTask* gameTask; //ゲームタスク管理変数
	gameTask = new GameTask();


	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) != 1)
	{
		ClsDrawScreen();


		gameTask->GameUpdate();

		ScreenFlip();
	}*/

	bool EndFlag = 0;

	ChangeWindowMode(true);
	SetWindowText("WINDOW_NAME");
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 16);
	if (DxLib_Init() == -1)return -1;
	SetDrawScreen(DX_SCREEN_BACK);

	SetUseZBuffer3D(true);	// Zﾊﾞｯﾌｧを有効にする
	SetWriteZBuffer3D(true);// Zﾊﾞｯﾌｧへの書き込みを有効にする

	//インスタンス化
	UserClass		 User;							//ユーザ情報クラス
	TitlePageClass* TitlePage = new TitlePageClass;	//タイトルページクラス
	GamePageClass* GamePage = new GamePageClass;	//ゲームページクラス

	//メインループ
	while (ProcessLoop() == 0 && EndFlag != TRUE)
	{

		switch (User.GetPage())
		{
			//タイトルページ
		case PAGE::P_TITLE:
			TitlePage->Main(User);
			break;
			//ゲームページ
		case PAGE::P_GAME:
			GamePage->Main(User);
			break;
			//ゲーム終了
		case PAGE::P_END:
			EndFlag = TRUE;
			break;
		}

		LP_MOUSE.ResetMouse();

	}
	DxLib_End();
	return 0;
}