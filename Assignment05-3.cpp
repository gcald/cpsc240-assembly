//Assignment 05 Problem #3 George Calderon
#include <iostream>
using std::cout;
using std::endl;

short axRegister, totalOn, currentSprinkler = 16, currentNum, binLoopCounter = 0, loopCounter = 0;

void printCurrentSprinkler () {
	cout << currentSprinkler << " ";
}

void printDefective() {
	cout << "Defective sprinklers: ";
}

void printBinary() {
	cout << "AX = ";
}

void printCurrentNum() {
	cout << currentNum;
}

void printTotalOn() {
	cout << totalOn << " sprinklers are ON" << endl;
}

void printNewLine() {
	cout << endl;
}

void printSpace() {
	cout << " ";
}

int main() {
	
	_asm {
		call printBinary;
		mov  ax, 0x6A2F; //Set ax register to default content
		mov  axRegister, ax; //For simplicity, store it in a short
	binLoop:
		cmp  binLoopCounter, 4; //Will add the space every 4 bits
		je   resetBin;
		mov  ax, 1000000000000000b; //This, followed by a few shifts, ensure that the binary is printed in the right order.
		and  ax, axRegister;
		shr  ax, 15; //Moves it all the way to the first bit to print the binary in the right order.
		mov  currentNum, ax;
		call printCurrentNum;//Will print the current binary number
		inc  binLoopCounter;
		shl  axRegister, 1;
		cmp  currentNum, 1; //When ever a sprinkler is on, it will also count the sprinkler into totalOn
		je   countSprinklers;
		jmp  binLoop;
	countSprinklers:
		inc  totalOn;
		jmp  binLoop;
	resetBin: //Prints the space adn then resets the counter in order to prepare for another space. This will also quit the loop after 16 bits.
		cmp  loopCounter, 3;
		je   done1;
		call printSpace;
		mov  binLoopCounter, 0;
		inc  loopCounter;
		jmp  binLoop;
	done1: //Will print the next line, aka, "Defective Sprinklers: "
		call printNewLine;
		call printTotalOn;
		call printDefective;
		mov  axRegister, 0x6A2F;
	defectiveLoop: //Same loop as before, but modified to print the sprinkler when the bit = 0.
		cmp  currentSprinkler, 0; //When we finished with the last sprinkler.
		je   done2;
		mov  ax, 1000000000000000b;
		and  ax, axRegister;
		shr  ax, 15;
		shl  axRegister, 1;
		mov  currentNum, ax;
		cmp  ax, 0;
		je   sprinklerNum;
		dec  currentSprinkler; //Opposite of inc, or increment, is dec, or decrement.
		jmp  defectiveLoop;
	sprinklerNum: //Prints the current sprinkler number.
		call printCurrentSprinkler;
		dec  currentSprinkler;
		jmp  defectiveLoop;
	done2:
		call printNewLine;
	}


	system("pause");
	return 0;
}

/*Program I/O
AX = 0110 1010 0010 1111
9 sprinklers are ON
Defective sprinklers: 16 13 11 9 8 7 5
Press any key to continue . . .
*/