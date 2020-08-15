/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    double cost[1005];
     double avg, n, sum, dif, result,b, c, negSum, posSum;
    int a, count;

    while(scanf("%lf",&n) == 1 && (n != 0) ){
            sum = 0;
           negSum = 0;
           posSum = 0;
        for(a = 0; a < n; a++){
            scanf("%lf",&cost[a]);
            sum += cost[a];
        }
        avg = sum / n;

        for(a = 0; a < n; a++){
            if(cost[a] > avg){
                b =fabs((double) (long) cost[a] - avg);
                posSum += b;
            }
            else{
                b = fabs((double) (long) avg - cost[a]);
                negSum += b;
            }
        }

        if(posSum < negSum)
            result = posSum;
        else
            result = negSum;

        printf("$%.2lf\n",result);
    }
    return 0;
}
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

int main(){
  int n;
  double amount;
  while(scanf("%d",&n) && n!=0){
    vector<double> money;
    double amount,total=0,respPos=0,respNeg=0;
    for (int i = 0; i < n; ++i)
    {
      scanf("%lf",&amount);
      total += amount;
      money.push_back(amount);
    }
    total /= n;
    for (int i = 0; i < n; ++i)
    {
      double dif =(double) (long) ((money[i]-total) * 100.0) / 100.0;
      if(dif>0)
        respPos+=dif;
      else
        respNeg+=dif;
    }
    double resp = (-respNeg > respPos) ? -respNeg : respPos;

    printf("$%.2lf\n",resp);
  }

 return 0;
}
