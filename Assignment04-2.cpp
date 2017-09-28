////Project No.4 Problem 02 George Calderon
//
//#include <iostream>
//using std::cin;
//using std::cout;
//using std::endl;
//
//char c;
//int initPrint = 0;
//int caseNum = 0;
//
//void getChar() {
//	cin.get(c);
//}
//
//void printOutput() { // Used to get exact sample I/O.
//	cout << "  Output: ";
//}
//
//void printChar() {
//	cout << c;
//}
//
//void endLine() {
//	cout << endl;
//}
//
//int main() {
//	cout << "Enter a sentence: ";
//	
//	_asm {
//	whileLoop:		 // used to get the characters of input
//		call getChar;
//		cmp  c, 'a';
//		je   capital;
//		cmp  c, 'e';
//		je   capital;
//		cmp  c, 'i';
//		je   capital;
//		cmp  c, 'o';
//		je   capital;
//		cmp  c, 'u';
//		je   capital;
//		cmp  c, '.'; // loop ends when '.' is encountered.
//		je   done;
//		mov  caseNum, 0; // cases used to avoid printing 'Output: ' everytime.
//		cmp  initPrint, 0; // If equal to 0, will print the 'Output: ' line.
//		je   printOut;
//		call printChar; // prints the remainder character which would be a consonant.
//		jmp  whileLoop;
//	printCons: // Only used in order to print first 'Output: ' line.
//		call printChar;
//		jmp whileLoop;
//	printOut:
//		inc  initPrint; // will increment the initPrint to avoid printing 'Output: ' more than once.
//		call printOutput;
//		cmp  caseNum, 0; // Case 0: Consonant/Remainder.
//		je   printCons;
//		cmp  caseNum, 1; // Case 1: Vowel (Must be capitalized).
//		je   capital;
//		cmp  caseNum, 2; // Case 2: Used when '.' is the only input.
//		je   done;
//		jmp  whileLoop;
//	capital:
//		mov  caseNum, 1; // Initialized the Case number.
//		cmp  initPrint, 0;
//		je   printOut;
//		mov  al, 32; // used to subtract from the lowercase letter to equal the uppercase letter.
//		sub  c, al;
//		call printChar;
//		jmp  whileLoop;
//	done:
//		mov  caseNum, 2;
//		cmp  initPrint, 0;
//		je   printOut;
//		call printChar;
//		call endLine;
//	}
//
//	system("PAUSE");
//	return 0;
//}