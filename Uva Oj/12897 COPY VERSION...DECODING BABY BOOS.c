# include <stdio.h>
# include <string.h>
//using namespace std ;
char s[ 1048576];
int main ()
{
    int testcase, n,i, j;
    scanf ( " %d " , &testcase);
    while (testcase--)
    {
        scanf( " %s " , s);
        scanf( " %d " , &n);
        char R[ 128 ], s1[ 10 ], s2[ 10 ];
        for (  i = 0 ; i < 128 ; i++)
            R[i] = i;
        for (  i = 0 ; i < n; i++)
        {
            scanf ( " %s %s " , s1, s2);
            for (  j = 'A' ; j <= 'Z' ; j++)
                if (R[j] == s2[ 0 ])
                    R[j] = s1[ 0 ];
        }
        for (  i = 0 ; s[i]; i++)
            putchar(R[s[i]]);
        puts( "" );
    }
    return 0 ;
}
