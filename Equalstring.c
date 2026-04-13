#include <stdio.h>

int Equals(const char* a, const char* b, int n) {
	int check = 1;
	//int i = 0;
	//while (i < n) {
	//	if (a[i] != b[i]) {
	//		check = 0;
	//		break;
	//	}
	//	i++;
	//}
	__asm {
		XOR ESI,ESI
		MOV EDI , [EBP +8]
		MOV EDX , [EBP + 12]
		
		WHILE:
			CMP ESI, [EBP +16]
			JE ENDWHILE
			MOV AL, [EDI + ESI]
			MOV BL, [EDX + ESI]
			
			CMP AL,BL
			JNE Not_Equal
			

			INC ESI
			JMP WHILE
		Not_Equal:
			MOV check ,0
			JMP ENDWHILE
		ENDWHILE:	
	}


	return check;
}

int main() {
	const char a[] = "2345a";
	const char b[] =  "2345a";
	printf("Equal is 1 and Not equal is 0 : %d", Equals(a, b, 3));
}
