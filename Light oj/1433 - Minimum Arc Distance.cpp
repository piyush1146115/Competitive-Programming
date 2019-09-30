#include<bits/stdc++.h>
using namespace std;
struct point
{
	int x, y;
};

template<typename t> inline double distance(t a, t b)
{
	double dis = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)* (a.y - b.y));
	
	return dis;
}

template<typename t> inline t sq(t a)
{
	return a*a;
}

int main()
{
	point o, a, b;
	
	int test;
	
	scanf("%d", &test);
	
	for(int tc = 1; tc <= test; tc++)
	{
		scanf("%d %d %d %d %d %d",&o.x, &o.y, &a.x, &a.y, &b.x, &b.y);
		
		double oa, ob, ab;
		
		oa = distance(o, a);
		ob = distance(o, b);
		ab = distance(a, b);
		
		
		double angle ;
		
		angle = sq(oa) + sq(ob) - sq(ab);
		//angle /= (2 * ab*oa);
		 
		//double radius = oa;
		
		double ans = oa * angle;
		
		printf("Case %d: %.4lf\n",tc,ans);
		
	}
	return 0;
}
