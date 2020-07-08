#pragma once
#include <string>
#include "User.h"
#include<vector>
#include"Draw.h"
#include<sstream>

/*�񎟌��z���vector���`*/
using std::vector;
typedef vector< vector<int> > Dvector_i;
typedef vector< vector<std::string> > Dvector_;

#define EXAMPLE_MACRO_NAME
#define _CRT_SECURE_NO_WARNINGS

class KeyClass;
class TextClass
{
private:
	//�萔
	enum { SceneMax = 8, RowMax = 1024 };						//�V�[���ő吔�A�s���ő�
	enum { NORMAL, NOTWINDOW, END, TITLE }; //�`�惂�[�h�萔

	int  WriteMode;									    //�`�惂�[�h�i�[

	short int  TextCount;								//�e�L�X�g�J�E���^
	short int  SceneCount;								//�V�[���J�E���^
	short int  SerifCount;								//�Z���t�J�E���^

	int  TextGraphEndFlag;								//�e�L�X�g�S���`�抮���t���O
	int  AutoFlag;		//�I�[�g�t���O

	int LineNo[64][1024];								//�e�Z���t�̍s�����擾
	int LineMax[100];									//1�V�[�����Ƃ̃e�L�X�g�̑��s��
	std::string Name[64][1024];							//�L�����l�[���ϐ�
	std::vector<std::vector<std::string>> Text;							//�Z���t�e�L�X�g�ϐ�
	bool oldLeftMouse;
	bool FadeFlag;




public:
	//��������`�F�b�N
	TextClass();										//������
	void InitVar();										//�ϐ�������
	void LoadStory();									//�X�g�[���[���[�h
	int  CutSpace(std::string& TmpText);				//�e�L�X�g����S�p�󔒂���菜��
	void CheckText(UserClass& User);					//�e�L�X�g�`�F�b�N
	std::vector<std::string> StringSplit(const std::string& Str, char Sep);


	//���C���֐�
	void Main(int& ChangeFlag, UserClass& User);		//���C���֐�
	void ModeChange(int& ModeFlag, int& ChangeFlag, UserClass& User);

	//�ʏ�`��֘A
	void NormalWrite(UserClass& User);					//�e�L�X�g�ʏ�`��
	void WriteText(UserClass& User);					//�e�L�X�g�`��

	//���̍s�֐i�߂�
	void PutNextLine(UserClass& User);					//���̍s�֐i�߂�	

	void NotWindow();

	//����R�[�h�`�F�b�N
	void CheckCotrolCode(UserClass& User);


	//�Q�[���O���t�B�b�N
	TextGraphClass Graph;

};

