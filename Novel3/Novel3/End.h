#pragma once
#include"User.h"


class EndingClass 
{
public:
	EndingClass();									//エンディングクラス
	void Main(UserClass& User, int& ModeFlag);		//メイン関数
	void StartMovie(UserClass& User);				//動画再生
	void SaveEnd();									//エンディングを迎えたことをセーブ
	void BackTitle(UserClass& User, int& ModeFlag);	//タイトルに戻る
};