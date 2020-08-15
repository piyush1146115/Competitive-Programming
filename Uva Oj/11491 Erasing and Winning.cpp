#include<bits/stdc++.h>
using namespace std;
#define mxx 100005

int st[30][mxx], a[mxx];
char s[mxx];

void create(int n)
{
    for(int i = 0; i < n; i++)
    {
        st[0][i] = i;
    }

    for(int k = 1; (1 << k) < n; k++){
        for(int i = 0; i + (1 << k) <= n; i++){

                int x = st[k - 1][i];
                int y = st[k - 1][i + (1 << (k - 1))];

                if(a[x] >= a[y])
                    st[k][i] = x;
                else
                    st[k][i] = y;
        }
    }
}


int query(int i, int j)
{
    int x, y;

    if(j - i > 1){
    int k =(int) log2(j-i+1);
    x = st[k][i];
     y = st[k][j-(1<<k)+1];
    }
    else{
        x = i;
        y = j;
    }
    return a[x] >= a[y] ? x : y;

}


int main()
{

    int n, d, i, j, k;

    while(scanf("%d %d",&n,  &d) == 2){

     if(n == 0 && d == 0)
        break;

        scanf("%s", s);

        for(i = 0; i < n; i++){
            a[i] = s[i] - 48;
        }

        create(n);

      int rem = n - d;
      int lo = 0, hi;

        while(rem != 0){
            hi = n - rem;
            k = query(lo, hi);
            printf("%d",a[k]);
            lo = k + 1;
            rem--;
        }
        printf("\n");

    }

    return 0;
}
