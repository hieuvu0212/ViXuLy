#include <stdio.h>
int main() {
	int a = 25;
	char s[100];
	/***************
	int i = 0;
	while (a != 0) {
		 s[i++] = a % 2 +'0';
		 a = a / 2;
	}
	while (i--) printf("%c", s[i]);
	*********/
	__asm {
		XOR ESI, ESI; i =0
		WHILE:
			MOV BL , s[ESI]

	}
}
