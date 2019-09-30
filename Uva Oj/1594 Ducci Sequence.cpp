#include<bits/stdc++.h>
using namespace std;
vector<int> v, v2;
int n;
void f()
{
    int i;

    for(i = 0; i < n; i++){
        v[i] = abs(v[i + 1] - v[i]);
    }
}
int main()
{
    int i, j, k, test, loop, zero, flag;
    map<vector<int> , int> m;

    scanf("%d", &test);

    while(test--){
        scanf("%d", &n);

        for(i = 0; i < n; i++){
            scanf("%d", &j);
            v.push_back(j);
        }

        loop = 0;
        zero = 0;

        while(1){
                        flag = 1;
            for(i = 0; i < n; i++){
                if(v[i] > 0)
                {
                    flag = 0;
                    break;
                }
            }
            if(flag)
            {
                zero = 1;
                break;
            }

            m[v]++;
            if(m[v] > 1)
            {
                loop = 1;
                break;
            }

            v.push_back(v[0]);
            f();
            v.pop_back();
        }
        if(loop == 1){
            printf("LOOP\n");
        }
        else{
            printf("ZERO\n");
        }
        m.clear();
        v.clear();
    }
    return 0;
}
