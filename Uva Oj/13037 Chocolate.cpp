#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    set <int> s1, s2, s3;
    int i, j, l, r, s, test, t = 0, le[100005], ra[100005], se[100005];

    cin >> test;

    while(test--){
        t++;
        scanf("%d %d %d",&l, &r, &s);

        for(i = 0; i < l; i++){
            scanf("%d",&le[i]);
            s1.insert(le[i]);
        }

        for(i = 0; i < r; i++){
            scanf("%d",&ra[i]);
            s2.insert(ra[i]);
        }

        for(i = 0; i < s; i++){
            scanf("%d",&se[i]);
            s3.insert(se[i]);
        }
        int c1[5] , c2[5];
        memset(c1, 0, sizeof(c1));
        memset(c2, 0, sizeof(c2));

        set <int> ::  iterator it;
        for(it = s1.begin(); it != s1.end(); it++){
            if(s2.count(*it) == 0 && s3.count(*it) == 0)
                c1[1]++;
            if(s2.count(*it) == 0 && s1.count(*it) > 0 && s3.count(*it) > 0)
                c2[2]++;
            if(s3.count(*it) == 0 && s1.count(*it) > 0 && s2.count(*it) > 0)
                c2[3]++;
        }

               for(it = s2.begin(); it != s2.end(); it++){
            if(s1.count(*it) == 0 && s3.count(*it) == 0)
                c1[2]++;
                if(s1.count(*it) == 0 && s2.count(*it) > 0 && s3.count(*it) > 0)
                    c2[1]++;
        }

        for(it = s3.begin(); it != s3.end(); it++){
            if(s1.count(*it) == 0 && s2.count(*it) == 0)
                c1[3]++;
        }

        s1.clear();
        s2.clear();
        s3.clear();

        printf("Case #%d:\n",t);

        for(i = 1; i <= 3; i++)
            printf("%d %d\n",c1[i], c2[i]);
    }
    return 0;
}
