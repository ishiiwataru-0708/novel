#include"DxLib.h"
#include"anime.h"

AnimeClass::AnimeClass()
{
	FadeFlag = false;
	Count = 0;
}

/*�t�F�[�h�C������*/
int AnimeClass::FadeIn(int Speed)
{
	//��ʂ����񂾂񖾂邭����
	if (FadeFlag == 0) 
	{
		SetDrawBright(Count, Count, Count);
		Count += Speed;
	}

	//��ʂ��ő�܂Ŗ��邭�Ȃ������~
	if (Count >= 255) FadeFlag = 1;

	return FadeFlag;
}

/*�S�Ă̕ϐ���������*/
void AnimeClass::Reset() 
{
	FadeFlag = false;
	Count = 0;
}