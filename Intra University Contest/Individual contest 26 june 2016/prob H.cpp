#include<bits/stdc++.h>
using namespace std;

struct point{
int x, y;
}s, e;

int main()
{
    int n, i, j, c = 0;
    string st;

    scanf("%d %d %d %d %d",&n, &s.x, &s.y, &e.x, &e.y);
        cin >> st;

        for(i = 0; i < n; i++){
                c++;
            if(st[i] == 'E'){
                if(e.x > s.x){
                    s.x++;
                }
            }
            else if(st[i] == 'S'){
                if(e.y < s.y){
                    s.y--;
                }
            }
            else if(st[i] == 'W'){
                if(e.x < s.x){
                    s.x--;
                }
            }
            else if(st[i] == 'N'){
                if(e.y > s.y){
                    s.y++;
                }
            }
               if(s.x == e.x && s.y == e.y)
            break;
        }
        if(i < n)
            cout << c;
        else
            printf("-1\n");

        return 0;
}
