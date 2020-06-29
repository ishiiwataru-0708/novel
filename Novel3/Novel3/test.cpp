#include <stdio.h>
#include <string.h>
#include"test.h"

 //表示したい文字列
 char g_message[256] = " HelloWorld ";

 // m e s s a g eで指定した文章を start の 位 置 か ら len 文 字 分 表 示 す る
 void writeSubstring(char* message, int start, int len)
 {
	 int i;
	 //文字数
		 int maxLen = strlen(message);
	
		 // s t a r t の 位 置 が 表 示 し た い 最 大 文 字 数 よ り 大 き い 場 合
		 if (start >= maxLen) {
		 return;
		
	}
	
		 //指定した位置から l e n 文 字 分 表 示 す る
		 for (i = 0; i < len && message[start + i] != 0; i++)
		 {
		 printf("%c", message[start + i]);
		
	}
	 printf("\n");

	 }

 int main()
 {
	 // g _ m e s s a g eを表示する
		writeSubstring(g_message, 0, strlen(g_message));
	 // g_message 2文 字 目( g_message [1] )か ら5 文 字 分 表 示 す る
	    writeSubstring(g_message, 1, 5);
	 // g_message 6文 字 目( g_message [5] )か ら10 文 字 分 表 示 す る
		 //10 文 字 は 表 示 で き な い の で ， 文 字 列 の 最 後 ま で 表 示
	    writeSubstring(g_message, 5, 10);
	 // g_message 20 文 字 目 か ら 表 示 （ な に も 表 示 さ れ な い ）
	    writeSubstring(g_message, 20, 10);
 }