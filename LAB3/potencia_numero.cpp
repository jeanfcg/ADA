#include <iostream>

using namespace std;

double power(double n, int exp) {
	if (exp==0) {
		return 1;
	}
	double mitad = power(n, exp / 2);
	double resultado = mitad * mitad;
	
	if (exp % 2 == 1) {
		resultado *= n;
	}
	return resultado;
}

int main() {
	double n;
	int exp;
	cout << "Ingrese la base: ", cin >> n;
	cout << "Ingrese el exponente: ", cin >> exp;
	double resultado = power(n, exp);
	cout << "el numero " << n << " elevado a la potencia " << exp << " es igual a: " << resultado << endl;
	return 0;
}
