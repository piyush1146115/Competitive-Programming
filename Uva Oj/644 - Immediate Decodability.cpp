#include<bits/stdc++.h>
using namespace std;
int main()
{
    string num[15], s;
    int i, j, k = 0, l, a, c = 0;

    while(cin >> s)
    {
        num[k++] = s;
        if(s != "9"){
            continue;
        }
        c++;
        num[k - 1].clear();
        k--;
        int flag = 1;
        sort(num, num + k);

        for(i = 0; i < k - 1; i++){
            l = num[i].size();
            for(j = i + 1; j  < k;j++ ){
                if(num[j].size() >= num[i].size()){
                    for(a = 0; a < l; a++){
                        if(num[j][a] != num[i][a])
                            break;
                    }
                    if(a == l)
                        flag = 0;
                }
            }
            if(flag == 0)
                break;
        }
        k = 0;

        if(flag)
            printf("Set %d is immediately decodable\n",c);
        else
            printf("Set %d is not immediately decodable\n",c);
    }
    return 0;
}
