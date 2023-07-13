#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

struct punto{
	double x;
	double y;
};

double comb(punto a[],int low,int mid,int high,double min_left,double min_right);
bool distanciaCal(punto a,punto b)
{
	return a.x<b.x; 
}

double distancia(punto a,punto b)
{
	return (double)sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2)); 
}

double div(punto a[],int low,int high)
{
	if(low>=high) return 99999;  
	
	int mid=(low+high)/2;
	double min_left=div(a,low,mid);
	double min_right=div(a,mid+1,high);
	return comb(a,low,mid,high,min_left,min_right); 
}

double comb(punto a[],int low,int mid,int high,double min_left,double min_right)
{
	double d=(min_left<min_right)?min_left:min_right;
	double line=(double)(a[mid].x+a[mid+1].x)*0.5; 
	double min=d;
	for(int i=mid+1;a[i].x<line+d && i<=high;i++){ 
		for(int j=mid;a[j].x>line-d && j>=low;j--){
			double temp=distancia(a[i],a[j]);
			if(temp<min) min=temp;
		}
	}
	return min;
}
int main()
{
	int ent;
	punto p[10001];
	while(cin>>ent)
	{
		if (ent==0){
			break;
		}
		for(int i=0;i<ent;i++){
			cin>>p[i].x>>p[i].y;
		}
		
		sort(p,p+ent,distanciaCal);
		double dis=div(p,0,ent-1);

		if(dis>=10000.0) {
			cout<<"INFINITY\n"<<endl;
		} 
		else {
			printf("%.4lf\n",dis);
		}
	}
	return 0;
}

