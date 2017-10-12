//Project #7 Problem #2 by George Calderon and Zach Qiu
#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::showpoint;
using std::setprecision;

float a, b, c, x1, x2, zero = 0, two = 2, four = 4;

void display() {
	cout << fixed << showpoint << setprecision(2) << "   X1=" << x1 << "   X2=" << x2 << endl;
}

void getNums() {
	cout << "To see the real roots of aX^2 + bX + c = 0, enter a, b, and c values: ";
	cin >> a >> b >> c;
}

int main() {
	getNums();

	_asm {
	x1:
		fld  zero; // 0
		fld  b;    // 0 b
		fsub;	   // 0 - b
		fld  b;    // (-b) b
		fld  b;    // (-b) b b
		fmul;      // (-b) b^2
		fld  four; // (-b) b^2 4
		fld  a;    // (-b) b^2 4 a
		fld  c;    // (-b) b^2 4 a c
		fmul;      // (-b) b^2 4 a*c
		fmul;      // (-b) b^2 4*a*c
		fsub;      // (-b) (b^2)-4ac
		fsqrt;     // (-b) sqrt((b^2)-4ac)
		fadd;	   // (-b) + sqrt((b^2)-4ac)
		fld  two;  // (-b)+sqrt((b^2)-4ac) 2
		fld  a;    // (-b)+sqrt((b^2)-4ac) 2 a
		fmul;      // (-b)+sqrt((b^2)-4ac) 2*a
		fdiv;      // ((-b)+sqrt((b^2)-4ac))/2a
		fstp x1;   // x1 = ((-b)+sqrt((b^2)-4ac))/2a
	x2:
		fld  zero; // 0
		fld  b;    // 0 b
		fsub;	   // 0 - b
		fld  b;    // (-b) b
		fld  b;    // (-b) b b
		fmul;      // (-b) b^2
		fld  four; // (-b) b^2 4
		fld  a;    // (-b) b^2 4 a
		fld  c;    // (-b) b^2 4 a c
		fmul;      // (-b) b^2 4 a*c
		fmul;      // (-b) b^2 4*a*c
		fsub;      // (-b) (b^2)-4ac
		fsqrt;     // (-b) sqrt((b^2)-4ac)
		fsub;	   // (-b) - sqrt((b^2)-4ac)
		fld  two;  // (-b)-sqrt((b^2)-4ac) 2
		fld  a;    // (-b)-sqrt((b^2)-4ac) 2 a
		fmul;      // (-b)-sqrt((b^2)-4ac) 2*a
		fdiv;      // ((-b)-sqrt((b^2)-4ac))/2a
		fstp x2;   // x2 = ((-b)-sqrt((b^2)-4ac))/2a
	done:
		call display;
	}

	system("pause");
	return 0;
}