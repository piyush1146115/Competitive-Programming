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
using namespace std;

unsigned long long int h[50010];

int lowerbound(unsigned long long key, int n)
{
    int begin, end, mid;
    end = n -1;
    begin = 0;

    while(begin <= end){
        mid = (begin + end)/2;

        if(h[mid] == key){
            //index = mid;
            end = mid - 1;
        }
        else if(key < h[mid]){
            end = mid - 1;
        }
        else if(key > h[mid]){
            begin = mid + 1;
        }
    }
    return begin;
}
int upperbound(unsigned long long key, int n)
{
    int begin, end, mid;
    end = n -1;
    begin = 0;

    while(begin <= end){
        mid = (begin + end)/2;

        if(h[mid] == key){
            //index = mid;
            begin = mid + 1;
        }
        else if(h[mid] > key){
            end = mid - 1;
        }
        else if(h[mid] < key){
            begin = mid + 1;
        }
    }
    return end;
}

int main()
{
    int n, a, i, j, q;
    unsigned long long int b, p[25005];

    scanf("%d", &n);

    for(a = 0; a < n; a++){
        scanf("%llu", &h[a]);
    }

    scanf("%d", &q);

    for(a = 0; a < q; a++)
        scanf("%llu",&p[a]);


    for(a = 0; a < q; a++){
        if(p[a]  <= h[0]){
            printf("X ");
        }
        else{
        i = lowerbound(p[a], n);
        printf("%llu ",h[i - 1]);
        }

        if(p[a] >= h[n - 1]){
            printf("X\n");
        }
        else{
        j = upperbound(p[a], n);
        printf("%llu\n",h[j + 1]);
        }
    }

    return 0;
}
