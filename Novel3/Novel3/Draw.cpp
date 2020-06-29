#include<DxLib.h>
#include"comon.h"
#include"Draw.h"

/*初期化*/

TitleGraphClass::TitleGraphClass()
{
	Load();
	SetPoint();
	
}

/*画像ロード*/
void TitleGraphClass::Load()
{
	TitleBackHandle = LoadGraph("image/通学路(昼).jpg");

}

/*描画座標セット*/
void TitleGraphClass::SetPoint()
{
	TitleBackPoint[GRAPH::X] = 0;
	TitleBackPoint[GRAPH::Y] = 0;
}

/*画像描画*/
void TitleGraphClass::Draw()
{

	DrawGraph(TitleBackPoint[GRAPH::X],
		TitleBackPoint[GRAPH::Y], TitleBackHandle, true);

}


/*初期化*/
TextGraphClass::TextGraphClass()
{
	Load();			//画像読み込み
	SetPoint();		//描画座標セット
}

/*画像ロード*/
void TextGraphClass::Load()
{
	//背景ロード
	GameBackHandle.push_back(LoadGraph("image/駅前(昼).jpg"));
	GameBackHandle.push_back(LoadGraph("image/教室(昼).jpg"));
	GameBackHandle.push_back(LoadGraph("image/通学路(昼).jpg"));

	//キャラクタ描画
	CharacterHandle = LoadGraph("image/藤林遥/ノーマル制服.png");
	CharacterHandle2 = LoadGraph("image/木間ななせ/ノーマル制服.png");

	//テキストボックス
	TextBoxHandle = LoadGraph("image/メッセージウインドウ/box_blue_name.png");

}

/*描画座標セット*/
void TextGraphClass::SetPoint() 
{
	//背景
	GameBackPoint[GRAPH::X] = 0;
	GameBackPoint[GRAPH::Y] = 0;

	//キャラクタ描画座標
	CharacterPoint[GRAPH::X] = SCREEN_SIZE_X / 3;
	CharacterPoint[GRAPH::Y] = 0;

	//テキストボックス
	TextBoxPoint[GRAPH::X] = 0;
	TextBoxPoint[GRAPH::Y] = SCREEN_SIZE_Y - SCREEN_SIZE_Y / 3;

}

/*背景描画*/
void TextGraphClass::DrawBack(UserClass& User)
{
	//背景描画
	switch (User.GetBackCode()) 
	{
	case GAME_BACK::TUUGAKU:
		DrawGraph(GameBackPoint[GRAPH::X], GameBackPoint[GRAPH::Y], 
			GameBackHandle[GAME_BACK::TUUGAKU], true);
		break;

	case GAME_BACK::EKIMAE:
		DrawGraph(GameBackPoint[GRAPH::X], GameBackPoint[GRAPH::Y], 
			GameBackHandle[GAME_BACK::EKIMAE], true);
		break;

	case GAME_BACK::KYOUSITU:
		DrawGraph(GameBackPoint[GRAPH::X], GameBackPoint[GRAPH::Y],
			GameBackHandle[GAME_BACK::KYOUSITU], true);
		break;
	}
}

/*キャラクタ描画*/
void TextGraphClass::DrawChar(UserClass& User)
{
	//キャラクタ描画
	switch (User.GetCharacterCode()) 
	{
	case GAME_CHAR::HARUKA:
		DrawGraph(CharacterPoint[GRAPH::X], CharacterPoint[GRAPH::Y],
			CharacterHandle, TRUE);
		break;

	case GAME_CHAR::NANASE:
		DrawGraph(CharacterPoint[GRAPH::X], CharacterPoint[GRAPH::Y],
			CharacterHandle2, TRUE);
		break;

	case GAME_CHAR::NOT:
		break;
	}
}

/*テキストウィンドウ描画*/
void TextGraphClass::DrawWindow() 
{
	//テキストボックス描画
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	DrawGraph(TextBoxPoint[GRAPH::X],
		TextBoxPoint[GRAPH::Y], TextBoxHandle, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void ConfigGraphClass::SetPoint()
{

}

/*パラメータをセット*/
void ConfigGraphClass::SetMenuParam()
{

	/*コンフィグメニューのパラメータセット*/

	ConfigParam[TEXTSPEED].SetNo = ConfigData.TextSpeed;
}



/*デバッグ用*/
void TextGraphClass::Draw() {}
