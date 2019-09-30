#include<bits/stdc++.h>
using namespace std;
#define sq(x) x*x

double x, y, ara[20][3];

double bin(double lox, double loy, double hix, double hiy)
{
    double a, b, c, midx, midy, cx, cy;

    cx = lox;
    cy = loy;

    for(int k=0; k<500; k++)
    {
        midx = (lox + hix) /2.0;
        midy = (hiy + loy) / 2.0;
        //    cout << midx <<" " << midy << endl << endl;
        //  cout << cx <<" " << cy << endl << endl;
        //cout << x <<" " << y << endl << endl;

        c = sq(abs(cx - x)) + sq(abs(cy - y));
        b = sq(abs(cx - midx)) + sq(abs(cy - midy));
        a = sq(abs(x - midx)) + sq(abs(y - midy));

        //cout << sq(c) << " " << sq(a) << " " << sq(b) << endl;
        if( c == a + b){
            return a;
        }
        else if(c > (a + b)){
            lox = midx;
            loy = midy ;
        }
        else{
            hix = midx;
            hiy = midy ;
        }
    }
    return a;
}

int main()
{

    int i, j, k, N;
    string s;

    while(cin >> s)
    {

        if(s == "*")
            break;

        stringstream ss(s);
        ss >> N;

        //cout << N << endl;
        scanf("%lf %lf", &x, &y);

        for(i = 0; i < N; i++)
            scanf("%lf %lf", &ara[i][0], &ara[i][1]);

        ara[N][0] = ara[0][0];
        ara[N][1] = ara[0][1];

        double ans = 1000000000.0, res = 0.0;

        for(i = 0; i < N ; i++)
        {
            res = bin(ara[i][0], ara[i][1], ara[i+ 1][0],ara[i+ 1][1] );
            res=sqrt(res);
            ans = min(res, ans);
        }
        printf("%.3lf\n",ans);
    }
}
