#include<bits/stdc++.h>
using namespace std;
int main()
{
   // freopen("input.txt", "r", stdin);

   string str;
   int i, j, k, sum;
   vector<int>v;

   while(getline(cin, str)){
    if(str[0] != '|')
        continue;

    for(i = 0; i < str.size(); i++){
        if(str[i] == 'o')
            v.push_back(1);
        else if(str[i] == ' ')
            v.push_back(0);
    }
    k = 1;
    sum = 0;
    for(i = v.size() -1; i >= 0; i--){
        if(v[i] == 1)
            sum += k;

        k *= 2;
    }
    printf("%c",sum);
    v.clear();
   }
   return 0;
}
