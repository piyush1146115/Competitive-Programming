#include<bits/stdc++.h>
using namespace std;
int main()
{
    int cont[50], i, j, k, test, sum, cost;
    string s;

    scanf("%d",&test);
    getchar();
    while(test--){
        getline(cin, s);
        memset(cont, 0, sizeof(cont));

        for(i = 0; i < s.size(); i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                cont[s[i] - 'A']++;
            }
            if(s[i] >= '0' && s[i] <= '9'){
                cont[s[i] - '0' + 26]++;
            }
        }

        sort(cont, cont + 36);

        k = 35;
        cost = 1;
        sum = 0;
      /*  for(i = 35; i >= 0; i--)
            printf("%d\n",cont[i]);*/

        for(i = 1; i <= 6; i++){
            cost++;
            for(j = 1; j <= i; j++){
                sum += (cont[k] * cost);
               // cout << sum << endl;
                k--;
            }
        }

         for(i = 5; i >= 1; i--){
            cost++;
            for(j = 1; j <= i; j++){
                sum += (cont[k] * cost);
                k--;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
