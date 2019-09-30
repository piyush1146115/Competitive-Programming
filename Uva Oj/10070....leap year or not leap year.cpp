#include<bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    int i, j, a, b, c = 0, d, l;
    int d4, d15, d55, d100, d400;

    while(cin >> str){

        l = str.size();

        d4 = 0;
        d15 = 0;
        d55 = 0;
        d100 = 0;
        d400 = 0;

        for(i = 0; i < l ; i++){
            d4 = (str[i] - 48  + d4*10) % 4;
            d100 = (str[i] - 48 + d100 * 10) % 100;
            d55 = (str[i] - 48 + d55 * 10) % 55;
            d15 = (str[i] - 48 + d15 * 10) % 15;
            d400 = (str[i] - 48 + d400 * 10) % 400;
         }
         if(c > 0)
        printf("\n");

        c++;

        if ((d4 == 0 && d100 != 0) || d400 == 0)
        {
            printf("This is leap year.\n");
            if (d15 == 0)
                printf("This is huluculu festival year.\n");
            if (d55 == 0)
                printf("This is bulukulu festival year.\n");
        }
        else
        {
            if (d15 == 0)
                printf("This is huluculu festival year.\n");
            else
                printf("This is an ordinary year.\n");
        }
    }

    return 0;
}
