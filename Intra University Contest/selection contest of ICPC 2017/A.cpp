#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x, y;
	
	cin>>x>>y;
    int d=sqrt(x*x+y*y);

    if(d*d==(x*x+y*y))
    {
        printf("black");
        return 0;
    }


    if(d % 2 == 1)
    {
        if((x>=0 && y<=0) || (x<=0 && y>=0)) printf("black");
        else printf("white");
    }
    else
    {
        if((x>=0 && y<=0) || (x<=0 && y>=0)) printf("white");
        else printf("black");
    }


//main();
}
