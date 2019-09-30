#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> v1, v2;
int main()
{

    int n, b, a;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d %d", &b, &a);
        v1.push_back(b);
        v2.push_back(a);
    }

    if(v1 != v2){
        printf("rated\n");
    }
    else{
            int m = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++ ){
                if(v2[j] > v2[i]){
                    m = 1;
                    break;
                }
            }
        }

        if(m == 0){

            printf("maybe");
        }
        else{
            printf("unrated\n");
        }
    }
}

