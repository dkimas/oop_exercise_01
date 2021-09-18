// Цыбенко Дмитрий вариант 2 действия с комплексными числами

#include <iostream>
#include <cmath>

using namespace std;

class Complex {
public:

	double rad, ang, drad, dang, x, x1, x2, y, y1, y2;
	
	Complex (double r, double j) {
		rad = abs(r);
		ang = j;
	}

	void printComplex() {
		cout << "radius=" << rad << " angle=" << ang << '\n';
	}
	// вывод числа
	void add(Complex a, Complex b) {
		x1 = cos(a.ang) * a.rad;
		y1 = sin(a.ang) * a.rad;
		x2 = cos(b.ang) * b.rad;
		y2 = sin(b.ang) * b.rad;
		x = x1 + x2;
		y = y1 + y2;
		drad = sqrt(x*x + y*y);
		dang = acos(x / drad);
	}
	Complex getadd() {
		Complex result(drad, dang);
		return result;
	}
	// сложение
	void sub(Complex a, Complex b) {
		x1 = cos(a.ang) * a.rad;
		y1 = sin(a.ang) * a.rad;
		x2 = cos(b.ang) * b.rad;
		y2 = sin(b.ang) * b.rad;
		x = x1 - x2;
		y = y1 - y2;
		drad = sqrt(x * x + y * y);
		dang = acos(x / drad);
	}
	Complex getsub() {
		Complex result(drad, dang);
		return result;
	}
	// вычитание
	void mul(Complex a, Complex b) {
		drad = a.rad * b.rad;
		dang = a.ang + b.ang;
	}
	Complex getmul() {
		Complex result(drad, dang);
		return result;
	}
	// умножение
	void div(Complex a, Complex b) {
		drad = a.rad / b.rad;
		dang = abs(a.ang - b.ang);
	}
	Complex getdiv() {
		Complex result(drad, dang);
		return result;
	}
	// деление
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
	// сравнение
	void conj(Complex a) {
		drad = a.rad;
		dang = - a.ang;
		cout << "Conjugate: radius=" << drad << " angle=" << dang << '\n';
	}
	// сопряженное
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
	// сравнение по целой части
};

int main()
{
	int a, b, c, d, menu, f=1;
	cout << "Input complex first" << '\n';
	cin >> a >> b;
	Complex first(a, b);
	cout << "Input complex second" << '\n';
	cin >> c >> d;
	Complex second(c, d);
	while (f) {
		cout << "1. Print numbers 2. Sum numbers 3. Subtract from first number second 4. Multiply numbers 5. Divide numbers" << '\n';
		cout << "6. Compare numbers 7. Conjugate first number 8. Compare real part of numbers 9. Exit" << '\n';
		cin >> menu;
		switch (menu) {
		case 1: {
			first.printComplex();
			second.printComplex();
			break;
		}
		case 2: {
			first.add(first, second);
		    (first.getadd()).printComplex();
			
			break;
		}
		case 3: {
			first.sub(first, second);
			(first.getsub()).printComplex();
			break;
		}
		case 4: {
			first.mul(first, second);
			(first.getmul()).printComplex();
			break;
		}
		case 5: {
			first.div(first, second);
			(first.getdiv()).printComplex();
			break;
		}
		case 6: {
			first.equ(first, second);
			break;
		}
		case 7: {
			first.conj(first);
			break;
		}
		case 8: {
			first.equreal(first, second);
			break;
		}
		case 9: {
			f=0;
			break;
		}
		default: {
			cout << "wrong command" << '\n';
			break;
		}
		}
		
	}

	return 0;
}
