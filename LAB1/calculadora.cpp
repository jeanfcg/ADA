#include <iostream>

using namespace std;

void add(int* a, int* b, int* result) {
	*result = *a + *b;
}
void subtract(int* a, int* b, int* result) {
	*result = *a - *b;
}
void multiply(int* a, int* b, int* result) {
	*result = *a * *b;
}
void divide(int* a, int* b, int* result) {
	if (*b!=0) {
		*result = *a / *b;
	} else {
		cout<<"Error: Division by zero"<<endl;
	}
}

int main() {
	int num1, num2;
	cout<<"Enter number 1: ", cin>>num1;
	cout<<"Enter number 2: ", cin>>num2;
	
	int result;
	
	add(&num1, &num2, &result);
	cout<<"resultado suma: "<<result<<endl;
	
	subtract(&num1, &num2, &result);
	cout<<"resultado resta: "<<result<<endl;
	
	multiply(&num1, &num2, &result);
	cout<<"resultado multiplicación: "<<result<<endl;
	
	divide(&num1, &num2, &result);
	cout << "resultado división: "<<result <<endl;
	return 0;
}
