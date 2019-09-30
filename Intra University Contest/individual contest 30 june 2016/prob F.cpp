#include<bits/stdc++.h>
using namespace std;
int main()
{
    int c = 1, h = 1, i, j, x, y;

    cin >> x >> y;

    for(i = 1; ;i++){
        if(i % 2 == 1){
            if(y < 2){
                c = 0;
                break;
            }
            else if(x >= 2){
                x -= 2;
                y -= 2;
                continue;
            }
            else if(x == 1 && y >= 12){
                x -= 1;
                y -= 12;
                continue;
            }
            else if(x == 0 && y >= 22){
                y -= 22;
                continue;
            }
            else{
                c = 0;
                break;
            }
        }
        else{
            if(y < 2){
                h = 0;
                break;
            }
            if(y >= 22){
                y -= 22;
                continue;
            }
            else if(y >= 12 && x >= 1){
                x -= 1;
                y -= 12;
                continue;
            }
            else if(x >= 2){
                x -= 2;
                y -= 2;
                continue;
            }
            else{
                h = 0;
                break;
            }
        }
    }
    if(c){
        printf("Ciel\n");
    }
    else
        printf("Hanako\n");

    return 0;
}
