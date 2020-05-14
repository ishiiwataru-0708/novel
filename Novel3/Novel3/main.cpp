#include <DxLib.h>

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_
	HINSTANCE hPrevIntance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//ウィンドウモードで起動
	 ChangeWindowMode(TRUE);
	 // D X ラ イ ブ ラ リ 初 期 化
	 if (DxLib_Init() == -1)
	 {
		 return -1;

	 }
	 ClsDrawScreen();
	 SetDrawScreen(DX_SCREEN_BACK);				//裏画面設定

	 SetGraphMode(800,600,32);
	
	 ScreenFlip();
	 WaitKey();

	 // D X ラ イ ブ ラ リ 終 了 処 理
		 DxLib_End();
	 return 0;

}