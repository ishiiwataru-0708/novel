#pragma once
#include<iostream>

//マウスクラスで使う
enum  MOUSE { _LEFT, _RIGHT };

#define LP_MOUSE MouseClass::GetInstance()


class KeyClass 
{
private:
	int KeyState[256];
//	KeyClass() {}

public:
	static KeyClass* GetInstance();
	void SetHitKey();
	int  GetState(int KeyCode);
};

/*---------------------------
 | マウスクラス(シングルトン)|
  ---------------------------*/
class MouseClass 
{
private:
	int MouseX, MouseY;					  //クリックされた座標を格納
	bool MouseState[2];					  //クリックしたキーを格納
	int MouseWheel;						  //マウスホイールの回転量を格納
	static MouseClass* Instance;
//	MouseClass() {}

public:

	static MouseClass& GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new MouseClass();
		}

		return *Instance;
	}

	void ResetMouse();
	void SetHitMouse();					//クリックした座標を取得(右クリックか左クリックかも)
	void GetPoint(int* x, int* y);		//クリックした座標を返す
	void GetPointX(int& x);				//x座標を返す
	void GetPointY(int& y);				//y座標を返す
	int  GetWheel();					//マウスホイールの回転量を取得
	bool  GetState(MOUSE MouseCode);		//マウスの状態を返す
};
