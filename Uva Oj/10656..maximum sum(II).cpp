#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int main()
{
    int n, num, cont, i;

    while(cin >> n, n){
            cont = 0;
        for(i = 1; i <= n; i++){
            scanf("%d",&num);
            if(num > 0){
                cont++;
                v.push_back(num);
            }
        }
        if(cont == 0){
            printf("0\n");
        }
        else{
            int l = v.size();
            for(i = 0; i < l; i++){
                printf("%d",v[i]);
                if(i != l - 1)
                    printf(" ");
            }
            printf("\n");
            v.clear();
        }
    }
    return 0;
}
