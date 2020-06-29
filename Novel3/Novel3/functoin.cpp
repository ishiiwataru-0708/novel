#include"Key.h"
#include<DxLib.h>

int ProcessLoop()
{
	//インスタンス化
	KeyClass* Key = KeyClass::GetInstance();
	MouseClass Mouse = MouseClass::GetInstance();

	//固定処理
	ScreenFlip();
	if (ClearDrawScreen() != 0) return -1;
	if (ProcessMessage() != 0) return -1;
	Key->SetHitKey();
	LP_MOUSE.SetHitMouse();

	return 0;
}