//#include<bits/stdc++.h>
//using namespace std;
//#define ll long long
//int main()
//{
//    ll q;
//    scanf("%I64d", &q);
//
//    for(int i = 0; i < q; i++){
//            ll n;
//        scanf("%I64d", &n);
//
//        ll div = n / 4;
//        ll mod = n % 4;
//        if(n <= 3)
//            printf("-1\n");
//        else if( n <= 7 && n % 2 == 0 ){
//            printf("1\n");
//        }
//        else if( n <= 7 && n % 2 != 0){
//            printf("-1\n");
//        }
//        else if(mod % 2 == 0)
//            printf("%I64d\n", div);
//        else
//            printf("%I64d\n", div - 1);
//    }
//}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long q,val;
    cin>>q;
    while(q--)
    {
        cin>>val;
        if(val<=3) cout<<-1<<endl;
        else
        {
            if(val%2 == 1)
            {
                  int ck = 0;
                val-=9;
                if(val<0)
                {
                    ck = 1;
                    cout<<-1<<endl;
                }

                else if(val%4 == 0)
                {
                    ck = 1;
                    cout<<val/4 + 1<<endl;
                }
                else
                {

                    long long f = val/4;
                    if(f!=0)
                    {
                        ck = 1;
                        cout<<f + 1<<endl;
                    }
                }
                if(ck == 0) cout<<-1<<endl;
            }

            else
            {
                if(val%4 == 0)
                    cout<<val/4<<endl;
                else
                {
                    long long f = val/4;
                    cout<<f<<endl;
                }
            }

        }
    }
   // main();
}
