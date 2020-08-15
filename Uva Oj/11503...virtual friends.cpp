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
#include <utility>
#include <set>
#include <math.h>
#define pi acos(-1.0)
#define N 1000000
using namespace std;

int parent [100000 + 10];

int findParent (int n)
{
    if ( parent [n] < 0 )
        return n;
    return parent [n] = findParent(parent [n]);
}

int main ()
{
    int testCase;
    scanf ("%d", &testCase);

    while ( testCase-- ) {
        int frndShipFormed;
        scanf ("%d", &frndShipFormed);

        memset (parent, -1, sizeof (parent));

        int indexing = 1;
        map <string, int> m;

        for ( int i = 0; i < frndShipFormed; i++ ) {
            string first, second;
            cin >> first >> second;

            if ( !m [first] )
                m [first] = indexing++;
            if ( !m [second])
                m [second] = indexing++;

            int p = findParent (m [first]);
            int q = findParent (m [second]);

            if ( p == q ) {
                printf ("%d\n", parent [p] * -1);
                continue;
            }

            if ( parent [p] < parent [q] ) {
                parent [p] += parent [q];
                parent [q] = p;
                printf ("%d\n", parent [p] * -1);
            }
            else {
                parent [q] += parent [p];
                parent [p] = q;
                printf ("%d\n", parent [q] * -1);
            }
        }
    }

    return 0;
}
