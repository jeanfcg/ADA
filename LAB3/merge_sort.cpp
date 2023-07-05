#include <iostream>

using namespace std;

void Merge(int* array, int left, int middle, int right) {//combinar dos subarrays ordenados en un array ordenado
	int n1 = middle - left + 1;
	int n2 = right - middle;
	
	int* L = new int[n1];
	int* R = new int[n2];
	
	// Copiar datos a los arrays temporales
	for (int i=0; i<n1; i++) {
		L[i] = array[left + i];	
	}
	
	for (int j=0; j<n2; j++) {
		R[j] = array[middle + 1 + j];
	}
	// Combinar los arrays temporales
	int i = 0;
	int j = 0;
	int m = left;
	
	while (i<n1 && j<n2) {	
		if (L[i] <= R[j]) {
			array[m] = L[i];
			i++;
		} else {
			array[m] = R[j];
			j++;
		}
		m++;
	}
	// Copiar los elementos restantes de L
	while (i<n1) {
		array[m] = L[i];
		i++;
		m++;
	}
	// Copiar los elementos restantes de R
	while (j<n2) {
		array[m] = R[j];
		j++;
		m++;
	}
	
	delete[] L;
	delete[] R;
}

void MergeSort(int* array, int left, int right) {
	if (left >= right) {
		return;
	}
	
	int middle = left + (right - left) / 2;
	
	MergeSort(array, left, middle);
	MergeSort(array, middle+1, right);
	
	Merge(array, left, middle, right);
}

int main() {
	int array[] = {12,5,22,52,3,8,2,27};
	int n = sizeof(array) / sizeof(array[0]);
	
	cout << "el array sin ordenar: ";
	for (int i = 0; i < n; i++) {
		cout <<array[i]<< " ";
	} cout<<endl;
	
	MergeSort(array, 0, n - 1);
	
	cout << "el array ya ordenado: ";
	for (int i=0; i<n; i++) {
		cout <<array[i]<< " ";
	} cout<<endl;
	return 0;
}
