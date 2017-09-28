//Assignment 05 Problem #4 George Calderon
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;
using std::rand;

short axRegister, currentFloor = 16, currentNum, binLoopCounter = 0, loopCounter = 0;

void printCurrentFloor() {
	cout << currentFloor << " ";
}

void printBinary() {
	cout << "AX = ";
}

void printFloors() {
	cout << "Elevator will stop at floors no. ";
}

void printCurrentNum() {
	cout << currentNum;
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
		mov  ax, 1001000100001100b; //Number in the I/O example
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
		jmp  binLoop;
	resetBin: //Prints the space and then resets the counter in order to prepare for another space. This will also quit the loop after 16 bits.
		cmp  loopCounter, 3;
		je   done1;
		call printSpace;
		mov  binLoopCounter, 0;
		inc  loopCounter;
		jmp  binLoop;
	done1: //Will print the next line, aka, "Elevator will stop at floors no. "
		call printNewLine;
		call printFloors;
		mov  axRegister, 1001000100001100b;
	floorLoop: //Same loop as before, but modified to print the floor number.
		cmp  currentFloor, 1; //When we finished with the last floor (aka first floor).
		je   done2;
		mov  ax, 1000000000000000b;
		and  ax, axRegister;
		shr  ax, 15;
		shl  axRegister, 1;
		mov  currentNum, ax;
		cmp  ax, 1;
		je   floorNum;
		dec  currentFloor; //Opposite of inc, or increment, is dec, or decrement.
		jmp  floorLoop;
	floorNum: //Prints the current floor number.
		call printCurrentFloor;
		dec  currentFloor;
		jmp  floorLoop;
	done2:
		call printNewLine;
	}

	system("pause");
	return 0;
}

/*Program I/O
AX = 1001 0001 0000 1100
Elevator will stop at floors no. 16 13 9 4 3
Press any key to continue . . .
*/