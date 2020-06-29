#include"DxLib.h"
#include"Text.h"
#include"Key.h"
#include "User.h"
#include"Page.h"

TextClass::TextClass()
{
	InitVar();		//�ϐ�������
	LoadStory();	//�X�g�[���ǂݍ���
}

/*�ϐ�������*/
void TextClass::InitVar() 
{
	//�����o�ϐ�������;
	TextCount = 0;
	SceneCount = 0;
	SerifCount = 0;
	WriteMode = NORMAL;
	TextGraphEndFlag = 0;
	memset(LineMax, 0, sizeof(LineMax));
	memset(LineNo, 0, sizeof(LineNo));
	memset(Text, '\0', sizeof(Text));
	memset(Name, '\0', sizeof(Name));
}

/*�X�g�[���[���[�h*/
void TextClass::LoadStory()
{
	//�^�̕ϐ�
	int							FileHandle;			//�t�@�C���n���h��
	char						TmpBuf[128];		//�e�L�X�g�擾�p�ꎞ�ϐ�
	char						FileName[64];		//�t�@�C�����i�[
	std::string					TmpText;			//�e�L�X�g�擾�㑀��p�ꎞ�I�u�W�F�N�g 
	std::vector<std::string>	SplitTextArray;		//�������ꂽ�������i�[����z��

	//�J�E���^
	int	Count = 0;									//�J�E���^
	int	Scene = 0;									//�V�[���J�E���^

	//�s���Ǘ�
	int SerifNo = -1;								//�Z���t�̃i���o�[���i�[(�ŏ��͕K�����Z�����̂ŁA�����l�͕��̐��ɂ��Ă���)

	//�萔
	const int LoadTextLen = 128;					//�ǂݍ��ރe�L�X�g�̕�����
	const int NAME = 0;						//�������ꂽ��������i�[����z��Ɋւ������
	const int TEXT = 1;						//�������ꂽ��������i�[����z��Ɋւ������


	//SceneMax(�萔)�܂Ń��[�h
	while (Scene <= SceneMax)
	{

		//�t�@�C�������擾
	//	sprintf(FileName, "./resource/story/zankyo scene%d.txt", Scene);
		sprintf_s(FileName, "story/��%d.txt",Scene);

		//�t�@�C���I�[�v��
		FileHandle = FileRead_open(FileName);

		//�t�@�C���I�[�܂Ń��[�v
		while (FileRead_eof(FileHandle) == 0) 
		{
			//�t�@�C�������s�擾
			FileRead_gets(TmpBuf, LoadTextLen, FileHandle);

			//�ꕶ���ڂ� '\0' �Ȃ��s�Ɣ��f���X�L�b�v
			if (TmpBuf[0] == '\0') continue;

			//char�^�z���TmpBuf��String�I�u�W�F�N�g��TmpText�ɕϊ�
			TmpText = TmpBuf;

			//TmpText�̈ꕶ���ڂ�'\0'�Ȃ�΋�s�Ɣ��f���X�L�b�v
			if (TmpText[0] == NULL) continue;

			//�S�p����p�X�y�[�X������
			CutSpace(TmpText);

			//TmpText�̈ꕶ���ڂ�'\0'�Ȃ�΋�s�Ɣ��f���X�L�b�v
			if (TmpText[0] == '\0') continue;

			//TmpText��Name��Text�ɕ���
			SplitTextArray = StringSplit(TmpText, ':');

			//�������ꂽ�������Name��Text�ɑ��
			Name[Scene][Count] = SplitTextArray[NAME];
			Text[Scene][Count] = SplitTextArray[TEXT];

			//Name��"�R�����g"�Ȃ�R�����g�Ɣ��f���X�L�b�v
			if (Name[Scene][Count] == "�R�����g") continue;

			//Text��'\0'�Ȃ�O�̃e�L�X�g�̑����Ɣ��f���AName�ɑ����Ƒ�����A
			//Text��Name(��s�S�ē����Ă�)�̓��e���R�s�[ �� �s�����Z
			//����ȊO�Ȃ�Ύ��̃e�L�X�g�Ɣ��f���ASerifNo�����Z���A�s�����Z
			if (Text[Scene][Count] == "\0")
			{
				Text[Scene][Count] = Name[Scene][Count];
				Name[Scene][Count] = "����";
				LineNo[63][1023]++;
			}
			else {
				SerifNo++;
				LineNo[Scene][SerifNo]++;
			}

			//�ő�s�����Z
			LineMax[Scene]++;

			//�J�E���g��i�߂�
			Count++;
		}

		//�V�[���J�E���g��i�߂�
		Scene++;

		//�J�E���g������
		Count = 0;
		SerifNo = -1;

	}

}

/*�����񕪊�*/

std::vector<std::string> TextClass::StringSplit(const std::string& Str, char Sep)
{
	//���낢��錾
	std::vector<std::string> V;
	std::stringstream Ss(Str);
	std::string Buffer;

	const std::string EndOfText = "\0";

	//�����񕪊�
	while (std::getline(Ss, Buffer, Sep))
	{
		V.push_back(Buffer);
	}

	//�I�[���� '\0' ��}��
	V.push_back(EndOfText);

	return V;
}

/*�e�L�X�g����X�y�[�X����菜��*/
int TextClass::CutSpace(std::string& TmpText)
{
	//�ϐ��錾
	int  i = 0;				//�󔒏��������Ɏg���J�E���^
	char TmpStr[3];		   	//�󔒏��������ɂ����ꎞ�ϐ�

	const int BigSpaceSize = 2; //�S�p�X�y�[�X�̃T�C�Y

	//�S�p�󔒂���菜������
	if (TmpText.length() >= BigSpaceSize)
	{
		do
		{
			if (TmpText.length() <= i)
			{
				TmpText[0] = '\0';
				return 0;
			}
			TmpStr[0] = TmpText[i];
			TmpStr[1] = TmpText[i + 1];
			TmpStr[2] = '\0';
			i += 2;
		} while (strcmp(TmpStr, "�@") == 0);
		TmpText = &TmpText[i - 2];
	}

	//���p�X�y�[�X����菜������
	i = 0;
	while (TmpText[i] == ' ')
	{
		//�������𒴂��Ȃ��悤�ȃR�[�f�B���O
		i++;
		if (TmpText.length() <= i)
		{
			TmpText[0] = '\0';
			return 0;
		}
	}
	TmpText = &TmpText[i];

}

void TextClass::Main(UserClass& User) 
{
	//�e�L�X�g�`�F�b�N
	CheckText(User);
	
	//�w�i�`��
	Graph.DrawBack(User);

	//�L�����N�^�`��
	Graph.DrawChar(User);

	//�e�L�X�g�{�b�N�X�`��
	if (WriteMode != NOTWINDOW)
	{
		Graph.DrawWindow();

	}

	CheckCotrolCode(User);


	//�e�L�X�g�`��
	if (WriteMode == NORMAL)
	{
		NormalWrite(User);	//�ʏ�e�L�X�g�`��
	}

	//�e�L�X�g�`��
	if (WriteMode == NORMAL) NormalWrite(User);	//�ʏ�e�L�X�g�`��
	//if (WriteMode == BACKLOG) BackLogMain(User);	//�o�b�N���O
	//if (WriteMode == NOTWINDOW) NotWindow();		//�E�B���h�E��\��
	//if (WriteMode == END) GameEnd(User);		//�Q�[���I��

}

/*���[�h�`�F���W*/
void TextClass::ModeChange(int& ModeFlag, int& ChangeFlag, UserClass& User)
{
	//�C���X�^���X��
	MouseClass Mouse = MouseClass::GetInstance();

	static int Count = 0;

	const int AtherSelect = -1;

	//�^�C�}�[
	static int Timer = 0;
	if (WriteMode != NOTWINDOW) Timer++;

	//�o�b�N���O
//	if (Mouse->GetWheel() > 0 && WriteMode == NORMAL) WriteMode = BACKLOG;

	//�G���f�B���O���[�h��
	if (WriteMode == END) 
	{
		WriteMode = NORMAL;
		ModeFlag = MODE::END;;
	}

	//�^�C�g����ʂ�
	if (WriteMode == TITLE)
	{
		Count++;
		DrawBox(0, 0, SCREEN_SIZE_X, SCREEN_SIZE_Y, GetColor(0, 0, 0), TRUE);
		SetFontSize(100);
		ChangeFont("�l�r ����");
		DrawString(SCREEN_SIZE_X / 3, SCREEN_SIZE_X / 3, "- FIN - ", GetColor(255, 255, 255));
		if (Count > 200) 
		{
			WriteMode = NORMAL;
			ModeFlag = MODE::OTHER;
			User.SetPage(PAGE::P_TITLE);
			Count = 0;
		}

	}
}

void TextClass::CheckText(UserClass& User)
{
	const int AtherSelect = -1;

	//���ڃt���O
	static bool FirstFlag = false;

	//�V�[���̏I���Ȃ�A���̃V�[����(�J�E���g�X�V)
	if (TextCount >= LineMax[SceneCount]) 
	{
		SceneCount++;
		TextCount = 0;
		SerifCount = 0;
	}
}

/*�e�L�X�g�ʏ�`��*/
void TextClass::NormalWrite(UserClass& User)
{
	MouseClass Mouse = MouseClass::GetInstance();

	//�e�L�X�g�`��
	WriteText(User);
}

void TextClass::WriteText(UserClass& User) 
{
	//�ϐ��錾
	static int  WriteCount = 0;					//�������ݎ��J�E���g
	static int  WriteIndex[3] = { 0,0,0 };			//���݉������ڂ�
	static int  WriteX = 0;							//��������X�����W
	static int  WriteY = 0;							//��������Y���W
	static int  OldTextCount;						//�O�̃e�L�X�g�J�E���g���擾
	static int  WriteLine;							//�`�悷��s
	int  Length;									//������
	int  TmpCount = 0;								//�ꎞ�J�E���^
	int  LoopCount = 0;								//���[�v�p�J�E���^
	char WriteText[3];								//�������ݕ���

	//�萔��`	
	const int DrawX = 250;							//�`���w���W						
	const int DrawY = SCREEN_SIZE_Y - SCREEN_SIZE_Y / 3 + 50;	//�`���x���W
	const int TextSpace = 14;							//�����ƕ����̊Ԋu
	const int LineSpace = 40;							//�s�ƍs�̊Ԋu
	const int FontSize = 28;							//�t�H���g�T�C�Y
	int DrawSpeed;										//�����̕`�摬�x


	//�����̕`�摬�x���擾
	if (AutoFlag == 1)
	{
		DrawSpeed = User.GetAutoTextSpeed();
	}
	else			
	{
		DrawSpeed = User.GetTextSpeed();
	}


	//�e�L�X�g���i�񂾂�ϐ�������
	if (TextCount != OldTextCount)
	{
		memset(WriteIndex, 0, sizeof(WriteIndex));
		WriteCount = 0;
		WriteX = 0;
		WriteY = 0;
		WriteLine = 0;
	}
	//�O�̃e�L�X�g�J�E���g���擾(��̏������̂���)
	OldTextCount = TextCount;

	//���ݕ\������Ă��镶���������\������(Line�͍s���������A�ő�s�������[�v����)
	for (int Line = 0; Line < LineNo[SceneCount][SerifCount]; Line++) 
	{

		//�`�悪�������Ă���s�܂ŕ`��
		if (Line <= WriteLine)
		{
			LoopCount = 0;		//���[�v�J�E���^������
			while (LoopCount <= WriteIndex[Line])
			{
				//�������݉\�������ȉ��Ȃ�
				WriteX = LoopCount * TextSpace;	//�`��X���W�X�V
				WriteText[0] = Text[SceneCount][TextCount + Line][LoopCount];//1byte�ڑ��
				WriteText[1] = Text[SceneCount][TextCount + Line][LoopCount + 1];//2byte�ڑ��
				WriteText[2] = '\0';
				LoopCount += 2;		//�ꕶ�����J�E���g�A�b�v
			}

			Length = Text[SceneCount][TextCount + Line].length() - 2;

			//������̏I�[�Ȃ�΁A�������ݍs�����X�V
			if (Length <= WriteIndex[Line])
			{
				WriteLine = Line + 1;//������̏I�[�Ȃ�΁A�������ݍs�����X�V
			}
			else if (WriteCount % DrawSpeed == 0)
			{
				WriteIndex[Line] += 2;
			}


			//�������S���`��I���t���O�������Ă���Ȃ��,
			//�`��J�E���g���ő�ɂ���(����������)
			if (TextGraphEndFlag == 1)
			{
				WriteIndex[Line] = Length;
			}
		}
	}

	//�`��^�C�~���O���@�p
	WriteCount++;

	//�e�L�X�g���S�ĕ`�悳�ꂽ��A�S���`��I���t���O�𗧂Ă�
	if (WriteLine == LineNo[SceneCount][SerifCount])
	{
		TextGraphEndFlag = 1;
	}

}

/*���̍s�֐i�߂�*/
void TextClass::PutNextLine(UserClass& User)
{
	//�C���X�^���X�擾
	KeyClass* Key = KeyClass::GetInstance();
	MouseClass Mouse = MouseClass::GetInstance();

	//�G���^�[��������āA�e�L�X�g���\�����I����āA���j���[��I�����Ă��Ȃ��Ȃ�A�J�E���g��i�߂�
	if ((Key->GetState(KEY_INPUT_RETURN) == 1 || Mouse.GetState(MOUSE::_LEFT) == 1))
	{
		//�e�L�X�g�\�������t���O�������Ă���΃J�E���g��i�߂�
		if (TextGraphEndFlag == 1)
		{

			//�e�L�X�g�J�E���g�����݂̍s�����i�߂�
			//TextCount        += RowNo;
			TextCount += LineNo[SceneCount][SerifCount];

			//Graph.Draw();

			//�Z���t�J�E���g��i�߂�
			SerifCount++;

			//�e�L�X�g�\�������t���O��܂�
			TextGraphEndFlag = 0;

		}
		else
		{
			TextGraphEndFlag = 1;
		}
	}
}

/*�E�B���h�E��\��*/
void TextClass::NotWindow() 
{
	auto Mouse = MouseClass::GetInstance();

	//�^�C�}�[
	static int Timer = 0;

	Timer++;

	if (Mouse.GetState(MOUSE::_RIGHT) > 0 && Timer > 20)
	{
		WriteMode = NORMAL;
		Timer = 0;
	}
}

/*����R�[�h�`�F�b�N*/
void TextClass::CheckCotrolCode(UserClass& User) 
{
	//�e��R�[�h�󂯎��ϐ�
	std::string EventCode;
	std::string CharacterCode;
	std::string BackCode;

	bool EventFlag = FALSE;

	do {

		EventFlag = FALSE;

		//�w�i�摜����
		if (Name[SceneCount][TextCount] == "�w�i")
		{
			//�w�i�R�[�h�󂯎��
			BackCode = Text[SceneCount][TextCount];
			if (BackCode == "����")
			{
				User.SetBackCode(GAME_BACK::KYOUSITU);
			}
			if (BackCode == "�w�O")
			{
				User.SetBackCode(GAME_BACK::EKIMAE);
			}
			if (BackCode == "�ʊw")
			{
				User.SetBackCode(GAME_BACK::TUUGAKU);
			}
			TextCount++;
			SerifCount++;
			EventFlag = TRUE;
		}

		//�L�����N�^�摜����
		if (Name[SceneCount][TextCount] == "�L����") 
		{
			//�L�����N�^�R�[�h�󂯎��
			CharacterCode = Text[SceneCount][TextCount];
			if (CharacterCode == "�y") User.SetCharacterCode(GAME_CHAR::HARUKA);
			if (CharacterCode == "�ȂȂ�") User.SetCharacterCode(GAME_CHAR::NANASE);
			if (CharacterCode == "��\��")	User.SetCharacterCode(GAME_CHAR::NOT);
			TextCount++;
			SerifCount++;
			EventFlag = TRUE;
		}

		//�G���h
		if (Name[SceneCount][TextCount] == "�G���h") 
		{
			TextCount++;
			SerifCount++;
			WriteMode = END;
		}

	} while (EventFlag == TRUE);
}




