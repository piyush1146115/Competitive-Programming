#include<bits/stdc++.h>
using namespace std;

double cap, mil_per_gal, init_cost, cost[55], dist[55], mid;
 int n;
 
 map< pair<int, double> , double >dp;
  
 double fun(int pos, double tank)
 {
	 if(pos == n + 1)
	 return 0.0;
	 
	 int type;
	 pair<int, double> pp;
	 pp.first = pos;
	 pp.second = tank;
	 
	 if(dp[pp] != 0.0)
	 return dp[pp];
	 
	 double dis = dist[pos + 1] - dist[pos];
	 double  need = dis/mil_per_gal;
	 double rem = tank - need;
	 double rem2 = cap - need;
	 double emp = cap - tank;
	 
	 if(rem < 0){
		 type = 1;
	 }
	 else if(tank <= mid){
		 type = 2;
	 } 
	 else{
		 type = 3;
	 }
	 double ans = (double)LONG_LONG_MAX;
	 
	 if(type == 1){
		 ans = min(ans, (emp * cost[pos]) + 2.00 + fun(pos + 1, rem2));
	 }
	 else if(type == 2)
	 {
		 ans = min(ans, (emp * cost[pos]) + 2.00 + fun(pos + 1, rem2));
		 ans = min(ans, fun(pos + 1, rem));
	 }
	 else{
		 ans = min(ans, fun(pos + 1, rem));
	 }
	 
	 return dp[pp] = ans;
 }
 
int main()
{
	double d;
	int tc = 0;
	
	while(scanf("%lf", &d) == 1){
		if(d < 0)
		return 0;
		
		scanf("%lf %lf %lf %d",&cap, &mil_per_gal, &init_cost, &n);
		
		cost[0] = init_cost;
		dist[0] = 0.0;
		dist[n + 1] = d;
		
		mid = cap/2.0;
		
		for(int i =  1; i <= n; i++)
		scanf("%lf %lf", &dist[i], &cost[i]);
		
		for(int i = 1; i <= n; i++)
		cost[i] = cost[i]/100.00;
		
		double dis = dist[1];
		double cos = dis/ mil_per_gal;
		 
		double ans = cost[0] + fun(1, cap - cos);
		printf("Data Set #%d\nminimum cost = $%.2lf\n",++tc,ans);
		dp.clear();
	}
	return 0;
}
