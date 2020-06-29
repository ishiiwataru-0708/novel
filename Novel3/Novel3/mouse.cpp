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

/*�}�E�X�̏�Ԃ��擾*/
void MouseClass::SetHitMouse()
{
	//�N���b�N���ꂽ�L�[���擾
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

	//���݂̃}�E�X���W���擾
	GetMousePoint(&MouseX, &MouseY);

	//�}�E�X�z�C�[���̉�]�ʂ��擾
	MouseWheel = GetMouseWheelRotVol();
}

/*�}�E�X�̍��W��Ԃ�*/
void MouseClass::GetPoint(int* x, int* y)
{
	//���݂̃}�E�X���W���|�C���^�ɑ��
	*x = MouseX;
	*y = MouseY;
}

/*�}�E�X�̊e���W��Ԃ�*/
void MouseClass::GetPointX(int& x)
{ 
	x = MouseX;
}
void MouseClass::GetPointY(int& y) 
{ 
	y = MouseY; 
}

/*�}�E�X�z�C�[���̉�]�ʂ��擾*/
int MouseClass::GetWheel() 
{
	return MouseWheel;
}

/*�}�E�X�̏�Ԃ�Ԃ�*/
bool MouseClass::GetState(MOUSE MouseCode) 
{
	//�}�E�X�̏�Ԃ�Ԃ�
	return MouseState[MouseCode];
}
