#include<bits/stdc++.h>
using namespace std;
int main()
{
    double x[4], y[4], c[4], ax, ay;
    int i, j, k;

    while(1){
        scanf("%lf %lf %lf %lf %lf %lf",&x[1], &y[1], &c[1], &x[2], &y[2], &c[2]);
        if(x[1] == 0 && x[2] == 0 && y[1] == 0 && y[2] == 0 && c[1] == 0 && c[2] == 0)
            break;

        x[1] = -(x[1]/ y[1]);
        c[1] = c[1]/ y[1];
        x[2] = -(x[2]/ y[2]);
        c[2] = c[2] / y[2];

    if(abs(x[1] - x[2]) != 0){
        ax  = (c[2] - c[1])/ (x[1] - x[2]);
        ay = c[1] + (x[1]* ax);
        printf("The fixed point is at %.2lf %.2lf.\n", ax, ay);
    }
    else{
        printf("No fixed point exists.\n");
    }
    }
    return 0;

}
