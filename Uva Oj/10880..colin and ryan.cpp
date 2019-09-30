#include<bits/stdc++.h>
using namespace std;
vector <long long int>q;
int main()
{
    long long int c, r, i, j, k, test, g, casen = 0, sqr;

    cin >> test;

    while(test--){
            casen++;
        cin >> c >> r;

        g = c - r;
        printf("Case #%lld:",casen);

        if(c == r)
        {
            printf(" 0\n",casen);
        }
        else
        {
            sqr = sqrt(g);

            for(i = 1; i <= sqr; i++){
                if(g % i == 0){
                    j = g / i;
                    if(i > r){
                        q.push_back(i);
                    }
                    if(j > r && i != j){
                        q.push_back(j);
                    }
                    if(j < r)
                        break;
                }
            }
            sort(q.begin(), q.end());

            k = q.size();
            for(i = 0; i < k; i++){
                printf(" %lld",q[i]);
            }
            printf("\n");
            q.clear();
        }

    }
    return 0;
}
