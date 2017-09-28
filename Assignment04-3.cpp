//Project No.4 Problem 03 George Calderon

#include <iostream>
#include <cstdlib>
using std::cin;
using std::cout;
using std::endl;
using std::rand;

char choice;
int numCorrect = 0, numWrong = 0, randNum1, randNum2, answer, caseNum;

void getRand() { // Gets a random number from 0-99.
	randNum1 = rand() % 99;
	randNum2 = rand() % 99;
}

void printAdd() { // Prints the addition equation and gets the answer.
	cout << "    " << randNum1 << " + " << randNum2 << " = ? ";
	cin >> answer;
}

void printSub() { // Prints the subtraction equation and gets the answer.
	cout << "    " << randNum1 << " - " << randNum2 << " = ? ";
	cin >> answer;
}

void printCorrect() { // Prints the word "CORRECT" with the right amount of indents
	cout << "      CORRECT" << endl;
}

void printWrong() { // Prints the word "WRONG" with the right amount of indents
	cout << "      WRONG" << endl;
}

void printContinue() { // Asks the user is they would like to continue.
	cout << "      Continue(y/n)? ";
	cin >> choice;
}

void isDone() { // Asks the user if they are done.
	cout << "  Are you done(y/n)? ";
	cin >> choice;
}

void printScore() { // Prints the score of the current session.
	cout << "    No. of CORRECT answers = " << numCorrect << endl;
	cout << "    No. of WRONG answers = " << numWrong << endl;
}

void printDone() { // Says goodbye to the user.
	cout << "    Have a nice day!" << endl;
}

void printMenu() { // Prints the menu (used multiple times to remember choice options).
	cout << "a. Practice Addition" << endl;
	cout << "b. Practice Subtraction" << endl;
	cout << "  Enter your choice(a/b): ";
	cin >> choice;
}

int main() {

	_asm {
	programStart: // Where the program starts.
		call printMenu;
		cmp  choice, 'a';
		je   addition; // Will jump to addition if 'a' is entered.
	subtraction:
		mov caseNum, 0; // Case number is used to continue in subtraction mode when asked to continue.
		call getRand;
		call printSub;
		mov  eax, randNum1;
		sub  eax, randNum2;
		cmp  eax, answer; // Compares the answer calulated in the register to the user input.
		je   correct;
		jmp  wrong;
	addition:
		mov caseNum, 1; // Case number is used to continue in addition mode when asked to continue.
		call getRand;
		call printAdd;
		mov  eax, randNum1;
		add  eax, randNum2;
		cmp  eax, answer; // Compares the answer calculated in the register to the user input.
		je   correct;
	wrong:
		call printWrong; // Will print and increment the total number of wrong answers.
		inc  numWrong;
		call printContinue;
		jmp  again; // Will jump to again label to determine whether the user wants to continue.
	correct: // Will print and increment the total number of correct answers.
		call printCorrect;
		inc  numCorrect;
		call printContinue;
	again: // Will jump to againNo if user does not want to continue.
		cmp  choice, 'n';
		je   againNo;
		cmp  choice, 'N';
		je   againNo;
	againYes: // If user wants to continue, it will take them back to the corresponding mode.
		cmp  caseNum, 1; // caseNum = 1 when the mode is set to addition.
		je   addition; // Will jump back to addition if caseNum = 1,
		jmp  subtraction; // Otherwise it will jump back to subtraction.
	againNo:
		call printScore; // Will print the current score.
		mov numCorrect, 0;
		mov numWrong, 0; // Will zero the scores since user did NOT want to continue.
		call isDone;
		cmp  choice, 'Y';
		je   doneYes;
		cmp  choice, 'y';
		je   doneYes; // Used to determine "Are you done?" prompt.
	doneNo:
		jmp programStart; // If not done, we will loop back to the front, which includes printing the menu.
	doneYes:
		call printDone; // We bid the user farewell.
	}

	system("PAUSE");
	return 0;
}