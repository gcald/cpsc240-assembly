//Assignment 05 Problem #1 George Calderon
#include <iostream>
using std::cout;
using std::endl;

short numPrinter = 0, numFloppy = 0, ramSize = 0;

void printContent() {
	cout<< "Printers connected: " << numPrinter << endl
		<< "Floppy Drives connected: " << numFloppy << endl
		<< "RAM size: " << ramSize << "GB" << endl;
}

int main() {
	
	_asm {
		mov ax, 1100111010011100b; //The content stored in AX register during an interrupt.
		shr ax, 2;
	Ram:
		mov ramSize, 11b;
		and ramSize, ax; //Used to get the bits at the new bit 0 and bit 1.
		cmp ramSize, 0; //Cases used in order to get the right amount of ram stored in the variable.
		je Ram0;
		cmp ramSize, 1;
		je Ram1;
		cmp ramSize, 2;
		je Ram2;
		cmp ramSize, 3;
		je Ram3;
	Floppy:
		shr ax, 4;
		mov numFloppy, 11b;
		and numFloppy, ax; //This will get us the number of floppy drives - 1.
		inc numFloppy; //So we increment numFloppy by 1.
	Printer:
		shr ax, 8;
		mov numPrinter, 11b;
		and numPrinter, ax; //This will get the exact amount of printers, no additional steps required.
		jmp done;
	Ram0:
		mov ramSize, 16;
		jmp Floppy;
	Ram1:
		mov ramSize, 32;
		jmp Floppy;
	Ram2:
		mov ramSize, 48;
		jmp Floppy;
	Ram3:
		mov ramSize, 64;
		jmp Floppy;
	Done:
		call printContent;
	}

	system("pause");
	return 0;
}

/*Program I/O
Printers connected: 3
Floppy Drives connected: 3
RAM size: 64GB
Press any key to continue . . .
*/
