#include <iostream>
#include <cmath>

using namespace std;

class Calculadora {
public:
	static double sumar(double a, double b) {
		return a + b;
	}
	
	static double restar(double a, double b) {
		return a - b;
	}	
	
	static double multiplicar(double a, double b) {
		return a * b;
	}
	
	static double dividir(double a, double b) {
		if (b != 0) {
			return a / b;
		} else {
			cout << "¡Error! No se puede dividir por cero."<<endl;
			return 0.0;
		}
	}
	static double potenciar(double a, double b) {
		return pow(a, b);
	}
	
	static double radicar(double a, double b) {
		return pow(a, 1 / b);
	}
};
int main() {
	Calculadora O;
	float a, b, c;
	cout << "ingrese el primer numero: ", cin >> a;
	cout << "ingrese el segundo numero: ", cin >> b;
	double (*fOperaciones[6])(double a, double b) = {&O.sumar, &O.restar, &O.multiplicar, &O.dividir, &O.potenciar, &O.radicar};
	char operadores[] = "+-*/^V";
	for (size_t i = 0; i < 6; i++)
	{
		c = fOperaciones[i](a, b);
		cout << a << " " << operadores[i] << " " << b << " = " << c << endl;
	}
}
