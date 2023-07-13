#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int monedasMax(vector<int>& moneda){
	int x = 0, contador = 0;
	
	for(int i=0; i < moneda.size()-1; i++){
		if(x + moneda[i] < moneda[i+1]) {
			x = x + moneda[i];
			++contador;
		}
	} return contador + 1;
}
	int main() {
		int a;
		cin>>a;
		
		while(a--){
			int b;
			cin>>b;
			vector<int> moneda(b);
			for(int i = 0; i<b; i++){
				cin>>moneda[i];
			} cout<<monedasMax(moneda)<<endl;
		} return 0;
	}
