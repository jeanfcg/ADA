#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Objeto {
	int peso;
	int valor;
};

bool compararObjetos(const Objeto& a, const Objeto& b) {
	double ratioA = static_cast<double>(a.valor) / a.peso;
	double ratioB = static_cast<double>(b.valor) / b.peso;
	return ratioA > ratioB;
}
double mochila(vector<Objeto>& objetos, int capacidad) {
	sort(objetos.begin(), objetos.end(), compararObjetos);
	double valorTotal = 0.0;
	int espacioRestante = capacidad;
	for (const auto& objeto : objetos) {
		if (espacioRestante >= objeto.peso) {
			valorTotal += objeto.valor;
			espacioRestante -= objeto.peso;
		} else {
			double fraccion = static_cast<double>(espacioRestante) / objeto.peso;
			valorTotal += fraccion * objeto.valor;
			break;
		}
	}
	return valorTotal;
}

int main() {
	vector<Objeto> objetos = {
		{10, 20},
		{20, 100},
		{15, 40},
		{30, 120}
	};
	int capacidadMochila = 50;
	double valorO = mochila(objetos, capacidadMochila);
	cout << "el maximo valor que se puede obtener es: "<<valorO<< endl;
	return 0;
}
