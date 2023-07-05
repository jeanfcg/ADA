#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> sumMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {//funcion suma
	int n = A.size();
	vector<vector<int>> result(n, vector<int>(n));
	
	for (int i=0; i<n; i++) {
		for (int j = 0; j < n; j++) {
			result[i][j] = A[i][j] + B[i][j];
		}
	}
	
	return result;
}

vector<vector<int>> subtractMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {//funcion resta
	int n = A.size();
	vector<vector<int>> result(n, vector<int>(n));
	
	for (int i=0; i<n; i++) {
		for (int j = 0; j < n; j++) {
			result[i][j] = A[i][j] - B[i][j];
		}
	}
	
	return result;
}

vector<vector<int>> strassenMatrixMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {//funcion multiplicacion algoritmo strassen
	int n = A.size();
	if (n == 1) {
		vector<vector<int>> C(1, vector<int>(1));
		C[0][0] = A[0][0] * B[0][0];
		return C;
	}
	
	int mid = n / 2;//dividir las matrices en 4 submatrices
	
	vector<vector<int>> A11(mid, vector<int>(mid));
	vector<vector<int>> A12(mid, vector<int>(mid));
	vector<vector<int>> A21(mid, vector<int>(mid));
	vector<vector<int>> A22(mid, vector<int>(mid));
	
	vector<vector<int>> B11(mid, vector<int>(mid));
	vector<vector<int>> B12(mid, vector<int>(mid));
	vector<vector<int>> B21(mid, vector<int>(mid));
	vector<vector<int>> B22(mid, vector<int>(mid));
	
	for (int i = 0; i < mid; i++) {
		for (int j = 0; j < mid; j++) {
			A11[i][j] = A[i][j];
			A12[i][j] = A[i][j + mid];
			A21[i][j] = A[i + mid][j];
			A22[i][j] = A[i + mid][j + mid];
			B11[i][j] = B[i][j];
			B12[i][j] = B[i][j + mid];
			B21[i][j] = B[i + mid][j];
			B22[i][j] = B[i + mid][j + mid];
		}
	}
	vector<vector<int>> P1 = strassenMatrixMultiply(A11, subtractMatrix(B12, B22));
	vector<vector<int>> P2 = strassenMatrixMultiply(sumMatrix(A11, A12), B22);
	vector<vector<int>> P3 = strassenMatrixMultiply(sumMatrix(A21, A22), B11);
	vector<vector<int>> P4 = strassenMatrixMultiply(A22, subtractMatrix(B21, B11));
	vector<vector<int>> P5 = strassenMatrixMultiply(sumMatrix(A11, A22), sumMatrix(B11, B22));
	vector<vector<int>> P6 = strassenMatrixMultiply(subtractMatrix(A12, A22), sumMatrix(B21, B22));
	vector<vector<int>> P7 = strassenMatrixMultiply(subtractMatrix(A11, A21), sumMatrix(B11, B12));
	
	vector<vector<int>> C11 = sumMatrix(subtractMatrix(sumMatrix(P5, P4), P2), P6);//calcular las submatrices resultantes
	vector<vector<int>> C12 = sumMatrix(P1, P2);
	vector<vector<int>> C21 = sumMatrix(P3, P4);
	vector<vector<int>> C22 = subtractMatrix(subtractMatrix(sumMatrix(P5, P1), P3), P7);
	
	vector<vector<int>> C(n, vector<int>(n));//combinar las submatrices en una matriz resultante
	for (int i=0; i<mid; i++) {
		for (int j = 0; j<mid; j++) {
			C[i][j] = C11[i][j];
			C[i][j + mid] = C12[i][j];
			C[i + mid][j] = C21[i][j];
			C[i + mid][j + mid] = C22[i][j];
		}
	}
	return C;
}
void printMatrix(const vector<vector<int>>& matrix) {
	int n = matrix.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		} cout<<endl;
	} cout<<endl;
}

int main() {
	vector<vector<int>> A = {{1, 2, 3, 4},
	{5, 6, 7, 8},
	{9, 10, 11, 12},
	{13, 14, 15, 16}};
	
	vector<vector<int>> B = {{16, 15, 14, 13},
	{12, 11, 10, 9},
	{8, 7, 6, 5},
	{4, 3, 2, 1}};
	
	cout<<"la matriz A:" << endl;
	printMatrix(A);
	
	cout<<"la matriz B:" << endl;
	printMatrix(B);
	
	vector<vector<int>> C = strassenMatrixMultiply(A, B);
	cout<<"el resultado de la multiplicacion de matrices es:"<<endl;
	printMatrix(C);
	
	return 0;
}
