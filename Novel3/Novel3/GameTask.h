#pragma once


class KeyClass;
class MouseClass;
class GameTask
{
public:
	// ��ʑJ�ڗp
	enum GAME_MODE
	{
		GAME_TITLE,
		GAME_MAIN,
		GAME_MAIN2,
		GAME_CLEAR,
	};
	GAME_MODE gameMode;

	

	// ----- �ݽ�׸��Q
	GameTask(); 
	~GameTask();  // �޽�׸� 

	int SystemInit(void);
	int GameTitle(void); // �ް�����
	int GameMain(void);  // �ް�Ҳ�
	int GameMain2(void);  // �ް�Ҳ�
	int GameClear(void); // �ް�ػ���

	int GameUpdate(void);

	void ChengeGameMode(GAME_MODE);

	int fontSize1;	// ̫�Ļ���
	int fontSize2;	// ̫�Ļ���

	int titleImage; //�^�C�g���̔w�i
	int CharaImage; //�L�����N�^�[�̉摜
	int CharaImage2; //�L�����N�^�[�̉摜

	int Tcount; //�^�C�g���J�E���g

	MouseClass* mouse;

};
