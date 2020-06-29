#pragma once
#include"User.h"
#include"Draw.h"
//タイトル画面のメニューで使う

	enum TITLE_MODE{ START};

class TitleClass 
{
protected:
	TITLE_MODE Select = START;
	bool FadeFlag;

public:
	void Main(int& ChangeFlag, UserClass& User);						//メイン関数
	void ModeChange(int& ModeFlag, int& ChangFlag, UserClass& User);	//モードチェンジ
	TitleGraphClass Graph;//タイトルグラフィック制御
};
