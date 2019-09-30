#include<bits/stdc++.h>
using namespace std;
void pos(int n)
{
    int m = n % 7;

    if(m == 1){
        printf("Tuesday\n");
    }
    else if(m == 2){
        printf("Wednesday\n");
    }
    else if(m == 3){
        printf("Thursday\n");
    }
    else if(m == 4){
        printf("Friday\n");
    }
    else if(m == 5){
        printf("Saturday\n");
    }
    else if(m == 6){
        printf("Sunday\n");
    }
    else
        printf("Monday\n");
}

void neg(int n)
{
    int m = n % 7;

    if(m == 1){
        printf("Sunday\n");
    }
    else if(m == 2){
        printf("Saturday\n");
    }
    else if(m == 3){
        printf("Friday\n");
    }
    else if(m == 4){
        printf("Thursday\n");
    }
    else if(m == 5){
        printf("Wednesday\n");
    }
    else if(m == 6){
        printf("Tuesday\n");
    }
    else{
        printf("Monday\n");
    }
}

int main()
{
    int m, d, test;

    scanf("%d", &test);

    while(test--){

        scanf("%d %d", &m, &d);

        if(m == 1){
            if(d >= 10)
                pos(d - 10);
            else
                neg(10 - d);
        }
        else if(m == 2){
            if(d >= 21)
                pos(d - 21);
            else
                neg(21 - d);
        }
        else if(m == 3){
            pos(d);
        }
        else if(m == 4){
            if(d >= 4)
                pos(d - 4);
            else
                neg(4 - d);
        }
        else if(m == 5){
            if(d >= 9)
                pos(d - 9);
            else
                neg(9 - d);
        }
        else if(m == 6){
            if(d >= 6)
                pos(d - 6);
            else
                neg(6 - d);
        }
        else if(m == 7){
            if(d >= 11)
                pos(d - 11);
            else
                neg(11 - d);
        }
        else if(m == 8){
            if(d >= 8)
                pos(d - 8);
            else
                neg(8 - d);
        }
        else if(m == 9){
            if(d >= 5)
                pos(d - 5);
            else
                neg(5 - d);
        }
        else if(m == 10){
            if(d >= 10)
                pos(d - 10);
            else
                neg(10 - d);
        }
        else if(m == 11){
            if(d >= 7)
                pos(d - 7);
            else
                neg(7 - d);
        }
        else if(m == 12){
            if(d >= 12)
                pos(d - 12);
            else
                neg(12 - d);
        }


    }
}
