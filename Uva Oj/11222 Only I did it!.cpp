#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int test ,i, j, t = 0, m, n, cnt[5];
    set <int> s1, s2, s3;
    cin >> test;

    while(test--){
            t++;
        cin >> n;
        for(i = 0; i < n; i++)
        {
            scanf("%d",&m);
            s1.insert(m);
        }

              cin >> n;
        for(i = 0; i < n; i++)
        {
            scanf("%d",&m);
            s2.insert(m);
        }

              cin >> n;
        for(i = 0; i < n; i++)
        {
            scanf("%d",&m);
            s3.insert(m);
        }

        set <int> :: iterator it;
        memset(cnt , 0, sizeof(cnt));
        for(it = s1.begin(); it != s1.end(); it++){
            if(s2.count(*it) == 0 && s3.count(*it) == 0)
                cnt[1]++;
        }

        for(it = s2.begin(); it != s2.end(); it++){
            if(s1.count(*it) == 0 && s3.count(*it) == 0)
                cnt[2]++;
        }

        for(it = s3.begin(); it != s3.end(); it++){
            if(s1.count(*it) == 0 && s2.count(*it) == 0)
                cnt[3]++;
        }
        int mx = -1;
        for(i =1; i <= 3; i++){
            if(cnt[i] > mx){
                mx = cnt[i];
            }
        }

    printf("Case #%d:\n", t);

        if(mx == cnt[1]){
                printf("1 %d",mx);
               for(it = s1.begin(); it != s1.end(); it++){
            if(s2.count(*it) == 0 && s3.count(*it) == 0)
                cout << " "<< *it ;
        }
          cout << endl;
        }
        if(mx == cnt[2]){
                 printf("2 %d",mx);
               for(it = s2.begin(); it != s2.end(); it++){
            if(s1.count(*it) == 0 && s3.count(*it) == 0)
                 cout << " "<< *it ;
        }
          cout << endl;
        }
        if(mx == cnt[3]){
                   printf("3 %d",mx);
             for(it = s3.begin(); it != s3.end(); it++){
            if(s1.count(*it) == 0 && s2.count(*it) == 0)
                 cout << " "<< *it ;
        }
          cout << endl;
        }

        s1.clear();
        s2.clear();
        s3.clear();
    }
    return 0;
}
