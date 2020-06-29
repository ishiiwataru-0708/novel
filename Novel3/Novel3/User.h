#pragma once

//モード一覧

enum MODE  { MAIN,OTHER, END };


//ページ一覧
  enum PAGE { P_TITLE, P_GAME, P_END};

class UserClass
{
private:
	int    PageFlag;								//現在のページ
	int    BackCode;								//背景画像コード
	int    CharCode;								//キャラクタコード


public:
	 UserClass();
	 ~UserClass();

	 void SetPage(int Page);							//現在ページをセット
	 int  GetPage();									//現在ページを取得

	 //背景コード
	 void SetBackCode(int Code);
	 int  GetBackCode();
	 int  GetTextSpeed();		//テキストの表示速度
	 int  GetAutoTextSpeed();	//オートモードの表示速度

	 //キャラクタコード
	 void SetCharacterCode(int Code);
	 int  GetCharacterCode();
};