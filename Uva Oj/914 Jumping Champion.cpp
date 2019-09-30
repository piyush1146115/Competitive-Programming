#include<bits/stdc++.h>
using namespace std;
#define mxx 1000005
bool chk[mxx + 5];
vector<int> prime;

void sieve()
{
    int i, j;

    for(i = 4; i < mxx ; i += 2)
        chk[i] = 1;
int     sq = sqrt(mxx);

    for( i =3; i <= sq; i+= 2){
        if(chk[i] == 0){
            for(j = i * i; j < mxx;j += i * 2 ){
                chk[j] = 1;
            }
        }
    }

    prime.push_back(2);

    for( i =3; i < mxx;i += 2){
        if(chk[i] == 0){
            prime.push_back(i);
        }
    }
}

int main()
{
    sieve();
    int lo, hi, test;

    scanf("%d",&test);

    while(test--){
            int ara[10000];

        memset(ara, 0, sizeof(ara));
        scanf("%d %d",&lo, &hi);

   // cout << prime.size();

    int dif = 0, ans;
        for(int i = 0; i < prime.size(); i++){
            if(prime[i] >= lo && prime[i] <= hi){
               // printf("%d\n", prime[i]);
               if(prime[i + 1] <= hi){
                    //cout << prime[i] << " " << prime[i +1] << endl;
                ara[prime[i + 1] - prime[i]]++;
                dif = max(ara[prime[i + 1] - prime[i]], dif);
               }
            }
            if(prime[i] > hi)
                break;
        }

        int flag = 0;

        for(int i = 0; i < 10000; i++){
            if(ara[i] == dif){
                flag++;
                ans = i;
            }
        }
        if(flag > 1){
            printf("No jumping champion\n");
        }
        else{
            printf("The jumping champion is %d\n",ans);
        }
    }
    return 0;
}
