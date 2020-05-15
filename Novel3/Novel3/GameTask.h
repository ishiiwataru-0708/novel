#pragma once


class KeyClass;

class GameTask
{
public:
	// 画面遷移用
	enum GAME_MODE
	{
		GAME_TITLE,
		GAME_MAIN,
		GAME_CLEAR,
	};
	GAME_MODE gameMode;

	

	// ----- ｺﾝｽﾄﾗｸﾀ群
	GameTask(); // ﾃﾞﾌｫﾙﾄｺﾝｽﾄﾗｸﾀを private にして外部から生成できない様にする
	~GameTask();  // ﾃﾞｽﾄﾗｸﾀ 

	int SystemInit(void);
	int GameTitle(void); // ｹﾞｰﾑﾀｲﾄﾙ
	int GameMain(void);  // ｹﾞｰﾑﾒｲﾝ
	int GameClear(void); // ｹﾞｰﾑﾘｻﾞﾙﾄ

	int GameUpdate(void);

	void ChengeGameMode(GAME_MODE);

	int fontSize1;	// ﾌｫﾝﾄｻｲｽﾞ

	int titleImage; //タイトルの背景

};
