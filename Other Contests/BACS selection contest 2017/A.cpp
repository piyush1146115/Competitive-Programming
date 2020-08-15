#include<bits/stdc++.h>
using namespace std;
#define ll long long

int ara[1005];
int n;
bool isN(){
set<int> s;
for(int i = 0; i < n; i++)
    s.insert(ara[i]);

if(s.size() == 1)
    return 1;
else
    return 0;
}

bool allg()
{
    int flag = 1;
    for(int i = 1; i < n; i++)
        if(ara[i] < ara[i - 1])
        return 0;

    return 1;
}
bool allb()
{
    int flag = 1;
    for(int i = 1; i < n; i++)
        if(ara[i] > ara[i - 1])
        return 0;

    return 1;
}

int main()
{
 int test;
 cin >> test;

 while(test--){
     cin >> n;

    for(int i = 0; i < n; i++)
        cin >> ara[i];

    if(isN()){
        printf("neutral\n");
    }
    else if(allg()){
        printf("allGoodDays\n");
    }
    else if(allb()){
        printf("allBadDays\n");
    }
    else{
            int prev = 100000, cnt = 0,mx = -1;
        for(int i = 1; i < n - 1; i++)
        {
            if(ara[i] > ara[i - 1] && ara[i] > ara[ i + 1]){
                mx = max(mx, (i - prev));
                prev = i;
                cnt++;
            }
        }
        if(cnt < 2){
            printf("none\n");
        }
        else{
            printf("%d\n",mx - 1);
        }
    }
 }
}
