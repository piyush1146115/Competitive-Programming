/*
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
*/
#include<stdio.h>
using namespace std;

int main()
{
    double h, u, d, f, pos,fat, ft;
    int count;

    while(scanf("%lf %lf %lf %lf", &h, &u, &d, &f) == 4 && h != 0){
        //fat = f / 100;
        pos = 0;
        ft = u * (f/100);
        pos = pos + u;
        count = 1;
        
        if(pos <= h){
        pos = pos - d;
        
        while(pos >= 0 && pos <= h){
            if(u > 0){
            u = u - ft;
            if(u < 0){
                u = 0;
            }
            }
            count++;
            pos = pos + u;
            if(pos < 0){
                break;
            }
            if(pos > h){
                break;
            }
            pos = pos - d;
            if(pos < 0){
                break;
            }
        }
        }
        
        if(pos > 0){
            printf("success on day %d\n",count);
        }
        else{
            printf("failure on day %d\n",count);
        }
    }
    return 0;
}
