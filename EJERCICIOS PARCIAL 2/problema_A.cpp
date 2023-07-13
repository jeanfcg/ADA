#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main(int argc, char *argv[]) {
	
	int a;
	int b = 0;
	vector<int>array;
	
	while(cin>>a){
		array.push_back(a);
		sort(array.begin(), array.end());
		
		if(b % 2 == 0){
			int m = (0 + b)/2;
			cout<<array[m]<<endl;
		} else {
			int m = (0 + b)/2;
			int min = m+1;
			int res = (array[m] + array[min])/2;
			cout<<res<<endl;
		} b++;
	} return 0;
}
