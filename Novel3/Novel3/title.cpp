#include"DxLib.h"
#include"User.h"
#include"title.h"
#include"Key.h"

/*�^�C�g�����C�����[�h*/
void TitleClass::Main(int& ChangeFlag, UserClass& User) 
{
	//�萔�錾
	const int Speed = 5;	//�t�F�[�h�C�����x

	//���[�h�`�F���W���Ĉ���
	if (ChangeFlag == true)
	{
		ChangeFlag = false;			//���[�h�`�F���W�t���O��܂�
		FadeFlag = false;			//�t�F�[�h�����t���O���
	}

	FadeFlag = Graph.Anime.FadeIn(Speed);
	//�w�i�`��
	Graph.Draw();
}

void TitleClass::ModeChange(int& ModeFlag, int& ChangeFlag, UserClass& User) 
{

	//�C���X�^���X��
	//MouseClass Mouse = MouseClass::GetInstance();

	//Mouse.SetHitMouse();

	//���N���b�N���ꂽ
	if (LP_MOUSE.GetState(MOUSE::_LEFT) == true && FadeFlag == true)
	{
		//�Q�[���X�^�[�g
		if (Select == TITLE_MODE::START) 
		{
			ModeFlag = MODE::OTHER;
			User.SetPage(PAGE::P_GAME);
		}

	}

}