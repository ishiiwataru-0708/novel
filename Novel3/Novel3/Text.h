#pragma once
#include <string>
#include "User.h"
#include<vector>
#include"Draw.h"
#include<sstream>

/*二次元配列のvectorを定義*/
using std::vector;
typedef vector< vector<int> > Dvector_i;
typedef vector< vector<std::string> > Dvector_;

#define EXAMPLE_MACRO_NAME
#define _CRT_SECURE_NO_WARNINGS

class KeyClass;
class TextClass
{
private:
	//定数
	enum { SceneMax = 8, RowMax = 1024 };						//シーン最大数、行数最大
	enum { NORMAL, NOTWINDOW, END, TITLE }; //描画モード定数

	int  WriteMode;									    //描画モード格納

	short int  TextCount;								//テキストカウンタ
	short int  SceneCount;								//シーンカウンタ
	short int  SerifCount;								//セリフカウンタ

	int  TextGraphEndFlag;								//テキスト全文描画完了フラグ
	int  AutoFlag;		//オートフラグ

	int LineNo[64][1024];								//各セリフの行数を取得
	int LineMax[100];									//1シーンごとのテキストの総行数
	std::string Name[64][1024];							//キャラネーム変数
	std::vector<std::vector<std::string>> Text;							//セリフテキスト変数
	bool oldLeftMouse;
	bool FadeFlag;




public:
	//初期化･チェック
	TextClass();										//初期化
	void InitVar();										//変数初期化
	void LoadStory();									//ストーリーロード
	int  CutSpace(std::string& TmpText);				//テキストから全角空白を取り除く
	void CheckText(UserClass& User);					//テキストチェック
	std::vector<std::string> StringSplit(const std::string& Str, char Sep);


	//メイン関数
	void Main(int& ChangeFlag, UserClass& User);		//メイン関数
	void ModeChange(int& ModeFlag, int& ChangeFlag, UserClass& User);

	//通常描画関連
	void NormalWrite(UserClass& User);					//テキスト通常描画
	void WriteText(UserClass& User);					//テキスト描画

	//次の行へ進める
	void PutNextLine(UserClass& User);					//次の行へ進める	

	void NotWindow();

	//制御コードチェック
	void CheckCotrolCode(UserClass& User);


	//ゲームグラフィック
	TextGraphClass Graph;

};

