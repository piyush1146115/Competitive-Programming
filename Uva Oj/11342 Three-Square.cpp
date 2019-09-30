#include<bits/stdc++.h>
using namespace std;
vector <int> v[50005];
void three(){
    int i, j, k, sum;
for(i = 0; i*i <= 50000; i++){
    for(j = 0; (i*i + j *j) <= 50000; j++){
        for(k = 0; k < 50000; k++){
            sum = i *i + j*j + k*k;
            if(sum > 50000)
                break;
            else{
                v[sum].push_back(i);
                v[sum].push_back(j);
                v[sum].push_back(k);
            }
        }
    }
}
}
int main()
{
    three();
    int i, n, test;

    cin >> test;

    while(test--){
        scanf("%d",&n);
        if(v[n].empty()){
            printf("-1\n");
        }
        else
        {
            printf("%d %d %d\n",v[n][0], v[n][1], v[n][2]);
        }
    }
   return 0;
}
