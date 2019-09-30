
#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt","rt",stdin);
    int h1, h2, m1, m2, t1, t2, t3, t4;
    int test, i, caseno = 0;

    scanf("%d", &test);

    while(test--){
        scanf("%d:%d %d:%d",&h1, &m1, &h2, &m2);

        t1 = (h1 * 60) + m1;
        t2 = (h2 * 60) + m2;

        scanf("%d:%d %d:%d",&h1, &m1, &h2, &m2);

        t3 = (h1 * 60) + m1;
        t4 = (h2 * 60) + m2;

        if(t2 < t3 || t1 > t4)
            printf("Case %d: Hits Meeting\n",++caseno);
            else
            printf("Case %d: Mrs Meeting\n", ++caseno);


    }
    return 0;
}
/*
#include <stdio.h>

int main() {
    int testcase, cases = 0;
    scanf("%d", &testcase);
    while(testcase--) {
        int sh, sm, eh, em;
        scanf("%d:%d %d:%d", &sh, &sm, &eh, &em);
        sh = sh*60 + sm, eh = eh*60 + em;
        int ah, am, bh, bm;
        scanf("%d:%d %d:%d", &ah, &am, &bh, &bm);
        ah = ah*60 + am, bh = bh*60 + bm;
        printf("Case %d: ", ++cases);
        if(eh < ah || sh > bh)
            puts("Hits Meeting");
        else
            puts("Mrs Meeting");
    }
    return 0;
}
*/
