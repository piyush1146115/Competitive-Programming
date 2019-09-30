#include<bits/stdc++.h>
using namespace std;

int main()
{
//    int n;
//    scanf("%d",&n);
//    int fre[12] = {0};
//
//    for(int i=1;i<=n;i++)
//    {
//        int x = i;
//        while(x!=0)
//        {
//            fre[x%10]++;
//            x/=10;
//        }
//    }
//    for(int i=1;i<=9;i++)
//        cout<<i<<" ace = "<<fre[i]<<" bar "<<endl;
//    main();

    string s;
    cin>>s;
    if(s.size() == 1)
    {
        cout<<s<<endl;
        return 0;
    }
    int ck = 0,ans = s[0] -'0' ;
    for(int i=1; i<s.size(); i++){
        if(s[i]!='0')
        ans = min(ans,s[i] - '0');
        if(s[i] != '9'){
            ck = 1;
        }
    }

    if(ck)
        ans--;

    ans = max(1, ans);

        cout<<ans<<endl;
 //       main();
}
