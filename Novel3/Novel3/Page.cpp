#include"DxLib.h"
#include"User.h"
#include"Text.h"
#include"Page.h"
#include"title.h"
#include"test.h"

//*�y�[�W�J�ڏ���*/
void PageClass::MovePage(int Select, int FadeFlag, UserClass& User) 
{
	//�N���b�N���ꂽ��y�[�W�ړ�
	if (FadeFlag == true) User.SetPage(Select);
}

/*���[�h�Z�b�g*/
void PageClass::SetMode(int Mode, int FadeFlag)
{
	if (FadeFlag == true) ModeFlag = Mode;
}

/*���[�h�擾*/
int PageClass::GetMode()
{
	return ModeFlag;
}


/*----------------------
 | �^�C�g���y�[�W�N���X |
  ----------------------*/
  /*������*/
TitlePageClass::TitlePageClass() 
{
	//�������샂�[�h�ݒ�
	ModeFlag = MODE::MAIN;
}

/*�^�C�g�����C��*/
void TitlePageClass::Main(UserClass& User) 
{
	//���[�h����
	switch (ModeFlag) 
	{
		//���C�����[�h(�g�b�v���)
	case MODE::MAIN:
		Title.Main(ChangeFlag, User);
		Title.ModeChange(ModeFlag, ChangeFlag, User);
		break;
	default:
		break;
	}

	//�y�[�W���ς��
	if (ModeFlag == MODE::OTHER) 
	{
		ModeFlag = MODE::MAIN;	//���[�h�t���O��������
		ChangeFlag = true;		//�`�F���W�t���O�𗧂Ă�
	}

}

/*������*/
GamePageClass::GamePageClass()
{
	//�������샂�[�h�ݒ�
	ModeFlag = MODE::MAIN;
}

/*�Q�[�����C��*/
void GamePageClass::Main(UserClass& User)
{
	//���[�h�擾
	switch (ModeFlag)
	{
		//�Q�[�����C��
	case MODE::MAIN:
		Text.Main(ChangeFlag,User);
		Text.ModeChange(ModeFlag, ChangeFlag, User);
		break;
		//�G���f�B���O
	case MODE::END:
		//	Ending.Main(User, ModeFlag);
		break;
	}
			//�y�[�W���ς��Ƃ��A�㏈��������
			if (ModeFlag == MODE::OTHER)
			{
				ModeFlag = MODE::MAIN;	//���[�h�t���O��������
				ChangeFlag = true;			//�`�F���W�t���O�𗧂Ă�
			}
	

}