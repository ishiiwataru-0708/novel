#pragma once
#include"User.h"
#include"Draw.h"
//�^�C�g����ʂ̃��j���[�Ŏg��

	enum TITLE_MODE{ START};

class TitleClass 
{
protected:
	TITLE_MODE Select = START;
	bool FadeFlag;

public:
	void Main(int& ChangeFlag, UserClass& User);						//���C���֐�
	void ModeChange(int& ModeFlag, int& ChangFlag, UserClass& User);	//���[�h�`�F���W
	TitleGraphClass Graph;//�^�C�g���O���t�B�b�N����
};
