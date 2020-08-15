#include<bits/stdc++.h>
using namespace std;
struct date
{
    char name[20];
    int day;
    int month;
    int year;
};
struct date bday[105];
struct date temp;
int main()
{
    int n, i, j;

    scanf("%d", &n);

    for(i = 0; i < n; i++){
        scanf("%s %d %d %d",bday[i].name, &bday[i].day, &bday[i].month, &bday[i].year);

        for(j = i; j >= 1; j--){
            if(bday[j - 1].year > bday[j].year){
                temp = bday[j];
                bday[j] = bday[j - 1];
                bday[j - 1] = temp;
            }
            else if(bday[j -1].year == bday[j].year){
                if(bday[j - 1].month > bday[j].month){
                     temp = bday[j];
                    bday[j] = bday[j - 1];
                    bday[j - 1] = temp;
                }
                else if(bday[j - 1].month == bday[j].month){
                    if(bday[j - 1].day > bday[j].day){
                         temp = bday[j];
                    bday[j] = bday[j - 1];
                    bday[j - 1] = temp;
                    }
                    else{
                        break;
                    }
                }
            }
            else{
                break;
            }
        }
    }

    printf("%s\n",bday[n -1].name);
    printf("%s\n",bday[0].name);

    return 0;
}
