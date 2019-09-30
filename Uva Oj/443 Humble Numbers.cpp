#include<bits/stdc++.h>
using namespace std;
long long h[6000];

void humble() {

    h[1] = 1;
    long long  i, in1, in2, in3, in4, a, b, c, d;
    in1 = in2 = in3 = in4 = 1;
    for(i = 2; i <= 5843; i++) {
        a = h[in1] * 2;
        b = h[in2] * 3;
        c = h[in3] * 5;
        d = h[in4] * 7;

        h[i] = min(min(a, b), min(c, d));

        if(h[i] == a)
            in1++;
        if(h[i] == b)
            in2++;
        if(h[i] == c)
            in3++;
        if(h[i] == d)
            in4++;
    }

}
int main()
{
    humble();

    long long int n, i, j, k;

    while(scanf("%lld", &n) == 1 && n != 0) {

        printf("The ");
        if(n % 100 >= 11 && n % 100 <= 20) {
            printf("%lldth ", n);
        }
        else if(n % 10 == 1) {
            printf("%lldst ",n);
        }
        else if(n % 10 == 2) {
            printf("%lldnd ",n);
        }
        else if(n % 10 == 3) {
            printf("%lldrd ",n);
        }
        else {
            printf("%lldth ",n);
        }
        printf("humble number is %lld.\n",h[n]);
    }
    return 0;
}
