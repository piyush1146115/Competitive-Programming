#include<bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	scanf("%d",&test);
	
	for(int tc = 1; tc <= test;tc++){
		int ax, ay, bx,by, cx, cy, dx,dy;
		scanf("%d %d %d %d %d %d",&ax, &ay, &bx, &by, &cx, &cy);
		
		dx = cx - (bx - ax);
		dy = cy - (by - ay);
		
		int r1 = abs(((ax * by) - (bx * ay)) + ((bx * cy) - (cx * by)) + ((cx * dy) - (dx * cy)) + ((dx * ay) - (ax * dy)));
		
		int ans = r1/2;
		
		printf("Case %d: %d %d %d\n",tc, dx, dy, ans);
	}
}
