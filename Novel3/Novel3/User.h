#pragma once

//���[�h�ꗗ

enum MODE  { MAIN,OTHER, END };


//�y�[�W�ꗗ
  enum PAGE { P_TITLE, P_GAME, P_END};

class UserClass
{
private:
	int    PageFlag;								//���݂̃y�[�W
	int    BackCode;								//�w�i�摜�R�[�h
	int    CharCode;								//�L�����N�^�R�[�h


public:
	 UserClass();
	 ~UserClass();

	 void SetPage(int Page);							//���݃y�[�W���Z�b�g
	 int  GetPage();									//���݃y�[�W���擾

	 //�w�i�R�[�h
	 void SetBackCode(int Code);
	 int  GetBackCode();
	 int  GetTextSpeed();		//�e�L�X�g�̕\�����x
	 int  GetAutoTextSpeed();	//�I�[�g���[�h�̕\�����x

	 //�L�����N�^�R�[�h
	 void SetCharacterCode(int Code);
	 int  GetCharacterCode();
};