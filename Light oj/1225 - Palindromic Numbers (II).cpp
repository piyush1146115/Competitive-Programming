#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[100];
 
    int test;
 
    cin >> test;
 
    for(int tc = 1; tc <= test; tc++) {
        //cin >> s;
        scanf("%s",s);
        int flag = 0;
        int len = strlen(s);
       
        for(int i = 0; i < len/2; i++)
        if(s[i] != s[len- i - 1]){
        flag = 1;
      //  cout << s[i] << " " << s[s.size() - i] << " " << i + 1 << endl;
    }
       
        if(flag)
        printf("Case %d: No\n",tc);
        else
        printf("Case %d: Yes\n",tc);
    }
 
    return 0;
}
 
