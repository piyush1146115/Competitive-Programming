#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector <long long int> vec;
    int n, m, i, j, l, flag = 0, casen = 0;
    int ara[105];

    while(scanf("%d", &n) == 1){
            flag = 0;
        for(i = 0; i < n; i++){
            scanf("%d", &ara[i]);

        }
        for(i = 0; i < n - 1; i++)
        {
             if(ara[i] < 1 || ara[i] > ara[i + 1]){
                flag = 1;
                break;
             }
        }

        if(flag == 0){
        for(i = 0; i < n ; i++){
            for(j = i ;j < n; j++ ){
                vec.push_back(ara[i] + ara[j]);
            }
        }

       l = vec.size();

       for(i = 0; i < l ; i++){
            for(j = 0; j < l; j++){
                    if(i == j)
                    continue;

                if(vec[i] == vec[j]){
                   flag = 1;
                    break;
                }
            }
            if(flag == 1){
                break;
            }
       }
    }
       printf("Case #%d: ",++casen);

        if(flag == 0){
            printf("It is a B2-Sequence.\n\n");
        }
        else{
            printf("It is not a B2-Sequence.\n\n");
        }
        vec.clear();
    }
    return 0;
}
