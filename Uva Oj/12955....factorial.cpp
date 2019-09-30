#include<bits/stdc++.h>
using namespace std;
int fact[15];
void factorial()
{
    int i, j, f;

    for(i = 1; i <= 12; i++){
            f = 1;
        for(j = 1; j <= i; j++){
            f *= j;
        }
        fact[i] = f;
    }
}
int main()
{
    factorial();

    int n, i, j, sum, cont;

    while(cin >> n){
        for(i = 12; i >= 1; i--){
            if(fact[i] <= n){
                break;
            }
        }
        if(fact[i] == n){
            cout << "1\n";
        }
        else{
            sum = 0;
            cont = 0;
            for(j = i; j >= 1; j--){
                if(sum + fact[j] == n){
                    cont++;
                    break;
                }
                if(sum + fact[j] < n){
                    cont++;
                    sum += fact[j];
                    j++;
                    continue;
                }
            }
            cout << cont << endl;
        }
    }
    return 0;

}
