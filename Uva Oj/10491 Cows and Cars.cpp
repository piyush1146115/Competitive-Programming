#include<bits/stdc++.h>
using namespace std;
int main()
{
    double cow, car, show, res;
    /**case 1: my choice is a car then go to a car
        case 2 : my choice is a cow then go to a car
        probability of win   = p(case 1) + p(case 2)
        p(case 1) = (car/ (car + cow) ) * ((car - 1) / (cow + car - show - 1))
        p(case 2) = (cow / (car + cow)) * (car / (cow + car - show - 1))
        **/
    while(cin >> cow >> car >> show){

        res = (car * (cow + car - 1))/ ((car + cow) * (car +cow - show - 1));

        printf("%.5lf\n",res);
    }
    return 0;
}
