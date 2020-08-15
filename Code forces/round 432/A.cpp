#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define eps 1e-9
int main()
{
	double inf = 100000000000.0;
	double a1, a2, b1, b2, c1, c2;
	
	scanf("%lf %lf %lf %lf %lf %lf", &a1, &a2, &b1, &b2, &c1, &c2);
	double x1, x2, y1, y2;
	
	x1 = (b1 - a1);
	x2 = (c1 - a1);
	y1 = (b2 - a2);
	y2 = abs(c2 - a2);
	
	double d1, d2;
	if(x1 == 0.0){
		d1 = inf;
	}
	else{
		d1 = y1/x1;
	}
	if(x2 == 0.0){
		d2 = inf;
	}
	else{
		d2 = y2/x2;
	}
	

	
		double ds1 = x1  + y1;
		double ds2 = c1 - b1  + c2 - b2;
		
		if(ds1 == ds2){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	
	main();
}

