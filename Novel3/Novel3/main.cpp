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
	/*GameTask* gameTask; //�Q�[���^�X�N�Ǘ��ϐ�
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

	SetUseZBuffer3D(true);	// Z�ޯ̧��L���ɂ���
	SetWriteZBuffer3D(true);// Z�ޯ̧�ւ̏������݂�L���ɂ���

	//�C���X�^���X��
	UserClass		 User;							//���[�U���N���X
	TitlePageClass* TitlePage = new TitlePageClass;	//�^�C�g���y�[�W�N���X
	GamePageClass* GamePage = new GamePageClass;	//�Q�[���y�[�W�N���X

	//���C�����[�v
	while (ProcessLoop() == 0 && EndFlag != TRUE)
	{

		switch (User.GetPage())
		{
			//�^�C�g���y�[�W
		case PAGE::P_TITLE:
			TitlePage->Main(User);
			break;
			//�Q�[���y�[�W
		case PAGE::P_GAME:
			GamePage->Main(User);
			break;
			//�Q�[���I��
		case PAGE::P_END:
			EndFlag = TRUE;
			break;
		}

		LP_MOUSE.ResetMouse();

	}
	DxLib_End();
	return 0;
}