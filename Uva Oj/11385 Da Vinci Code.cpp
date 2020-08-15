/*#include<bits/stdc++.h>
using namespace std;
map<long long,long long  int> m;
long long fib[100], ara[500];

void gen()
{
     long long int i, j, k;
    fib[1] =1;
    fib[2] = 2;
    m[1] = 1;
    m[2] = 2;

    for(i = 3; i <= 85; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
        m[fib[i]] = i;
    }
}

int main()
{
        gen();
       // freopen("input.txt", "r", stdin);
    long long i, j, k, test, n, len, mx = 0;
    char st[500], st2[500], ans[110];

    scanf("%lld", &test);

    while(test--){
        scanf("%lld", &n);
        mx = -1;
        for(i = 0; i < n; i++){
            scanf("%lld", &ara[i]);
            if(mx < ara[i])
                mx = ara[i];
           // cout << ara[i] << endl;
        }
        ans[m[mx]] = '\0';
        getchar();
        gets(st);
        //cout << st;

        len = strlen(st);
        k = 0;
        for(i = 0; i < len; i++){
            if(st[i] >= 'A' && st[i] <= 'Z'){
                st2[k++] = st[i];
            }
        }
       // cout << st2 << endl;
       memset(ans,' ', sizeof(ans));
       k = 0;
       for(i = 0; i < n; i++){
        ans[m[ara[i]] - 1] = st2[k++];

       }


       printf("%s\n",ans);
    }
    return 0;
}
*/

#include<bits/stdc++.h>
#define LL long long
using namespace std;

int nums [100];
LL fibs [100];
map <LL, int> map_fibo;

void generateFibo ()
{
    fibs [0] = 1;
    fibs [1] = 2;

    map_fibo [1] = 0;
    map_fibo [2] = 1;

    for ( int i = 2; fibs [i - 1] < (LL) 2147483648; i++ ) {
        fibs [i] = fibs [i - 1] + fibs [i - 2];
        map_fibo [fibs [i]] = i;
    }
}

int main ()
{
    //freopen("input.txt", "r", stdin);
    int testCase;
    scanf ("%d", &testCase);

    generateFibo ();

    while ( testCase-- ) {
        int n;
        scanf ("%d", &n);

        int maxi = INT_MIN;
        for ( int i = 0; i < n; i++ ) {
            scanf ("%d", &nums [i]);
            if ( maxi < nums [i] ) maxi = nums [i];
        }
        getchar ();

        char str [100 + 10];
        gets (str);

        char output [100 + 10];
        memset (output, ' ', sizeof (output));

        output [map_fibo [maxi] + 1] = 0;

        int str_len = 0;

        for ( int i = 0; i < n; i++ ) {
            while ( !isupper (str [str_len]) ) str_len++;

            output [map_fibo [nums [i]]] = str [str_len];
            str_len++;
        }

        printf ("%s\n", output);
    }

    return 0;
}
