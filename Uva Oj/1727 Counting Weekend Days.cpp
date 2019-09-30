#include<bits/stdc++.h>
using namespace std;
int main()
{
    string mon, day;
    int i, j, k, test;

    scanf("%d", &test);

    while(test--){
        cin >> mon >> day;

        if(mon == "APR" || mon == "JUN" || mon == "SEP" || mon == "NOV"){
            if(day == "FRI"){
                printf("10\n");
            }
            else if(day == "SAT" || day == "THU"){
                printf("9\n");
            }
            else{
                printf("8\n");
            }
        }
        else if(mon == "FEB"){
            printf("8\n");
        }
        else{
            if(day == "FRI" || day == "THU"){
                printf("10\n");
            }
            else if(day == "WED" || day == "SAT"){
                printf("9\n");
            }
            else
                printf("8\n");
        }
    }
    return 0;
}
