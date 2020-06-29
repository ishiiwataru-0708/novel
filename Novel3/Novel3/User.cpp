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

//現在ページをセット
void UserClass::SetPage(int Page) 
{
	PageFlag = Page;
}

//現在ページを取得
int UserClass::GetPage() 
{
	return PageFlag;
}

/*背景コードセット･ゲット*/
void UserClass::SetBackCode(int Code)
{ 
	this->BackCode = Code;
}
int  UserClass::GetBackCode()
{ 
	return BackCode;
}
/*キャラクタコードセット･ゲット*/
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
