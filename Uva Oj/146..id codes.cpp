#include<bits/stdc++.h>
using namespace std;
int main()
{
    char word[60];
freopen("input.txt", "r", stdin);
freopen("ouput.txt", "wt", stdout);

    while(gets(word)){
            if(word[0] == '#')
                break;

        int len = strlen(word);
        if(len == 1)
            printf("No Successor\n");
        else{
            int i;
            for(i =  0; i < len -1; i++)
                if(word[i] < word[i + 1])
                break;

            if(i == len -1){
                printf("No Successor\n");
            }
            else{
                for(i = len - 2; i >= 0;i--){
                    swap(word[i], word[i + 1]);
                    if(word[i] > word[i + 1])
                        break;
                }
            printf("%s\n",word);
            }
        }
    }
    return 0;
}
/*
#include<iostream>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
#include<queue>

using namespace std;

#define INF (1<<29)
#define SET(a) memset(a,-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define CLR(a) memset(a,0,sizeof(a))
#define FILL(a,v) memset(a,v,sizeof(a))
#define PB push_back
#define FOR(i,n) for(int i = 0;i<n;i++)
#define PI acos(-1.0)
#define EPS 1e-9
#define MP(a,b) make_pair(a,b)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define LL long long
#define MX 100000
#define MOD 1000000007




int main()
{
    char s[100];
    while(cin>>s)
    {
        if(s[0]=='#') break;

        int len=strlen(s);

        if(next_permutation(s,s+len))
            cout<<s<<endl;
        else
            cout<<"No Successor"<<endl;
    }
return 0;
}
*/
