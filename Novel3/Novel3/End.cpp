#include<DxLib.h>
#include"User.h"
#include"End.h"

/*������*/
EndingClass::EndingClass() 
{
}


/*�^�C�g���ɖ߂�*/
void EndingClass::BackTitle(UserClass& User, int& ModeFlag)
{
	
		ModeFlag = MODE::MAIN;
	
}

/*���C��*/
void EndingClass::Main(UserClass& User, int& ModeFlag)
{

	//�G���f�B���O��A�^�C�g���ɖ߂�
	BackTitle(User, ModeFlag);
}
