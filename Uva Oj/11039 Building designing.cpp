#include<bits/stdc++.h>
using namespace std;
bool comp(int a, int b){
return abs(a) > abs(b);
}

int main()
{
    ///freopen("input.txt", "r", stdin);
    int test, i, j, n, ans,po, ng;
    vector<int> pos;
    scanf("%d",&test);

    while(test--){
        scanf("%d",&n);

        for(i = 0; i < n; i++){
            scanf("%d",&j);
            pos.push_back(j);
        }
         po = 0, ng = 0;
        sort(pos.begin(), pos.end(), comp);
        ///sort(neg.begin(), neg.end(), comp);
        i = 0;
            while(i < pos.size()){

                while(i < pos.size()){
                    if(pos[i] > 0){
                        ng++;
                        break;
                    }
                    i++;
                }
                while(i < pos.size()){
                    if(pos[i] < 0){
                        ng++;
                        break;
                    }
                    i++;
                }
            }

        i = 0;
            while(i  < pos.size()){
                while(i < pos.size()){
                    if(pos[i] < 0){
                        po++;
                        break;
                    }
                    i++;
                }
                while(i < pos.size()){
                    if(pos[i] > 0){
                        po++;
                        break;
                    }
                    i++;
                }
            }
        ans = max(po, ng);
        cout << ans << endl;
        pos.clear();
        //neg.clear();

    }
    return 0;
}
