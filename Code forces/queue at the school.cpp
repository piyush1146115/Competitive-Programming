#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j, t, k;
    char s[60];

    cin >> n >> t;
    cin >> s;
while(t--){
    for(i = 0; i < n - 1; i++){
        if(s[i] == 'B' && s[i + 1] == 'G'){
       swap(s[i], s[i+ 1]);
       i++;
 }
}
}
    printf("%s\n", s);
    return 0;
}
