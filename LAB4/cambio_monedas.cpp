#include <iostream>
#include <vector>
using namespace std;

vector<int> cambioMonedas(vector<int>& denominaciones, int cantidad) {
	vector<int> solucion(denominaciones.size(), 0);
	
	for (size_t i = 0; i < denominaciones.size(); i++) {
		while (cantidad >= denominaciones[i]) {
			cantidad -= denominaciones[i];
			solucion[i]++;
		}
	}
	
	return solucion;
}

int main() {
	vector<int> denominaciones = {100, 50, 20, 10, 5, 1}; //valor de las monedas disponibles
	int cantidad;
	cout << "Ingrese la cantidad de cambio a devolver (en centavos): ", cin >> cantidad;
	vector<int> resultado = cambioMonedas(denominaciones, cantidad);
	cout << "El cambio a devolver es: " << endl;
	for (size_t i = 0; i < denominaciones.size(); i++) {
		if (resultado[i] > 0) {
			cout << resultado[i] << " monedas de " << denominaciones[i] << " centavos" << endl;
		}
	}
	
	return 0;
}
