#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j, k;
    set <int> s;
    cin >> n;
    i = n + 1;
    while(1){
        j = i;
        while(j != 0){
          s.insert(j % 10);
          j /= 10;
        }
        if(s.size() >= 4){
            printf("%d\n",i);
            break;
        }
        i++;
        s.clear();
    }
    return 0;
}
