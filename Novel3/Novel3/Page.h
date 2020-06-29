#pragma once
#include"User.h"
#include"Text.h"
#include"title.h"

class PageClass 
{
protected:
	int ModeFlag;											//動作モード(Main･Load･Confの三種類)
	int ChangeFlag;											//モードが変わったときに立つ

public:
	void MovePage(int select, int FadeFlag, UserClass& User);	//ページ遷移処理
	void SetMode(int Mode, int FadeFlag);					//モードセット
	int  GetMode();											//現在モード取得
};

/*----------------------
 | タイトルページクラス |
  ----------------------*/
class TitlePageClass : public PageClass 
{
public:
	TitlePageClass();					//初期化
	void Main(UserClass& User);			//タイトルページの入り口
	TitleClass      Title;				//タイトルクラスインスタンス(集約-分解構造)
	
};

class GamePageClass : public PageClass 
{
public:
	GamePageClass();					//初期化
	void Main(UserClass& User);			//ゲームページの入り口
	TextClass		Text;				//テキストクラス(集約-分解構造)	
};