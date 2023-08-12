/*
Problema: Algoritmo B&B para resolver el problema de la asignación con la siguiente matriz de costes:
x  f1 f2 f3 f4
d1 94 1 54 68
d2 74 10 88 82
d3 62 88 8 76
d4 11 74 81 21
*/


#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>


using namespace std;

const int INF = INT_MAX;

int costMin = INF;
vector<int> mejorAssignment;

int a = 4; // num tareas y trabajadores
vector<vector<int>> costs = {
	{94, 1, 54, 68},
{74, 10, 88, 82},
	{62, 88, 8, 76},
{11, 74, 81, 21}
};



void branchAndBound(int trabajador, vector<bool>& assigned, vector<int>& assignment, int cost) {
	if (trabajador == a) {
		if (cost < costMin) {
			costMin = cost;
			mejorAssignment = assignment;
		}
		return;
	}
	
	for (int tarea = 0; tarea < a; ++tarea) {
		if (!assigned[tarea]) {
			assigned[tarea] = true;
			assignment[trabajador] = tarea;
			branchAndBound(trabajador + 1, assigned, assignment, cost + costs[trabajador][tarea]);
			assigned[tarea] = false;
		}
	}
}

int main() {
	vector<bool> assigned(a, false);
	vector<int> assignment(a);
	
	branchAndBound(0, assigned, assignment, 0);
	
	cout << "la asignación óptima es: ";
	for (int trabajador = 0; trabajador < a; ++trabajador) {
		cout << "f" << (trabajador + 1) << "->d" << (mejorAssignment[trabajador] + 1) << " ";
	} cout << endl;
	cout << "el costo mínimo es: " << costMin << endl;
	
	return 0;
}
