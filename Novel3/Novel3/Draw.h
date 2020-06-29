#pragma once
#include<vector>
#include "User.h"
#include <string>
#include"comon.h"
#include"anime.h"

//�摜�`����W�Ŏg��
namespace GRAPH 
{
	enum { X, Y };
}

//�Q�[���w�i�R�[�h
namespace GAME_BACK {
	enum { EKIMAE, TUUGAKU,KYOUSITU, BLACK };
}

//�Q�[���L�����N�^�[�R�[�h
namespace GAME_CHAR {
	enum { HARUKA,NANASE, NOT };
}

/*�񎟌��z���vector���`*/
using std::vector;
typedef vector< vector<int> > Dvector_i;
typedef vector< vector<std::string> > Dvector_s;


struct ConfigArg_rec
{
	//�p�����[�^
	int			SetNo;	//�ݒ肳��Ă���l
};

/*�R���t�B�O�f�[�^�\����*/
struct ConfigData_rec
{
	//�e�L�X�g
	int  TextSpeed;
};

class GraphClass
{
protected:
	virtual void Load() = 0;		//�摜���[�h
	virtual void SetPoint() = 0;	//�`����W�Z�b�g

public:
	virtual void Draw() = 0;		//�摜�`��
	
	AnimeClass Anime;			//�A�j���C���X�^���X(�W��-�����\��)
};

class TitleGraphClass : public GraphClass
{
private:
	//�摜�n���h��
	int  TitleBackHandle;	//�w�i�摜

	//�`����W
	int  TitleBackPoint[2];	//�w�i�摜�`����W
	int fontSize1;	// ̫�Ļ���
	int fontSize2;	// ̫�Ļ���


	//���\�b�h
	void Load();			//�摜���[�h
	void SetPoint();		//�`����W�Z�b�g

public:
	TitleGraphClass();		//������
	void Draw();			//�摜�`��
};


/*----------------------------
 | �e�L�X�g�O���t�B�b�N�N���X |
  ----------------------------*/
class TextGraphClass : public GraphClass 
{
private:
	//�摜�n���h��
	vector<int> GameBackHandle;		//�w�i�摜
	int CharacterHandle;			//�L�����N�^�摜
	int CharacterHandle2;			//�L�����N�^�摜
	int TextBoxHandle;				//�e�L�X�g�{�b�N�X

	//�`����W
	int GameBackPoint[3];			//�w�i�摜
	int CharacterPoint[2];			//�L�����N�^�摜
	int TextBoxPoint[2];			//�e�L�X�g�{�b�N�X

	//���\�b�h
	void Load();					//�摜���[�h
	void SetPoint();				//�摜���W�Z�b�g


public:
	TextGraphClass();				//������
	void Draw();					//�ꉞ�ˁA���Ƃŏ�������
	void DrawBack(UserClass& User);	//�w�i�`��
	void DrawChar(UserClass& User);	//�L�����N�^�`��
	void DrawWindow();				//�e�L�X�g�E�B���h�E�`��

};

class ConfigGraphClass : public GraphClass 
{
private:
	//�萔
	enum { TEXTSPEED };

	struct ConfigData_rec ConfigData;				//�R���t�B�O�R�s�[���
	struct ConfigArg_rec  ConfigParam[1];			//�p�����[�^

	//���\�b�h
	void Load();
	void SetPoint();

public:
	//ConfigGraphClass();								//������

	void SetMenuParam();							//���j���[�p�����[�^�Z�b�g


};





