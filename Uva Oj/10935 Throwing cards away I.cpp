#include<bits/stdc++.h>
using namespace std;
int main()
{
    queue<int> q;
    vector<int> v;
    int i, j, k, n;

    while(scanf("%d",&n) == 1 && n != 0){

        for(i = 1; i <= n; i++){
            q.push(i);
        }

        while(!q.empty()){
            i = q.front();
            v.push_back(i);
            q.pop();
            if(!q.empty()){
                i = q.front();
                q.pop();
                q.push(i);
            }
        }

        printf("Discarded cards:");

       for(i = 0; i < v.size() - 1; i++)
        {
            if(i != v.size() - 2)
            printf(" %d,",v[i]);
            else
                printf(" %d",v[v.size() - 2]);
        }
        printf("\n");
    printf("Remaining card: %d\n",v[v.size() - 1]);
        v.clear();
    }
    return 0;
}
