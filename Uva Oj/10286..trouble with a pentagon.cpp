#include<stdio.h>
int main()
{
double a,b;
while(scanf("%lf",&a)==1)
{
b=1.0673956817111818692592637626711*a;
printf("%.10lf\n",b);
}
return 0;
}
/*
#include<iostream>
#include<cmath>

#define PI acos(-1)

using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    double l,x,conv=sin(72*PI/180)/sin(63*PI/180);

    while(cin>>l){
        x=conv*l;

        printf("%.10f\n",x);
    }
}
*/
