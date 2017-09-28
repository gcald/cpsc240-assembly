//Assignment 05 Problem #2 George Calderon
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::hex;
using std::uppercase;

int familyID1 = 0xBEEF, familyID2 = 0xFADE, familyID3 = 0xCABE, //Given 4 hexadecimal numbers
	currentNum, loopCounter = 0, counter = 0, sum = 0; //Variable used for asm loop

void printValid() {
	cout << hex << uppercase << currentNum << " is a valid ID for the family." << endl;
}

void printInvalid() {
	cout << hex << uppercase << currentNum << " is not a valid ID for the family." << endl;
}

int main() {
	
	_asm {
	preLoop: //Resets the sum and loopCounter while also loading up the family id's into currentNumber and ebx register.
		mov  sum, 0;
		mov  loopCounter, 0;
		cmp  counter, 0;
		je   id1;
		cmp  counter, 1;
		je   id2;
		cmp  counter, 2;
		je   id3;
		cmp  counter, 3;
		je   done;
	hexLoop: //This will check every 4 bits and add that number into sum. After that, it will shift 4 bits until all 4 digits are added.
		cmp  loopCounter, 4;
		je   checkNum;
		mov  eax, 1111b;
		and  eax, currentNum;
		shr  currentNum, 4;
		add  sum, eax;
		inc  loopCounter;
		jmp  hexLoop;
	checkNum: //This will check the final sum of all 4 digits. If the first bit is 1, it will jump to odd, otherwise it jumps to even.
		mov  eax, 1b;
		and  eax, sum;
		cmp  eax, 1;
		je   _odd;
		jmp  _even;
	_even: //Moves the untouched hexadecimal number into currentNum to be printed as valid before it loops again to make sure all ID's have been added.
		mov  currentNum, ebx;
		call printValid;
		inc  counter;
		jmp  preLoop;
	_odd: //Moves the untouched hexadecimal number into currentNum to be printed as invalid before it loops again to make sure all ID's have been added.
		mov  currentNum, ebx;
		call printInvalid;
		inc  counter;
		jmp  preLoop;
	id1: //Loads in familyID1 into both the eax and ebx register.
		mov  eax, familyID1;
		mov  currentNum, eax;
		mov  ebx, currentNum;
		jmp  hexLoop;
	id2:
		mov  eax, familyID2;
		mov  currentNum, eax;
		mov  ebx, currentNum;
		jmp  hexLoop;
	id3:
		mov  eax, familyID3;
		mov  currentNum, eax;
		mov  ebx, currentNum;
		jmp  hexLoop;
	done:
	}

	system("pause");
	return 0;
}

/*Program I/O
BEEF is a valid ID for the family.
FADE is a valid ID for the family.
CABE is not a valid ID for the family.
Press any key to continue . . .
*/
