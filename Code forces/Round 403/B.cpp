#include<bits/stdc++.h>
using namespace std;
#define mxx 60005
double pos[mxx];
map<int, double> sp;
	int n;
	
	double m;

double calc(double d)
{
	double ans = 0.0;
	
	for(int i = 0; i < n; i++)
	{
		double dis = abs(pos[i] - d);
		double c = dis/ sp[i];
		ans = max ( ans, c);
	}
	
	return ans;
}

double ter()
{
	double lo = 0.0, hi = m;
	int cnt = 500;
	
	while(cnt--)
	{
		double a = ((2 * lo) + hi) / 3.0;
		double b = ((2*hi) + lo) / 3.0;
		//cout <<"a" <<  " " << a << " " << calc(a) << endl;
		//cout << "b" << " " << b << " " << calc(b) << endl << endl;
		
		if(calc(a) < calc(b)){
			//lo = a;
			hi = b;
		}
		else{
			lo = a;
		}
	}
	
	//printf("%.10lf\n", lo);
	double ans = 0.0;
	
	for(int i = 0; i < n; i++)
	{
		double dis = abs(pos[i] - lo);
		double c = dis/ sp[i];
		ans = max ( ans, c);
	}
	
	
	
	return ans;
}

int main()
{
	
	

	m = -11111111.0;
	scanf("%d" ,&n);
	
	for(int i = 0; i < n; i++)
	{
		scanf("%lf", &pos[i]);
		m = max(m, pos[i]);
	}
	
	double d;
	
	for(int i = 0; i < n; i++)
	{
		scanf("%lf", &d);
		sp[i] = d;
		//cout << sp[i] << endl;
	}
	
		double ans = ter();
		
		printf("%.10lf\n", ans);
		
		
}
