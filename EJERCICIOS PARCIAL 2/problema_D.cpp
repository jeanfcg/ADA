#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct segmento
{
	int left;
	int right;
};

bool comparar(const segmento &a, const segmento &b)
{
	return a.left < b.left;
}

int main()
{  
	int n;
	cin >> n;
	while ( n-- ) 
	{
		int m; 
		cin >> m;
		vector<segmento> S(1);
		while (cin >> S[0].left >> S[0].right, !(S[0].left == 0 && S[0].right == 0))
			S.push_back(S[0]);
		sort(S.begin() + 1, S.end(), comparar);
		int actual = 0, rReach = 0;
		size_t i = 1;
		vector<segmento> seg;
		while (rReach < m)
		{

			int nuevo = actual;
			size_t masLejos = 0;    
			for ( ; i < S.size(); ++i)
			{
				if (S[i].left > actual)
					break;
				else if (S[i].right >= nuevo)
				{
					nuevo = S[i].right;
					masLejos = i;
				}
			}
			if (masLejos == 0)
				break;
			seg.push_back(S[masLejos]);
			actual = rReach = nuevo;
		}
		if (rReach >= m)
		{
			cout << seg.size() << endl;
			for (size_t i = 0; i < seg.size(); ++i)
				cout << seg[i].left << " " << seg[i].right << endl;
		}
		else
			cout << "0" << endl;
		if (n)
			cout << endl;
	}
	return 0;
}
