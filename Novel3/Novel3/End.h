#pragma once
#include"User.h"


class EndingClass 
{
public:
	EndingClass();									//�G���f�B���O�N���X
	void Main(UserClass& User, int& ModeFlag);		//���C���֐�
	void StartMovie(UserClass& User);				//����Đ�
	void SaveEnd();									//�G���f�B���O���}�������Ƃ��Z�[�u
	void BackTitle(UserClass& User, int& ModeFlag);	//�^�C�g���ɖ߂�
};