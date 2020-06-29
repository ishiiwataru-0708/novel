#include<DxLib.h>
#include "Key.h"

MouseClass* MouseClass::Instance = nullptr;

void MouseClass::ResetMouse()
{
	for (int i = 0; i < 2; i++)
	{
		MouseState[i] = false;
	}

}

/*マウスの状態を取得*/
void MouseClass::SetHitMouse()
{
	//クリックされたキーを取得
	if (GetMouseInput() & MOUSE_INPUT_LEFT)
	{

		MouseState[MOUSE::_LEFT] = true;
	}
	/*else
	{
		MouseState[MOUSE::_LEFT] = false;

	}*/
	if (GetMouseInput() & MOUSE_INPUT_RIGHT)
	{
		MouseState[MOUSE::_RIGHT] = true;
	}
	/*else
	{
		MouseState[MOUSE::_RIGHT] = false;
	}*/

	//現在のマウス座標を取得
	GetMousePoint(&MouseX, &MouseY);

	//マウスホイールの回転量を取得
	MouseWheel = GetMouseWheelRotVol();
}

/*マウスの座標を返す*/
void MouseClass::GetPoint(int* x, int* y)
{
	//現在のマウス座標をポインタに代入
	*x = MouseX;
	*y = MouseY;
}

/*マウスの各座標を返す*/
void MouseClass::GetPointX(int& x)
{ 
	x = MouseX;
}
void MouseClass::GetPointY(int& y) 
{ 
	y = MouseY; 
}

/*マウスホイールの回転量を取得*/
int MouseClass::GetWheel() 
{
	return MouseWheel;
}

/*マウスの状態を返す*/
bool MouseClass::GetState(MOUSE MouseCode) 
{
	//マウスの状態を返す
	return MouseState[MouseCode];
}
