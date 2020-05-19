#pragma once


class KeyClass;
class MouseClass;
class GameTask
{
public:
	// 画面遷移用
	enum GAME_MODE
	{
		GAME_TITLE,
		GAME_MAIN,
		GAME_MAIN2,
		GAME_CLEAR,
	};
	GAME_MODE gameMode;

	

	// ----- ｺﾝｽﾄﾗｸﾀ群
	GameTask(); 
	~GameTask();  // ﾃﾞｽﾄﾗｸﾀ 

	int SystemInit(void);
	int GameTitle(void); // ｹﾞｰﾑﾀｲﾄﾙ
	int GameMain(void);  // ｹﾞｰﾑﾒｲﾝ
	int GameMain2(void);  // ｹﾞｰﾑﾒｲﾝ
	int GameClear(void); // ｹﾞｰﾑﾘｻﾞﾙﾄ

	int GameUpdate(void);

	void ChengeGameMode(GAME_MODE);

	int fontSize1;	// ﾌｫﾝﾄｻｲｽﾞ
	int fontSize2;	// ﾌｫﾝﾄｻｲｽﾞ

	int titleImage; //タイトルの背景
	int CharaImage; //キャラクターの画像
	int CharaImage2; //キャラクターの画像

	int Tcount; //タイトルカウント

	MouseClass* mouse;

};
