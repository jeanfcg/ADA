#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Tarea {
	int inicio;
	int fin;
};

bool compararTareas(const Tarea& a, const Tarea& b) {
	return a.fin < b.fin;
}

vector<Tarea> planificacionVoraz(vector<Tarea>& tareas) {
	sort(tareas.begin(), tareas.end(), compararTareas);
	
	vector<Tarea> planificacion;
	planificacion.push_back(tareas[0]);
	
	int ultimaTareaIndex = 0;
	
	for (int i = 1; i < tareas.size(); i++) {
		if (tareas[i].inicio >= tareas[ultimaTareaIndex].fin) {
			planificacion.push_back(tareas[i]);
			ultimaTareaIndex = i;
		}
	}
	
	return planificacion;
}

int main() {
	vector<Tarea> tareas = {
		{1, 4},
		{3, 5},
		{0, 6},
		{5, 7},
		{3, 8},
		{5, 9},
		{6, 10},
		{8, 11},
		{8, 12},
		{2, 13},
		{12, 14}
	};
	
	vector<Tarea> planificacion = planificacionVoraz(tareas);
	
	cout << "Planificación de tareas: " << endl;
	for (const auto& tarea : planificacion) {
		cout << "Inicio: " << tarea.inicio << ", Fin: " << tarea.fin << endl;
	}
	
	return 0;
}
