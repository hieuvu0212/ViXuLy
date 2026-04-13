#include <stdio.h>
int sum(int* A, int n) {
	/*****
	int i = 0;
	int sum = 0;
	while ( n!=0 ) {
		sum += *(A + i);
		i++;
		n--;
	}
	*****/
	int result;
	__asm {
		
		MOV ESI , A
		
		MOV ECX , n
		
		XOR EBX , EBX
		WHILE:
			CMP ECX , 0
			JE ENDWHILE

			MOV EAX , [ESI]
			ADD EBX , EAX

			ADD ESI , 4
			DEC ECX
			JMP WHILE
		ENDWHILE:
		MOV result, EBX
		
	}
	return result;
}
int main() {
	int A[] = { 1,2,3,4,5,6 };
	printf("%d", sum(A, 6));

}
