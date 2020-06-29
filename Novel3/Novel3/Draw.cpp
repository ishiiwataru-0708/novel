#include<DxLib.h>
#include"comon.h"
#include"Draw.h"

/*������*/

TitleGraphClass::TitleGraphClass()
{
	Load();
	SetPoint();
	
}

/*�摜���[�h*/
void TitleGraphClass::Load()
{
	TitleBackHandle = LoadGraph("image/�ʊw�H(��).jpg");

}

/*�`����W�Z�b�g*/
void TitleGraphClass::SetPoint()
{
	TitleBackPoint[GRAPH::X] = 0;
	TitleBackPoint[GRAPH::Y] = 0;
}

/*�摜�`��*/
void TitleGraphClass::Draw()
{

	DrawGraph(TitleBackPoint[GRAPH::X],
		TitleBackPoint[GRAPH::Y], TitleBackHandle, true);

}


/*������*/
TextGraphClass::TextGraphClass()
{
	Load();			//�摜�ǂݍ���
	SetPoint();		//�`����W�Z�b�g
}

/*�摜���[�h*/
void TextGraphClass::Load()
{
	//�w�i���[�h
	GameBackHandle.push_back(LoadGraph("image/�w�O(��).jpg"));
	GameBackHandle.push_back(LoadGraph("image/����(��).jpg"));
	GameBackHandle.push_back(LoadGraph("image/�ʊw�H(��).jpg"));

	//�L�����N�^�`��
	CharacterHandle = LoadGraph("image/���їy/�m�[�}������.png");
	CharacterHandle2 = LoadGraph("image/�؊ԂȂȂ�/�m�[�}������.png");

	//�e�L�X�g�{�b�N�X
	TextBoxHandle = LoadGraph("image/���b�Z�[�W�E�C���h�E/box_blue_name.png");

}

/*�`����W�Z�b�g*/
void TextGraphClass::SetPoint() 
{
	//�w�i
	GameBackPoint[GRAPH::X] = 0;
	GameBackPoint[GRAPH::Y] = 0;

	//�L�����N�^�`����W
	CharacterPoint[GRAPH::X] = SCREEN_SIZE_X / 3;
	CharacterPoint[GRAPH::Y] = 0;

	//�e�L�X�g�{�b�N�X
	TextBoxPoint[GRAPH::X] = 0;
	TextBoxPoint[GRAPH::Y] = SCREEN_SIZE_Y - SCREEN_SIZE_Y / 3;

}

/*�w�i�`��*/
void TextGraphClass::DrawBack(UserClass& User)
{
	//�w�i�`��
	switch (User.GetBackCode()) 
	{
	case GAME_BACK::TUUGAKU:
		DrawGraph(GameBackPoint[GRAPH::X], GameBackPoint[GRAPH::Y], 
			GameBackHandle[GAME_BACK::TUUGAKU], true);
		break;

	case GAME_BACK::EKIMAE:
		DrawGraph(GameBackPoint[GRAPH::X], GameBackPoint[GRAPH::Y], 
			GameBackHandle[GAME_BACK::EKIMAE], true);
		break;

	case GAME_BACK::KYOUSITU:
		DrawGraph(GameBackPoint[GRAPH::X], GameBackPoint[GRAPH::Y],
			GameBackHandle[GAME_BACK::KYOUSITU], true);
		break;
	}
}

/*�L�����N�^�`��*/
void TextGraphClass::DrawChar(UserClass& User)
{
	//�L�����N�^�`��
	switch (User.GetCharacterCode()) 
	{
	case GAME_CHAR::HARUKA:
		DrawGraph(CharacterPoint[GRAPH::X], CharacterPoint[GRAPH::Y],
			CharacterHandle, TRUE);
		break;

	case GAME_CHAR::NANASE:
		DrawGraph(CharacterPoint[GRAPH::X], CharacterPoint[GRAPH::Y],
			CharacterHandle2, TRUE);
		break;

	case GAME_CHAR::NOT:
		break;
	}
}

/*�e�L�X�g�E�B���h�E�`��*/
void TextGraphClass::DrawWindow() 
{
	//�e�L�X�g�{�b�N�X�`��
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	DrawGraph(TextBoxPoint[GRAPH::X],
		TextBoxPoint[GRAPH::Y], TextBoxHandle, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void ConfigGraphClass::SetPoint()
{

}

/*�p�����[�^���Z�b�g*/
void ConfigGraphClass::SetMenuParam()
{

	/*�R���t�B�O���j���[�̃p�����[�^�Z�b�g*/

	ConfigParam[TEXTSPEED].SetNo = ConfigData.TextSpeed;
}



/*�f�o�b�O�p*/
void TextGraphClass::Draw() {}
