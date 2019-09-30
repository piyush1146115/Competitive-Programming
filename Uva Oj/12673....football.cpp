#include<bits/stdc++.h>
using namespace std;
long long int ara[105];
int main()
{
    long long int goal, match, point, s, r, i, j, k, dif;

    while(scanf("%lld %lld",&match, &goal) == 2)
    {
        for(i = 0; i < 101; i++)
            ara[i] = 0;

        point = 0;
        for(i = 0; i < match; i++){
            scanf("%lld %lld", &s, &r);
            if(s > r){
                point += 3;
            }
            else if(s == r){
                point++;
                ara[0]++;
            }
            else{
                dif = r - s;
                ara[dif]++;
            }
        }

        j = ara[0];

        if(goal >= j){
            point += (j * 2);
            goal -= j;
        }
        else{
            point += (goal * 2);
            goal = 0;
        }

        for(i = 1; i <= 100; i++)
        {
            if(ara[i] > 0 && goal > 0){
                    j = ara[i];

            if(goal >= (j * (i + 1))){
                    point += j * 3;
                    goal -= (j * (i + 1));
                    ara[i] = 0;
                }

            else{
                for(k = 1; k <= j; k++){

                    if(goal >= (i + 1)){
                        point += 3;
                        goal -= (i + 1);
                        ara[i]--;
                    }
                }
            }
            }
        }
          for(i = 1; i <= 100; i++)
        {
            if(ara[i] > 0 && goal > 0){
                    j = ara[i];

            if(goal >= (j * i)){
                    point += j;
                    goal -= (j * i);
                    ara[i] = 0;
                }

            else{
                for(k = 1; k <= j; k++){

                    if(goal >= i){
                        point++;
                        goal -= i + 1;
                        ara[i]--;
                    }
                }
            }
            }
        }

        cout << point << endl;
    }
    return 0;
}
