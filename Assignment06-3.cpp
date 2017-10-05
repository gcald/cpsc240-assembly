#include <iostream>
using std::cout;
using std::endl;

int a[3][3][2] = { { {1,2},{3,4},{5,6} },  { {7,8},{9,10},{11,12} } ,  { {13,14},{15,16},{17,18} } };
int currentInt, loopCounter = 0, loopSubCounter = 0;

void printInt() {
	cout << currentInt << endl;
}

void printAll() {
	cout << "a. Total Number of All Shirts: ";
}

void printMedium() {
	cout << "b. Total Number of Medium-sized Shirts: ";
}

void printShort() {
	cout << "c. Total Number of Short-sleeved Shirts: ";
}

void printRed() {
	cout << "d. Total Number of Red Shirts: ";
}

int main() {

	_asm {
		call printAll;
	loop1:
		cmp  loopCounter, 18; // Made to loop through all indexes
		je   done1;
		mov  ebx, loopCounter; //Moves the loops counter into register
		mov  eax, [a+ebx*4]; //Calculates the offset for the register (int = 4 bytes)
		add  currentInt, eax; //Adds all numbers into currentInt
		inc  loopCounter;
		jmp  loop1; //loops through
	done1:
		call printInt;
		call printMedium;
		mov  currentInt, 0;
		mov  loopCounter, 2; //Skip the first two nums [Small and Red shirts]
	loop2:
		cmp  loopCounter, 18; //Iterates through 18 indexes
		jge  done2;
		cmp  loopSubCounter, 2; //Will check if it has printed the two in succession
		je   loop2Sub;
		mov  ebx, loopCounter;
		mov  eax, [a + ebx * 4]; //Will iterate through loopCounter * int offset
		add  currentInt, eax; //Adds the shirts together
		inc  loopCounter;
		inc  loopSubCounter;
		jmp  loop2;
	loop2Sub:
		mov  loopSubCounter, 0; //Resets subCounter
		add  loopCounter, 4; //Move down 2 ints (2 * 4 bytes)
		jmp  loop2;
	done2:
		call printInt;
		call printShort;
		mov  currentInt, 0;
		mov  loopCounter, 0;
		mov  loopSubCounter, 0;
	loop3:
		cmp  loopCounter, 18; //Iterates through 18 indexes
		jge  done3;
		mov  ebx, loopCounter;
		mov  eax, [a + ebx * 4]; //Will iterate through loopCounter * int offset
		add  currentInt, eax; //Adds the shirts together
		add  loopCounter, 2; //Used to skip the Long Sleeves slice.
		jmp  loop3;
	done3:
		call printInt;
		call printRed;
		mov  currentInt, 0;
		mov  loopCounter, 0;
	loop4:
		cmp  loopCounter, 6; //Iterates through first 6 indexes (aka, the red shirts)
		je  done4;
		mov  ebx, loopCounter;
		mov  eax, [a + ebx * 4]; //Will iterate through loopCounter * int offset
		add  currentInt, eax; //Adds the shirts together
		inc  loopCounter;
		jmp  loop4;
	done4:
		call printInt;
	}

	system("PAUSE");

	return 0;
}