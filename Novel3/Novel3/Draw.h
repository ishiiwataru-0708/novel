#pragma once
#include<vector>
#include "User.h"
#include <string>
#include"comon.h"
#include"anime.h"

//画像描画座標で使う
namespace GRAPH 
{
	enum { X, Y };
}

//ゲーム背景コード
namespace GAME_BACK {
	enum { EKIMAE, TUUGAKU,KYOUSITU, BLACK };
}

//ゲームキャラクターコード
namespace GAME_CHAR {
	enum { HARUKA,NANASE, NOT };
}

/*二次元配列のvectorを定義*/
using std::vector;
typedef vector< vector<int> > Dvector_i;
typedef vector< vector<std::string> > Dvector_s;


struct ConfigArg_rec
{
	//パラメータ
	int			SetNo;	//設定されている値
};

/*コンフィグデータ構造体*/
struct ConfigData_rec
{
	//テキスト
	int  TextSpeed;
};

class GraphClass
{
protected:
	virtual void Load() = 0;		//画像ロード
	virtual void SetPoint() = 0;	//描画座標セット

public:
	virtual void Draw() = 0;		//画像描画
	
	AnimeClass Anime;			//アニメインスタンス(集約-分解構造)
};

class TitleGraphClass : public GraphClass
{
private:
	//画像ハンドル
	int  TitleBackHandle;	//背景画像

	//描画座標
	int  TitleBackPoint[2];	//背景画像描画座標
	int fontSize1;	// ﾌｫﾝﾄｻｲｽﾞ
	int fontSize2;	// ﾌｫﾝﾄｻｲｽﾞ


	//メソッド
	void Load();			//画像ロード
	void SetPoint();		//描画座標セット

public:
	TitleGraphClass();		//初期化
	void Draw();			//画像描画
};


/*----------------------------
 | テキストグラフィッククラス |
  ----------------------------*/
class TextGraphClass : public GraphClass 
{
private:
	//画像ハンドル
	vector<int> GameBackHandle;		//背景画像
	int CharacterHandle;			//キャラクタ画像
	int CharacterHandle2;			//キャラクタ画像
	int TextBoxHandle;				//テキストボックス

	//描画座標
	int GameBackPoint[3];			//背景画像
	int CharacterPoint[2];			//キャラクタ画像
	int TextBoxPoint[2];			//テキストボックス

	//メソッド
	void Load();					//画像ロード
	void SetPoint();				//画像座標セット


public:
	TextGraphClass();				//初期化
	void Draw();					//一応ね、あとで消したい
	void DrawBack(UserClass& User);	//背景描画
	void DrawChar(UserClass& User);	//キャラクタ描画
	void DrawWindow();				//テキストウィンドウ描画

};

class ConfigGraphClass : public GraphClass 
{
private:
	//定数
	enum { TEXTSPEED };

	struct ConfigData_rec ConfigData;				//コンフィグコピー情報
	struct ConfigArg_rec  ConfigParam[1];			//パラメータ

	//メソッド
	void Load();
	void SetPoint();

public:
	//ConfigGraphClass();								//初期化

	void SetMenuParam();							//メニューパラメータセット


};





