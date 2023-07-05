#include <iostream>
using namespace std;

// Función de búsqueda binaria recursiva
int binarySearch(int array[], int left, int right, int target) {
	if (right >= left) {
		int mid = left + (right - left) / 2;
		if (array[mid] == target)//medio
			return mid;
		if (array[mid] > target)
			return binarySearch(array, left, mid - 1, target);//mitad izquierda
		return binarySearch(array, mid + 1, right, target);//mitad derecha
	}
	return -1;//si el elemento no se encuentra
}
int main() {
	int array[] = {4,7,12,23,26,47,88};
	int array_size = sizeof(array) / sizeof(array[0]);
	int target = 47;
	int result = binarySearch(array, 0, array_size-1, target);
	if (result == -1)
		cout << "el elemento no se encuentra en este array."<<endl;
	else
		cout << "el elemento está presente en la posición: "<<result<<endl;
	return 0;
}
