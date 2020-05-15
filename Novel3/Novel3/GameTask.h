#pragma once


class KeyClass;

class GameTask
{
public:
	// ��ʑJ�ڗp
	enum GAME_MODE
	{
		GAME_TITLE,
		GAME_MAIN,
		GAME_CLEAR,
	};
	GAME_MODE gameMode;

	

	// ----- �ݽ�׸��Q
	GameTask(); // ��̫�ĺݽ�׸��� private �ɂ��ĊO�����琶���ł��Ȃ��l�ɂ���
	~GameTask();  // �޽�׸� 

	int SystemInit(void);
	int GameTitle(void); // �ް�����
	int GameMain(void);  // �ް�Ҳ�
	int GameClear(void); // �ް�ػ���

	int GameUpdate(void);

	void ChengeGameMode(GAME_MODE);

	int fontSize1;	// ̫�Ļ���

	int titleImage; //�^�C�g���̔w�i

};
