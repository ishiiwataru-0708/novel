#include "User.h"
#include"Page.h"
#include<DxLib.h>

UserClass::UserClass()
{
	PageFlag = PAGE::P_TITLE;
	BackCode = 0;
	CharCode = 0;
}


UserClass::~UserClass()
{

}

//���݃y�[�W���Z�b�g
void UserClass::SetPage(int Page) 
{
	PageFlag = Page;
}

//���݃y�[�W���擾
int UserClass::GetPage() 
{
	return PageFlag;
}

/*�w�i�R�[�h�Z�b�g��Q�b�g*/
void UserClass::SetBackCode(int Code)
{ 
	this->BackCode = Code;
}
int  UserClass::GetBackCode()
{ 
	return BackCode;
}
/*�L�����N�^�R�[�h�Z�b�g��Q�b�g*/
void UserClass::SetCharacterCode(int Code) 
{ 
	this->CharCode = Code;
}
int  UserClass::GetCharacterCode() 
{ 
	return CharCode; 
}

int UserClass::GetTextSpeed() 
{
	int TextSpeed;

	 TextSpeed = 5;

	return TextSpeed;
}

int UserClass::GetAutoTextSpeed() 
{
	int AutoSpeed;

	 AutoSpeed = 5;
	
	return AutoSpeed;
}
