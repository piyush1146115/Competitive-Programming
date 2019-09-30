#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define mxx 100005

int fr[mxx], bck[mxx];
int I[mxx], LF[mxx], LB[mxx];
int n;

void reset()
{
    I[0] = -inf;

    for(int i = 1; i <= n; i++)
        I[i] = inf;

}

void longest_2()
{
    reset();
    //cout << "ok\n";

    for(int i = 0; i < n; i++){

        int k = bck[i];

        int lo = 0, hi = n - 1,mid, ans = 0;

        while(lo <= hi){
            mid = (lo + hi)/2;
            if( k > I[mid]){
                ans = mid + 1;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }

            LB[i] = ans;
            I[ans] = k;
    }
    int mx = 1;
    for(int i = 0; i < n;i++){
        mx = max(mx, LB[i]);
        LB[i] = mx;
    }

    for(int i = 0; i < n/2; i++)
    swap(LB[i], LB[n - i -1]);

}


void longest_1()
{
    reset();
    //cout << "ok\n";

    for(int i = 0; i < n; i++){

        int k = fr[i];

        int lo = 0, hi = n  - 1,mid, ans = 0;

        while(lo <= hi){
            mid = (lo + hi)/2;
            if( k > I[mid]){
                ans = mid + 1;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }

            LF[i] = ans;
            I[ans] = k;
    }
    int mx = 1;
    for(int i = 0; i < n;i++){
        mx = max(mx, LF[i]);
        LF[i] = mx;
    }
}


void calc()
{
    int mx = 1;

    for(int i = 0; i < n; i++)
    {
        if((LF[i]) == LB[i] ){//&& LB[i + 1] > 1){
            mx = max(mx, (LF[i]+ LB[i] - 1));
        }
    }
     for(int i = n - 1; i >= 0; i--)
    {
        if((LB[i]) == LF[i] ){//&& LF[i - 1] > 1){
            mx = max(mx, (LF[i]+ LB[i] - 1));
        }
    }
//    for(int i = 0; i < n - 1; i++){
//        printf("LF[%d] = %d LB[%d] = %d\n",i, LF[i], i + 1, LB[i + 1]);
//    }

    printf("%d\n",mx);
}
int main()
{

    while(scanf("%d", &n) == 1){

        for(int i = 0; i < n; i++)
            scanf("%d", &fr[i]);


        for(int i = 0; i < n; i++)
           bck[i] = fr[n - i - 1];

//            for(int i = 0; i < n; i++)
//                printf("%d ",bck[i]);

         //   printf("\n");
           longest_1();
           longest_2();
           calc();
    }
}
