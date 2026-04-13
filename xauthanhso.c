#include <stdio.h>

int main() {
	char s[] = "125T";
	/********************
	int a = 0;
	int i = 0;
	while( char c = s[i++]){
		if( c < '0' || c > '9') break;
		a = a*10 + (c-'0');
	}
	*********/
	int a = 0;
	__asm {
		XOR EAX, EAX; a = 0
		XOR ESI, ESI; i = 0
		XOR ECX, ECX;
		WHILE:
			MOV CL, s[ESI]; c = s[i]
			TEST CL, CL
			JZ ENDWHILE
			CMP CL, '0'
			JB ENDWHILE
			CMP CL, '9'
			JA ENDWHILE

			SHL EAX,1
			MOV EBX,EAX
			SHL EAX,2
			ADD EAX,EBX

			AND CL,15

			ADD EAX,ECX
			INC ESI
			JMP WHILE
		ENDWHILE:
			MOV a,EAX
	}
	printf("%d", a);
}
