#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long

int N, M;

ll DP[101][11][3][1025];

ll fun(int pos, int num,int isStart, int mask)
{

//            cout << pos << " " << num << " "<<  mask << endl;
//            getchar();
    if(pos == M)
    {
        if(mask == ((1 << N) - 1))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    ll ret = 0;

//      if(mask == ((1 << N) - 1)){
//           ret = 1;
//        }

		if(DP[pos][num][isStart][mask] != -1){
			return DP[pos][num][isStart][mask];
		}

    if(isStart == 0)
    {
        ret += fun(pos + 1, 0, 0, 0);
        for(int i = 1; i < N; i++)
        {
            ret += fun(pos + 1, i, 1, mask|(1 << i));
            ret %= MOD;
        }
    }
    else
    {

        int n_num = (num + 1)%N;
        if(abs(n_num - num) == 1)
        {
            ret += fun(pos + 1,n_num,isStart, mask|(1 << n_num));
        }

        ret %= MOD;

        int n_num2 = (num - 1)%N;
        if(n_num2 < 0)
        {
            n_num2 += N;
        }
        if(abs(n_num2 - num) == 1 && n_num2 != n_num)
        {
            ret += fun(pos + 1,n_num2,isStart, mask|(1 << n_num2));
        }
    }
    ret %= MOD;

    DP[pos][num][isStart][mask] = ret;
    return ret;
}

int main()
{
    int test;
    scanf("%d", &test);

    while(test--)
    {
        scanf("%d %d", &N, &M);
        ll ans = 0;
      memset(DP, -1 , sizeof(DP));

        ans = fun(0, 0,0, 0);


        printf("%lld\n",ans);
    }
}
