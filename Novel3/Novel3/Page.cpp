#include"DxLib.h"
#include"User.h"
#include"Text.h"
#include"Page.h"
#include"title.h"
#include"test.h"

//*ページ遷移処理*/
void PageClass::MovePage(int Select, int FadeFlag, UserClass& User) 
{
	//クリックされたらページ移動
	if (FadeFlag == true) User.SetPage(Select);
}

/*モードセット*/
void PageClass::SetMode(int Mode, int FadeFlag)
{
	if (FadeFlag == true) ModeFlag = Mode;
}

/*モード取得*/
int PageClass::GetMode()
{
	return ModeFlag;
}


/*----------------------
 | タイトルページクラス |
  ----------------------*/
  /*初期化*/
TitlePageClass::TitlePageClass() 
{
	//初期動作モード設定
	ModeFlag = MODE::MAIN;
}

/*タイトルメイン*/
void TitlePageClass::Main(UserClass& User) 
{
	//モード分岐
	switch (ModeFlag) 
	{
		//メインモード(トップ画面)
	case MODE::MAIN:
		Title.Main(ChangeFlag, User);
		Title.ModeChange(ModeFlag, ChangeFlag, User);
		break;
	default:
		break;
	}

	//ページが変わる
	if (ModeFlag == MODE::OTHER) 
	{
		ModeFlag = MODE::MAIN;	//モードフラグを初期化
		ChangeFlag = true;		//チェンジフラグを立てる
	}

}

/*初期化*/
GamePageClass::GamePageClass()
{
	//初期動作モード設定
	ModeFlag = MODE::MAIN;
}

/*ゲームメイン*/
void GamePageClass::Main(UserClass& User)
{
	//モード取得
	switch (ModeFlag)
	{
		//ゲームメイン
	case MODE::MAIN:
		Text.Main(ChangeFlag,User);
		Text.ModeChange(ModeFlag, ChangeFlag, User);
		break;
		//エンディング
	case MODE::END:
		//	Ending.Main(User, ModeFlag);
		break;
	}
			//ページが変わるとき、後処理をする
			if (ModeFlag == MODE::OTHER)
			{
				ModeFlag = MODE::MAIN;	//モードフラグを初期化
				ChangeFlag = true;			//チェンジフラグを立てる
			}
	

}