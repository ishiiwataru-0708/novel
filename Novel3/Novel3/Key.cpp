#include <DxLib.h>
#include"Key.h"

KeyClass* KeyClass::GetInstance()
{
	static KeyClass i;
	return &i;
}

void KeyClass::SetHitKey() 
{
	char TmpKey[256];

	GetHitKeyStateAll(TmpKey);

	for (int i = 0; i < 256; i++) 
	{
		if (TmpKey[i] == 1)
		{
			KeyState[i]++;
		}
		else
		{
			KeyState[i] = 0;
		}
	}
}

/*指定されたキー状態を返す*/
int KeyClass::GetState(int KeyCode) 
{
	return KeyState[KeyCode];
}
