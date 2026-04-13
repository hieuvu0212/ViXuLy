// Luyentap2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdint.h>
int main()
{
    int16_t a = 30;
    int16_t b = 72;
    //while(b!=0){
    //int r = a%b;
    //a=b;
    //b=r;
    //}
    __asm {
        MOV AX,a
        MOV BX,b
        WHILE:
            TEST BX, BX; <=> CMP BX,0 : b != 0
            JZ ENDWHILE; <=> JE b=0 end
            XOR DX,DX
            DIV BX
            MOV AX,BX
            MOV BX,DX
            JMP WHILE
        ENDWHILE:
            MOV a,AX
    }
    printf("%d", a);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
