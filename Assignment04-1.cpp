////Project No.4 Problem 01 George Calderon
//
//#include <iostream>
//using std::cin;
//using std::cout;
//using std::endl;
//
//char c;
//int yesCount;
//int noCount;
//int yLoop = 0;
//int nLoop = 0;
//
//void drawStar() {
//	cout << '*';
//}
//
//void endLine() {
//	cout << endl;
//}
//
//void getChar() {
//	cin.get(c);
//}
//
//void printYCount() {
//	cout << "  No. of YES votes = " << yesCount << " = ";
//}
//
//void printNCount() {
//	cout << "  No. of NO votes = " << noCount << " = ";
//}
//
//int main() {
//	cout << "Enter a string of votes: ";
//
//	_asm {
//	whileLoop:
//		call getChar;
//		mov al, c;
//		cmp al, 'y';
//		je  countYes;
//		cmp al, 'n';
//		je countNo;
//		cmp c, '\n'; // When enter is pressed, jump to done.
//		je  printY;
//		jmp whileLoop;
//	countYes: // Increments 'y' counter for later loop.
//		inc yesCount;
//		jmp whileLoop;
//	countNo: // Increments 'n' counter for later loop.
//		inc noCount;
//		jmp whileLoop;
//	printY:
//		call printYCount;
//	loopY: // Loops until yLoop(initialized at 0) equals yesCount.
//		mov eax, yLoop;
//		cmp eax, yesCount;
//		je	printN;
//		call drawStar;
//		inc yLoop;
//		jmp loopY;
//	printN:
//		call endLine;
//		call printNCount;
//	loopN: // Loops until nLoop(initialized at 0) equals noCount.
//		mov eax, nLoop;
//		cmp eax, noCount;
//		je	done;
//		call drawStar;
//		inc nLoop;
//		jmp loopN;
//
//	done:
//		call endLine;
//	}
//
//	system("PAUSE");
//	return 0;
//}