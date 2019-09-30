/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, inc, i, j, k, m, n,rem;
    vector <int> v;

    while(scanf("%d", &n) == 1 && n  != 0)
    {
        m = n;
        rem = 1;
        inc = 0;
        while(rem != 2){
        inc++;
        m = n;
        a = 1;
        for(i = 1; i <= n;i++){
            v.push_back(i);
        }

        while(v.size() > 1){

            if(a > m && a % m == 0)
                a = m;
            else if(a != m)
                a = a % m;

        v.erase(v.begin() + (a - 1));

        m--;
        a += inc;
        a--;
        }
        rem = v[0];
        v.clear();
    }
    cout << inc << endl;
    }
    return 0;
}
*/
#include<cstdio>

using namespace std;

int main(){
    int n,x,pos,cont,cities;
    bool ok;

    while(1){
        scanf("%d",&n);
        if(n==0) break;

        for(int x=2;;x++){
            cities=n-1;
            pos=(x-1)%cities;
            ok=true;

            while(cities>1){

                if(pos==0){/**because we have reach to last city..and if we increment now by 2 we will
                                    never end in 2 as we first cut city 1.*/
                    ok=false;
                    break;
                }

                cities--;
                pos=(pos+x-1)%cities;
            }

            if(ok){
                printf("%d\n",x);
                break;
            }
        }
    }

    return 0;
}

