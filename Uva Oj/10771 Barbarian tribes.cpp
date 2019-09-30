#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m, n, inn, inm, s, pos, i, j, k, sum;

    while(scanf("%d %d %d",&m, &n, &k) == 3){
        if(m == 0 && n == 0 && k == 0)
            break;

        s = m + n;
        pos = 1;

        for(i = 1; i < s; i++){
            inm = m;
            inn = n;
            sum = m + n;
            j = 2;
            while(j--){
                    sum = m + n;
                pos = (pos + (k- 1)) % sum;
               // cout << pos << endl;
                if(pos == 0){
                    pos = sum;
                }
                if(pos <= m){
                    m--;
                }
                else{
                    n--;
                }
            }
            if(m != inm && n != inn){
                n++;
            }
            else{
                m++;
            }
        }
       // cout << m <<" " <<  n << endl;
        if(m >= 1){
            printf("Gared\n");
        }
        else
        {
            printf("Keka\n");
        }
    }
    return 0;
}
