#include<DxLib.h>
#include"User.h"
#include"End.h"

/*初期化*/
EndingClass::EndingClass() 
{
}


/*タイトルに戻る*/
void EndingClass::BackTitle(UserClass& User, int& ModeFlag)
{
	
		ModeFlag = MODE::MAIN;
	
}

/*メイン*/
void EndingClass::Main(UserClass& User, int& ModeFlag)
{

	//エンディング後、タイトルに戻る
	BackTitle(User, ModeFlag);
}
