#include"DxLib.h"
#include"anime.h"

AnimeClass::AnimeClass()
{
	FadeFlag = false;
	Count = 0;
}

/*フェードイン処理*/
int AnimeClass::FadeIn(int Speed)
{
	//画面をだんだん明るくする
	if (FadeFlag == 0) 
	{
		SetDrawBright(Count, Count, Count);
		Count += Speed;
	}

	//画面が最大まで明るくなったら停止
	if (Count >= 255) FadeFlag = 1;

	return FadeFlag;
}

/*全ての変数を初期化*/
void AnimeClass::Reset() 
{
	FadeFlag = false;
	Count = 0;
}