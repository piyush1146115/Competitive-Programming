#include<bits/stdc++.h>
using namespace std;
int ara[35005];
vector <int> prime, det[500];

void sieve()
{
    int i, j, k, l;
    for(i = 3; i <= 190; i += 2){
        if(ara[i] == 0){
            for(j = i * i; j <= 35000; j += (i + i)){
                ara[j] = 1;
            }
        }
    }
    for(i = 3; i <= 34500; i += 2){
        if(ara[i] == 0)
            prime.push_back(i);
    }
    k = 0;
    for(i = 0; prime[i] <= 34000; i++){
        if((prime[i + 1] - prime[i]) == (prime[i + 2] - prime[i + 1])){
                l = 2;
            det[k].push_back(prime[i]);
            det[k].push_back(prime[i + 1]);
            det[k].push_back(prime[i + 2]);
            j = 3;
            while((prime[i + j] - prime[i + j -1]) == (prime[i + 1] - prime[i])){
                det[k].push_back(prime[i +j]);
                l++;
                j++;
            }
            i += l;
            k++;
        }
    }
   /* for(i = 0; i < k; i++){
        for(j = 0; j < det[i].size(); j++){
            printf("%d ",det[i][j]);
        }
        printf("\n");
    }*/
}
int main()
{
    sieve();
    int i, j, up, down, l;
    while(scanf("%d %d",&up, &down) == 2){
            if(up == 0 && down == 0)
            break;
        if(down > up)
            swap(up, down);

        for(j = 0; j < 166; j++){
                l = det[j].size() - 1;
            if(det[j][0] >= down && det[j][l] <= up){
                printf("%d",det[j][0]);
                for(i = 1; i <= l; i++)
                    printf(" %d",det[j][i]);

                printf("\n");
            }
        }
    }
    return 0;
}
/*
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <bitset>
#include <utility>
#include <set>
#include <math.h>
#define pi acos(-1.0)
#define N 1 << 15
using namespace std;

bool mark [N];
vector <int> primeList;

void sieve ()
{
    memset (mark, true, sizeof(mark));

    mark [0] = mark [1] = false;

    for ( int i = 4; i < N; i += 2 )
        mark [i] = false;

    for ( int i = 3; i * i <= N; i += 2 ) {
        if ( mark [i] ) {
            for ( int j = i * i; j < N; j += 2 * i )
                mark [j] = false;
        }
    }

    primeList.clear ();
    primeList.push_back (2);

    for ( int i = 3; i < N; i += 2 ) {
        if ( mark [i] )
            primeList.push_back (i);
    }

    //printf ("%d\n", primeList.size ());
}

void print (int here, int there)
{
    printf ("%d", primeList [here]);

    for ( int i = here + 1; i <= there; i++ )
        printf (" %d", primeList [i]);
    printf ("\n");
}

int main ()
{
    sieve ();

    int x, y;

    while ( scanf ("%d %d", &x, &y) ) {
        if ( x == 0 && y == 0 ) break;

        if ( x > y )
            swap (x, y);

        size_t i = 0;

        while ( primeList [i] < x )
            i++;

        while ( primeList [i + 2] <= y ) {
            if ( primeList [i + 2] - primeList [i + 1] == primeList [i + 1] - primeList [i] ) {
                int startIndex = i;
                int endIndex = i + 2;
                int diff = primeList [i + 1] - primeList [i];
                while ( i + 3 < primeList.size () && primeList [i + 3] - primeList [i + 2] == diff ) {
                    endIndex++;
                    i++;
                }

                if ( primeList [endIndex] <= y ) {
                    if ( startIndex == 0 || primeList [startIndex] - primeList [startIndex - 1] != diff)
                        print (startIndex, endIndex);
                }
                else break;
            }
            i++;
        }
    }

    return 0;
}

// @END_OF_SOURCE_CODE
*/
