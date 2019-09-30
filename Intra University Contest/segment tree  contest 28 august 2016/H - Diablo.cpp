#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
    int i, j, k, n, test, cs = 0, q;

    scanf("%d",&test);

    while(test--){

        scanf("%d %d", &n, &q);
        for(i = 0; i < n; i++){
            scanf("%d", &k);
            v.push_back(k);
        }

        printf("Case %d:\n",++cs);

        while(q--){

            getchar();
            char ch;

            scanf("%c %d",&ch, &k);

            if(ch == 'a'){
                v.push_back(k);
            }
            else{
            if(k <= v.size()){
                    printf("%d\n",v[k - 1]);
                v.erase(v.begin() + (k - 1));
            }
            else{
                printf("none\n");
            }
        }
    }
    v.clear();
    }
    return 0;
}
