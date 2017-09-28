#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void problem01();
void problem02();

int main() {
	problem02();
	system("PAUSE");

	return 0;
}

void problem01() {
	short drinks, food, total;
	short price = 2;
	cout << "--------MENU--------" << endl
		 << "Drinks............$2" << endl
		 << "Sandwiches........$4" << endl;
	cout << "How many drinks?" << endl;
	cin >> drinks;
	cout << "How many sandwiches?" << endl;
	cin >> food;
	
	_asm {
		mov ax, 2;
		imul food;
		add  ax, drinks;
		imul price;
		mov total, ax;
	}
	cout << "Your total bill is $" << total << endl;
}

void problem02() {
	int a, b, c, h, len, wid;
	int t_area, t_peri;
	int r_area, r_peri;
	cout << "     /|\\			 --------------- " << endl
		 << "    / | \\			|               |" << endl
		 << "a  /  |  \\  b			|               | width" << endl
		 << "  /   |   \\			|               |" << endl
		 << " /    |    \\			|               |" << endl
		 << " -----------			 --------------- " << endl
		 << "      C					  length"<< endl;
	cout << "Enter the values of a, b, c, and h for the triangle:";
	cin >> a >> b >> c >> h;
	cout << "Enter the length and width of the rectangle:";
	cin >> len >> wid;

	_asm {
		mov eax, a;
		add eax, b;
		add eax, c;
		mov t_peri, eax; // adds b into a and c into a for perimeter of a + b + c.
		mov eax, c;
		imul h;
		//idiv 2;
		mov t_area, eax; // multiplies eax(c) by h and divides by 2 for area of (base*height)/2
		mov eax, len;
		imul wid;
		mov r_area, eax; // multiplies length by width for area of lw
		mov eax, len;
		add eax, wid;
		add eax, eax;
		mov r_peri, eax; // adds length and width together in eax to add eax to itself for a perimiter of 2eax(l+w)
	}
	cout << "Triangle" << endl;
	cout << "	Area................" << t_area/2 << endl; //until i learn IDIV
	cout << "	Perimeter..........." << t_peri << endl;
	cout << "Rectangle" << endl;
	cout << "	Area................" << r_area << endl;
	cout << "	Perimeter..........." << r_peri << endl;
}