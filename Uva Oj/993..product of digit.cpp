#include<bits/stdc++.h>
using namespace std;

vector<int> ans;
int flag;

void factorization(long long int n)
{
    int i;
    flag = 0;
    if(n < 10){
        ans.push_back(n);
        return;
    }
    else{
		
        for(i = 9; i >= 2; i--){
            if(n % i == 0){
                while(n % i == 0){
                    n = n / i;
                    ans.push_back(i);
                }
            }
        }
        
        if(n >= 10){
            flag = 1;
        }
        else if(n < 10 && n != 1){
            //ara[k++] = n;
			ans.push_back(n);
        }
    }
}

int main()
{
    long long int n;

   
        scanf("%lld",&n);
        
        factorization(n);
        
        if(flag){
            printf("-1\n");
            ans.clear();
        }
        else{

            sort(ans.begin(), ans.end());
		//	unsigned long long int res = 0, cnt = 1;
            if(ans.size() == 1)
            printf("1");
            for(int i = 0; i < ans.size(); i++)
            {
				printf("%d",ans[i]);
            }
            printf("\n");
            ans.clear();
        }
    
    return 0;
}
