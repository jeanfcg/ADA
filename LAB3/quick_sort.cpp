#include <iostream>

using namespace std;

// Función para intercambiar dos elementos en un array
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int partition(int array[], int low, int high) {
	int pivot = array[high];
	int i = (low - 1); 
	
	for (int j=low; j <= high-1; j++) {
		if (array[j] <= pivot) {
			i++;  // Incrementamos el índice del elemento más pequeño
			swap(array[i], array[j]);
		}
	}
	swap(array[i + 1], array[high]);
	return (i + 1);
}

// Función principal que implementa el algoritmo Quicksort
void QuickSort(int array[], int low, int high) {
	if (low < high) {
		int partitionIndex = partition(array, low, high);
		QuickSort(array, low, partitionIndex - 1);
		QuickSort(array, partitionIndex + 1, high);
	}
}

// Función para imprimir un array
void printArray(int array[], int size) {
	for (int i=0; i<size; i++)
		cout << array[i] << " ";
	cout << endl;
}

// Ejemplo de uso del algoritmo Quicksort
int main() {
	int array[] = {64,14,6,2,88,45,9};
	int arr_size = sizeof(array) / sizeof(array[0]);
	
	cout << "el array sin ordenar: ";
	printArray(array, arr_size);
	
	QuickSort(array, 0, arr_size - 1);
	
	cout << "el array ya ordenado: ";
	printArray(array, arr_size);
	
	return 0;
}
