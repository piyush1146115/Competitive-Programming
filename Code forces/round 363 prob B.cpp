#include<bits/stdc++.h>
using namespace std;

int main()
{

    int i, j, k, l, r, c, con = 0;
    string s[1005];

    cin >> r >> c;

    for(i = 0; i < r; i++)
        cin >> s[i];

    int row = -1, col = -1;
    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            if(s[i][j] == '*'){
                con++;
            }
        }
    }
    int sum, flag = 0;
      for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            if(s[i][j] == '*'){
                    sum = 0;
                for(k = 0; k < c; k++){
                    if(s[i][k] == '*')
                    sum++;

                for(k = 0; k < r;k++)
                    if(s[j][k] == '*')
                    sum++;

                cout << "sum =" << sum << endl;
                if(sum == con){
                        flag = 1;
                        row= i;
                        col = j;
                    break;
                }
                }
            }
        }
    }

    if(flag){
        printf("YES\n");

        if(row >= 0){
            printf("%d", row + 1);
        }
        if(col >= 0){
            printf(" %d",col + 1);
        }

    }
    else
        printf("NO\n");

    return 0;
}
