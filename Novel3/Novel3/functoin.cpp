#include"Key.h"
#include<DxLib.h>

int ProcessLoop()
{
	//�C���X�^���X��
	KeyClass* Key = KeyClass::GetInstance();
	MouseClass Mouse = MouseClass::GetInstance();

	//�Œ菈��
	ScreenFlip();
	if (ClearDrawScreen() != 0) return -1;
	if (ProcessMessage() != 0) return -1;
	Key->SetHitKey();
	LP_MOUSE.SetHitMouse();

	return 0;
}