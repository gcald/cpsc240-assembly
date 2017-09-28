#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void problem1();
void problem2();
void problem3();
void problem4();
void whileLoop();

int main() {
	
	problem1();

	system("PAUSE");
	return 0;
}

void problem1() {
	int numDrinks, numFood, foodSize, total;
	char drinkType;
	
	cout << "----------7-11 Convenient Store----------" << endl;
	cout << "Drinks" << endl;
	cout << "  Soda (S).............................$2" << endl;
	cout << "  Water (W)............................$1" << endl;
	cout << "Sandwiches" << endl;
	cout << "  10 inches............................$3" << endl;
	cout << "  12 inches............................$5" << endl;
	cout << endl << "How many drinks?";
	cin >> numDrinks;
	cout << "  What kind of drink(S=Soda, W=Water)?";
	cin >> drinkType;
	cout << "How many sandwiches?";
	cin >> numFood;
	cout << " What size of sandwich (10/12 inches)?";
	cin >> foodSize;

	_asm {
		cmp drinkType, 'S';
		je	soda;
		mov eax, 1;
		imul numDrinks;
		mov  total, eax;
		jmp sandwich;
	soda:
		mov eax, 2;
		imul numDrinks;
		mov  total, eax;
	sandwich:
		cmp foodSize, 10;
		je  small;
		mov eax, 5;
		imul numFood;
		jmp  bill;
	small:
		mov eax, 3;
		imul numFood;
	bill:
		add total, eax;
	}

	cout << "Your total bill = " << total << endl;
}

void whileLoop(int &num) {
	cout << "Enter your score (-1) to stop: ";
	cin >> num;
}

void problem2() {
	int average, count, total, num;

	cout << "Let's compute your score's average:" << endl;
	


}