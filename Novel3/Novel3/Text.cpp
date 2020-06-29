#include"DxLib.h"
#include"Text.h"
#include"Key.h"
#include "User.h"
#include"Page.h"

TextClass::TextClass()
{
	InitVar();		//変数初期化
	LoadStory();	//ストーリ読み込み
}

/*変数初期化*/
void TextClass::InitVar() 
{
	//メンバ変数初期化;
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

/*ストーリーロード*/
void TextClass::LoadStory()
{
	//真の変数
	int							FileHandle;			//ファイルハンドル
	char						TmpBuf[128];		//テキスト取得用一時変数
	char						FileName[64];		//ファイル名格納
	std::string					TmpText;			//テキスト取得後操作用一時オブジェクト 
	std::vector<std::string>	SplitTextArray;		//分割された文字を格納する配列

	//カウンタ
	int	Count = 0;									//カウンタ
	int	Scene = 0;									//シーンカウンタ

	//行数管理
	int SerifNo = -1;								//セリフのナンバーを格納(最初は必ず加算されるので、初期値は負の数にしておく)

	//定数
	const int LoadTextLen = 128;					//読み込むテキストの文字数
	const int NAME = 0;						//分割された文字列を格納する配列に関するもの
	const int TEXT = 1;						//分割された文字列を格納する配列に関するもの


	//SceneMax(定数)までロード
	while (Scene <= SceneMax)
	{

		//ファイル名を取得
	//	sprintf(FileName, "./resource/story/zankyo scene%d.txt", Scene);
		sprintf_s(FileName, "story/仮%d.txt",Scene);

		//ファイルオープン
		FileHandle = FileRead_open(FileName);

		//ファイル終端までループ
		while (FileRead_eof(FileHandle) == 0) 
		{
			//ファイルから一行取得
			FileRead_gets(TmpBuf, LoadTextLen, FileHandle);

			//一文字目が '\0' なら空行と判断しスキップ
			if (TmpBuf[0] == '\0') continue;

			//char型配列のTmpBufをStringオブジェクトのTmpTextに変換
			TmpText = TmpBuf;

			//TmpTextの一文字目が'\0'ならば空行と判断しスキップ
			if (TmpText[0] == NULL) continue;

			//全角･半角スペースを除去
			CutSpace(TmpText);

			//TmpTextの一文字目が'\0'ならば空行と判断しスキップ
			if (TmpText[0] == '\0') continue;

			//TmpTextをNameとTextに分割
			SplitTextArray = StringSplit(TmpText, ':');

			//分割された文字列をNameとTextに代入
			Name[Scene][Count] = SplitTextArray[NAME];
			Text[Scene][Count] = SplitTextArray[TEXT];

			//Nameが"コメント"ならコメントと判断しスキップ
			if (Name[Scene][Count] == "コメント") continue;

			//Textが'\0'なら前のテキストの続きと判断し、Nameに続きと代入し、
			//TextにName(一行全て入ってる)の内容をコピー ＆ 行数加算
			//それ以外ならば次のテキストと判断し、SerifNoを加算し、行数加算
			if (Text[Scene][Count] == "\0")
			{
				Text[Scene][Count] = Name[Scene][Count];
				Name[Scene][Count] = "続き";
				LineNo[63][1023]++;
			}
			else {
				SerifNo++;
				LineNo[Scene][SerifNo]++;
			}

			//最大行数加算
			LineMax[Scene]++;

			//カウントを進める
			Count++;
		}

		//シーンカウントを進める
		Scene++;

		//カウント初期化
		Count = 0;
		SerifNo = -1;

	}

}

/*文字列分割*/

std::vector<std::string> TextClass::StringSplit(const std::string& Str, char Sep)
{
	//いろいろ宣言
	std::vector<std::string> V;
	std::stringstream Ss(Str);
	std::string Buffer;

	const std::string EndOfText = "\0";

	//文字列分割
	while (std::getline(Ss, Buffer, Sep))
	{
		V.push_back(Buffer);
	}

	//終端文字 '\0' を挿入
	V.push_back(EndOfText);

	return V;
}

/*テキストからスペースを取り除く*/
int TextClass::CutSpace(std::string& TmpText)
{
	//変数宣言
	int  i = 0;				//空白除去処理に使うカウンタ
	char TmpStr[3];		   	//空白除去処理につかう一時変数

	const int BigSpaceSize = 2; //全角スペースのサイズ

	//全角空白を取り除く処理
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
		} while (strcmp(TmpStr, "　") == 0);
		TmpText = &TmpText[i - 2];
	}

	//半角スペースを取り除く処理
	i = 0;
	while (TmpText[i] == ' ')
	{
		//文字数を超えないようなコーディング
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
	//テキストチェック
	CheckText(User);
	
	//背景描画
	Graph.DrawBack(User);

	//キャラクタ描画
	Graph.DrawChar(User);

	//テキストボックス描画
	if (WriteMode != NOTWINDOW)
	{
		Graph.DrawWindow();

	}

	CheckCotrolCode(User);


	//テキスト描画
	if (WriteMode == NORMAL)
	{
		NormalWrite(User);	//通常テキスト描画
	}

	//テキスト描画
	if (WriteMode == NORMAL) NormalWrite(User);	//通常テキスト描画
	//if (WriteMode == BACKLOG) BackLogMain(User);	//バックログ
	//if (WriteMode == NOTWINDOW) NotWindow();		//ウィンドウ非表示
	//if (WriteMode == END) GameEnd(User);		//ゲーム終了

}

/*モードチェンジ*/
void TextClass::ModeChange(int& ModeFlag, int& ChangeFlag, UserClass& User)
{
	//インスタンス化
	MouseClass Mouse = MouseClass::GetInstance();

	static int Count = 0;

	const int AtherSelect = -1;

	//タイマー
	static int Timer = 0;
	if (WriteMode != NOTWINDOW) Timer++;

	//バックログ
//	if (Mouse->GetWheel() > 0 && WriteMode == NORMAL) WriteMode = BACKLOG;

	//エンディングモードへ
	if (WriteMode == END) 
	{
		WriteMode = NORMAL;
		ModeFlag = MODE::END;;
	}

	//タイトル画面へ
	if (WriteMode == TITLE)
	{
		Count++;
		DrawBox(0, 0, SCREEN_SIZE_X, SCREEN_SIZE_Y, GetColor(0, 0, 0), TRUE);
		SetFontSize(100);
		ChangeFont("ＭＳ 明朝");
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

	//一回目フラグ
	static bool FirstFlag = false;

	//シーンの終わりなら、次のシーンへ(カウント更新)
	if (TextCount >= LineMax[SceneCount]) 
	{
		SceneCount++;
		TextCount = 0;
		SerifCount = 0;
	}
}

/*テキスト通常描画*/
void TextClass::NormalWrite(UserClass& User)
{
	MouseClass Mouse = MouseClass::GetInstance();

	//テキスト描画
	WriteText(User);
}

void TextClass::WriteText(UserClass& User) 
{
	//変数宣言
	static int  WriteCount = 0;					//書き込み時カウント
	static int  WriteIndex[3] = { 0,0,0 };			//現在何文字目か
	static int  WriteX = 0;							//書き込みX軸座標
	static int  WriteY = 0;							//書き込みY座標
	static int  OldTextCount;						//前のテキストカウントを取得
	static int  WriteLine;							//描画する行
	int  Length;									//文字数
	int  TmpCount = 0;								//一時カウンタ
	int  LoopCount = 0;								//ループ用カウンタ
	char WriteText[3];								//書き込み文字

	//定数定義	
	const int DrawX = 250;							//描画基準Ｘ座標						
	const int DrawY = SCREEN_SIZE_Y - SCREEN_SIZE_Y / 3 + 50;	//描画基準Ｙ座標
	const int TextSpace = 14;							//文字と文字の間隔
	const int LineSpace = 40;							//行と行の間隔
	const int FontSize = 28;							//フォントサイズ
	int DrawSpeed;										//文字の描画速度


	//文字の描画速度を取得
	if (AutoFlag == 1)
	{
		DrawSpeed = User.GetAutoTextSpeed();
	}
	else			
	{
		DrawSpeed = User.GetTextSpeed();
	}


	//テキストが進んだら変数初期化
	if (TextCount != OldTextCount)
	{
		memset(WriteIndex, 0, sizeof(WriteIndex));
		WriteCount = 0;
		WriteX = 0;
		WriteY = 0;
		WriteLine = 0;
	}
	//前のテキストカウントを取得(上の初期化のため)
	OldTextCount = TextCount;

	//現在表示されている文字数だけ表示する(Lineは行数を示し、最大行数分ループする)
	for (int Line = 0; Line < LineNo[SceneCount][SerifCount]; Line++) 
	{

		//描画が完了している行まで描画
		if (Line <= WriteLine)
		{
			LoopCount = 0;		//ループカウンタ初期化
			while (LoopCount <= WriteIndex[Line])
			{
				//書き込み可能文字数以下なら
				WriteX = LoopCount * TextSpace;	//描画X座標更新
				WriteText[0] = Text[SceneCount][TextCount + Line][LoopCount];//1byte目代入
				WriteText[1] = Text[SceneCount][TextCount + Line][LoopCount + 1];//2byte目代入
				WriteText[2] = '\0';
				LoopCount += 2;		//一文字分カウントアップ
			}

			Length = Text[SceneCount][TextCount + Line].length() - 2;

			//文字列の終端ならば、書き込み行数を更新
			if (Length <= WriteIndex[Line])
			{
				WriteLine = Line + 1;//文字列の終端ならば、書き込み行数を更新
			}
			else if (WriteCount % DrawSpeed == 0)
			{
				WriteIndex[Line] += 2;
			}


			//もしも全文描画終了フラグが立っているならば,
			//描画カウントを最大にする(文字数を代入)
			if (TextGraphEndFlag == 1)
			{
				WriteIndex[Line] = Length;
			}
		}
	}

	//描画タイミング動機用
	WriteCount++;

	//テキストが全て描画されたら、全文描画終了フラグを立てる
	if (WriteLine == LineNo[SceneCount][SerifCount])
	{
		TextGraphEndFlag = 1;
	}

}

/*次の行へ進める*/
void TextClass::PutNextLine(UserClass& User)
{
	//インスタンス取得
	KeyClass* Key = KeyClass::GetInstance();
	MouseClass Mouse = MouseClass::GetInstance();

	//エンターが押されて、テキストが表示し終わって、メニューを選択していないなら、カウントを進める
	if ((Key->GetState(KEY_INPUT_RETURN) == 1 || Mouse.GetState(MOUSE::_LEFT) == 1))
	{
		//テキスト表示完了フラグが立っていればカウントを進める
		if (TextGraphEndFlag == 1)
		{

			//テキストカウントを現在の行数分進める
			//TextCount        += RowNo;
			TextCount += LineNo[SceneCount][SerifCount];

			//Graph.Draw();

			//セリフカウントを進める
			SerifCount++;

			//テキスト表示完了フラグを折る
			TextGraphEndFlag = 0;

		}
		else
		{
			TextGraphEndFlag = 1;
		}
	}
}

/*ウィンドウ非表示*/
void TextClass::NotWindow() 
{
	auto Mouse = MouseClass::GetInstance();

	//タイマー
	static int Timer = 0;

	Timer++;

	if (Mouse.GetState(MOUSE::_RIGHT) > 0 && Timer > 20)
	{
		WriteMode = NORMAL;
		Timer = 0;
	}
}

/*制御コードチェック*/
void TextClass::CheckCotrolCode(UserClass& User) 
{
	//各種コード受け取り変数
	std::string EventCode;
	std::string CharacterCode;
	std::string BackCode;

	bool EventFlag = FALSE;

	do {

		EventFlag = FALSE;

		//背景画像制御
		if (Name[SceneCount][TextCount] == "背景")
		{
			//背景コード受け取り
			BackCode = Text[SceneCount][TextCount];
			if (BackCode == "教室")
			{
				User.SetBackCode(GAME_BACK::KYOUSITU);
			}
			if (BackCode == "駅前")
			{
				User.SetBackCode(GAME_BACK::EKIMAE);
			}
			if (BackCode == "通学")
			{
				User.SetBackCode(GAME_BACK::TUUGAKU);
			}
			TextCount++;
			SerifCount++;
			EventFlag = TRUE;
		}

		//キャラクタ画像制御
		if (Name[SceneCount][TextCount] == "キャラ") 
		{
			//キャラクタコード受け取り
			CharacterCode = Text[SceneCount][TextCount];
			if (CharacterCode == "遥") User.SetCharacterCode(GAME_CHAR::HARUKA);
			if (CharacterCode == "ななせ") User.SetCharacterCode(GAME_CHAR::NANASE);
			if (CharacterCode == "非表示")	User.SetCharacterCode(GAME_CHAR::NOT);
			TextCount++;
			SerifCount++;
			EventFlag = TRUE;
		}

		//エンド
		if (Name[SceneCount][TextCount] == "エンド") 
		{
			TextCount++;
			SerifCount++;
			WriteMode = END;
		}

	} while (EventFlag == TRUE);
}




