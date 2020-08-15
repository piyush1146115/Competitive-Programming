#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int n, k, i, j;

    cin >> n >> k;

    if(k > n){
        printf("-1\n");
    }
    else if(n > 1 && k <= 1){
        printf("-1\n");
    }
    else{
      j = n - k + 2;
      if(n == 1)
        j = 1;
        i = 0;
    while(i < j){
        s.push_back('a');
        i++;
        if(i < j){
            s.push_back('b');
        i++;
        }
    }
    n -= j;
    i = 0;
    j = 2;
    while(i < n){
        s.push_back(j + 'a');
        j++;
        i++;
    }
    }
    cout << s << endl;
}
