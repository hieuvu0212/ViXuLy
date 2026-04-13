#include <stdio.h>
#include <stdint.h>
int main()
{
	char s[] = "ky thuat VXL";
	//char c; // AL
	//int i = -1;
	//while (c = s[++i]) {
	//	if (c < 'a' || c > 'z') continue;
	//	s[i] = c - 32;
	//}
	//printf("%s", s);
	/*****
	__asm{
		XOR ESI,ESI; i = 0
		DEC ESI; i = -1
		WHILE:
		INC ESI;++1
		MOV AL, [ESI + s]; c = s[i] tuong doi chi so
		TEST Al, AL
		JZ ENDWHILE; c = 0 endwhile

		CMP AL, 'a'
		JB WHILE; c < 'a'

		CMP AL, 'z'
		JA WHILE; c > 'z'

		SUB AL,32
		MOV s[ESI],AL
		JMP WHILE
		ENDWHILE:
	}
	/****/

	//char* p = s-1;
	//while (char c = *(++p)) {
	//	if (c < 'a' || c>'z') {
	//		continue;
	//	}
	//	*p = c - 32;
	//}
	__asm {
		LEA ESI, s;p = s-1
		DEC ESI

		WHILE:
		INC ESI; ++p
			MOV AL, [ESI];c = *p
			TEST AL, AL
			JZ ENDWHILE; c = 0 end
			CMP AL, 'a'
			JB WHILE
			CMP AL, 'z'
			JA WHILE
			SUB AL, 32;*p = c -32
			MOV [ESI],AL
			JMP WHILE
		ENDWHILE:
	}
	printf("%s", s);
}
