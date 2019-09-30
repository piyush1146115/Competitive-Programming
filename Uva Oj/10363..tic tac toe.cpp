#include<bits/stdc++.h>
using namespace std;
  char ch[5][5];
int check(char s){
int i, j;
    for(i = 0; i < 3; i++){
        if(ch[i][0] == s){
            if(ch[i][0] == ch[i][1] && ch[i][1] == ch[i][2])
                return 0;
        }
    }
    for(i = 0; i < 3; i++){
        if(ch[0][i] == s){
            if(ch[0][i] == ch[1][i] && ch[1][i] == ch[2][i])
                return 0;
        }
    }
    if(ch[0][0] == s){
        if(ch[0][0] == ch[1][1] && ch[1][1] == ch[2][2])
            return 0;
    }
    if(ch[0][2] == s){
        if(ch[0][2] == ch[1][1] && ch[1][1] == ch[2][0])
            return 0;
    }
    return 1;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int i, j, test, x, o, l = 0;


    cin >> test;
    //getchar();

    while(test--){
            x = 0;
            o = 0;
            for(i = 0; i < 3; i++)
                cin >> ch[i];

        for(i = 0; i < 3; i++){
            for(j = 0 ; j < 3; j++){

                if(ch[i][j] == 'X')
                    x++;
                else if(ch[i][j] == 'O')
                    o++;
            }
        }
       // printf("%d %d\n",x, o);
        if((x - o == 1)){
                  int r =   check('O');
            if(r)
            printf("yes\n");
            else printf("no\n");
        }
        else if(x == o){
                      int r =   check('X');
          //cout << r << endl;
            if(r)
            printf("yes\n");
            else printf("no\n");
        }
        else
            printf("no\n");
    }
    return 0;
}
