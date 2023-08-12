#include <bits/stdc++.h>

using namespace std;

vector<int> longestIncreasingSubsequence(const vector<int>& numeros) {
	int n = numeros.size();
	vector<int> longitudes(n, 1); // Inicialmente, cada posición es una secuencia de longitud 1
	
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (numeros[i] > numeros[j] && longitudes[i] < longitudes[j] + 1) {
				longitudes[i] = longitudes[j] + 1;
			}
		}
	}
	
	int maxLongitud = 0, endIndex = 0;
	for (int i = 0; i < n; ++i) {
		if (longitudes[i] > maxLongitud) {
			maxLongitud = longitudes[i];
			endIndex = i;
		}
	}
	
	vector<int> lis;
	while (maxLongitud > 0) {
		lis.insert(lis.begin(), numeros[endIndex]);
		--maxLongitud;
		--endIndex;
		while (endIndex >= 0 && longitudes[endIndex] != maxLongitud) {
			--endIndex;
		}
	}
	
	return lis;
}

int main() {
	vector<int> numeros = {11, 17, 5, 8, 6, 4, 7, 12, 3};
	
	vector<int> lis = longestIncreasingSubsequence(numeros);
	
	cout << "la secuencia creciente de máxima longitud es: ";
	for (int num : lis) {
		cout << num << " ";
	}
	cout << endl;
	
	return 0;
}
