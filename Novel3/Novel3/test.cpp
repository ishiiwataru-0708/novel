#include <stdio.h>
#include <string.h>
#include"test.h"

 //�\��������������
 char g_message[256] = " HelloWorld ";

 // m e s s a g e�Ŏw�肵�����͂� start �� �� �u �� �� len �� �� �� �\ �� �� ��
 void writeSubstring(char* message, int start, int len)
 {
	 int i;
	 //������
		 int maxLen = strlen(message);
	
		 // s t a r t �� �� �u �� �\ �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��
		 if (start >= maxLen) {
		 return;
		
	}
	
		 //�w�肵���ʒu���� l e n �� �� �� �\ �� �� ��
		 for (i = 0; i < len && message[start + i] != 0; i++)
		 {
		 printf("%c", message[start + i]);
		
	}
	 printf("\n");

	 }

 int main()
 {
	 // g _ m e s s a g e��\������
		writeSubstring(g_message, 0, strlen(g_message));
	 // g_message 2�� �� ��( g_message [1] )�� ��5 �� �� �� �\ �� �� ��
	    writeSubstring(g_message, 1, 5);
	 // g_message 6�� �� ��( g_message [5] )�� ��10 �� �� �� �\ �� �� ��
		 //10 �� �� �� �\ �� �� �� �� �� �� �� �C �� �� �� �� �� �� �� �� �\ ��
	    writeSubstring(g_message, 5, 10);
	 // g_message 20 �� �� �� �� �� �\ �� �i �� �� �� �\ �� �� �� �� �� �j
	    writeSubstring(g_message, 20, 10);
 }