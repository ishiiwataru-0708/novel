#include <DxLib.h>

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_
	HINSTANCE hPrevIntance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//�E�B���h�E���[�h�ŋN��
	 ChangeWindowMode(TRUE);
	 // D X �� �C �u �� �� �� �� ��
	 if (DxLib_Init() == -1)
	 {
		 return -1;

	 }
	 ClsDrawScreen();
	 SetDrawScreen(DX_SCREEN_BACK);				//����ʐݒ�

	 SetGraphMode(800,600,32);
	
	 ScreenFlip();
	 WaitKey();

	 // D X �� �C �u �� �� �I �� �� ��
		 DxLib_End();
	 return 0;

}