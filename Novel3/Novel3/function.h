#pragma once


/*メインループで実行する処理*/
int ProcessLoop();

/*影付きテキスト描画*/
void DrawStringShadow(int DrawX, int DrawY, std::string DrawText, 
	unsigned int TextColor, unsigned int ShadowColor);