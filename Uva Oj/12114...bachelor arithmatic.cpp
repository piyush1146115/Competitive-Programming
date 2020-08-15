/*#include<bits/stdc++.h>
using namespace std;

int main()
{
    int s, b, bef, af;
    int casen = 0;

    while(scanf("%f %f", &b, &s) == 2 && (b != 0 || s != 0)){

        if(b == 1 || b == 0){
            printf("Case %d: :-\\\n",++casen);
        }
        else{
        bef = s / b;
        if(bef >= 1)
            bef = 1.0;

        af = (s - 1)/ (b - 1);

        if(af >= 1)
            af = 1.0;

        if(bef == af)
            printf("Case %d: :-|\n",++casen);
        else if(af > bef)
            printf("Case %d: :-)\n",++casen);
        else if(af < bef)
            printf("Case %d: :-(\n", ++casen);
    }
    }
    return 0;
}
*/

#include<stdio.h>
int main()
{
    int b,s,i=1;
    while(scanf("%d %d",&b,&s)==2)
    {
        if(b==0 && s==0)break;
        else if(b==1||b==0)printf("Case %d: :-\\\n",i++);
        else if(s>=b)printf("Case %d: :-|\n",i++);
        else if(b>s)printf("Case %d: :-(\n",i++);
    }
    return 0;
}

