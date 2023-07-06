#include <iostream>
#include <cmath>

using namespace std;

typedef double (*Operacion)(double, double);

double sumar(double a, double b) {
	return a + b;
}

double restar(double a, double b) {
	return a - b;
}

double multiplicar(double a, double b) {
	return a * b;
}

double dividir(double a, double b) {
	if (b != 0) {
		return a / b;
	} else {
		std::cout << "¡Error! No se puede dividir por cero." << std::endl;
		return 0.0;
	}
}
double potenciar(double a, double b) {
	return pow(a, b);
}
double radicar(double a, double b) {
	return pow(a, 1 / b);
}
int main()
{
	typedef double (*Operacion)(double, double);
	Operacion operadores[6] = {&::sumar, &::restar, &::multiplicar, &::dividir, &::potenciar, &::radicar};
	float a, b, c; int opc;
	cout << "ingrese el primer numero: ", cin >> a;
	cout << "ingrese el segundo numero: ", cin >> b;
	cout << "\n0.suma \n1.resta \n2.multiplicacion \n3.division \n4.potencia \n5.raiz \n\ningrese la opcion: ", cin >> opc;
	c = operadores[opc](a,b);
	cout<<"la respuesta es: "<<c;
}
