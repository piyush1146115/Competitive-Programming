#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ara[22] = {2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97,
                    113, 131, 199, 311, 337, 373, 733, 919, 991};

    long long int i, j, n, cont;

    while(scanf("%lld", &n) == 1, n){
            cont = 0;
        if(n < 10)
        j = 10;
        else if(n < 100)
            j = 100;
        else if(n < 1000)
            j = 1000;

        for(i = 0; i < 22; i++){
            if(ara[i] > n && ara[i] < j)
                {
                cont++;
                break;
                }
        }

        if(cont == 0)
        cout << cont << endl;
        else
        cout << ara[i] << endl;
    }
    return 0;
}

/*
#include <cstdio>

int main()
{
    // Fairly simple to pre-calculate. Can just calculate all primes in a table, then check if all orderings of the digits are prime.
    int anagramic[] = {2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97, 113, 131, 199, 311, 337, 373, 733, 919, 991};
    int size = 22;


    int wanted;

    while (scanf("%d", &wanted), wanted)
    {
        int best = size;

        for (int i = size - 1; i >= 0 && anagramic[i] > wanted; --i, --best);

        if (best < size)
        {
            int max = 1;

            while (wanted)
            {
                wanted /= 10;
                max *= 10;
            }

            if (anagramic[best] < max)
                printf("%d\n", anagramic[best]);
            else
                printf("0\n");
        }
        else
            printf("0\n");
    }
}
*/
