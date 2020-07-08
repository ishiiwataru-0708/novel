#include"DxLib.h"
#include"User.h"
#include"title.h"
#include"Key.h"

/*タイトルメインモード*/
void TitleClass::Main(int& ChangeFlag, UserClass& User) 
{
	//定数宣言
	const int Speed = 5;	//フェードイン速度

	//モードチェンジして一回目
	if (ChangeFlag == true)
	{
		ChangeFlag = false;			//モードチェンジフラグを折る
		FadeFlag = false;			//フェード完了フラグを折
	}

	FadeFlag = Graph.Anime.FadeIn(Speed);
	//背景描画
	Graph.Draw();
}

void TitleClass::ModeChange(int& ModeFlag, int& ChangeFlag, UserClass& User) 
{

	//インスタンス化
	//MouseClass Mouse = MouseClass::GetInstance();

	//Mouse.SetHitMouse();

	//左クリックされた
	if (LP_MOUSE.GetState(MOUSE::_LEFT) == true && FadeFlag == true)
	{
		//ゲームスタート
		if (Select == TITLE_MODE::START) 
		{
			ModeFlag = MODE::OTHER;
			User.SetPage(PAGE::P_GAME);
		}

	}

}