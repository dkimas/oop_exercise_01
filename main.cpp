#include <iostream>
#include <cmath>

using namespace std;

class Complex {
public:

	double rad, ang, drad, dang;
	
	Complex (double r, double j) {
		rad = abs(r);
		ang = j;
	}

	void printComplex() {
		cout << "radius=" << rad << " angle=" << ang << '\n';
	}

	void add(Complex a, Complex b) {
		drad = a.rad + b.rad;
		dang = a.ang + b.ang;
		cout << "Sum: radius=" << drad << " angle="  << dang << '\n';
	}
	void sub(Complex a, Complex b) {
		drad = abs(a.rad - b.rad);
		dang = a.ang - b.ang;
		cout << "Subtract: radius=" << drad << " angle=" << dang << '\n';
	}
	void mul(Complex a, Complex b) {
		drad = a.rad * b.rad;
		dang = a.ang * b.ang;
		cout << "Multiple: radius=" << drad << " angle=" << dang << '\n';
	}
	void div(Complex a, Complex b) {
		drad = a.rad / b.rad;
		dang = a.ang / b.ang;
		cout << "Division: radius=" << drad << " angle=" << dang << '\n';
	}
	bool equ(Complex a, Complex b) {
		if ((a.rad == b.rad) && (a.ang == b.ang)) {
			cout << "Numbers are equal" << '\n';
			return true;
		}

		else {
			cout << "Numbers aren't equal" << '\n';
			return false;
		}
	}
	void conj(Complex a) {
		drad = a.rad;
		dang = - a.ang;
		cout << "Conjugate: radius=" << drad << " angle=" << dang << '\n';
	}
	bool equreal(Complex a, Complex b) {
		if (a.rad == b.rad) {
			cout << "Real part of numbers are equal" << '\n';
			return true;
		}

		else {
			cout << "Real part of numbers aren't equal" << '\n';
			return false;
		}
	}
};

int main()
{
	int a, b, c, d;
	cout << "Input complex first" << '\n';
	cin >> a >> b;
	Complex first(a, b);
	cout << "Input complex second" << '\n';
	cin >> c >> d;
	Complex second(c, d);
	first.printComplex();
	second.printComplex();
	first.add(first, second);
	first.sub(first, second);
	first.mul(first, second);
	first.div(first, second);
	first.equ(first, second);
	first.conj(first);
	first.equreal(first, second);

	return 0;
}
