#include<stdio.h>
#include<string.h>
int main()
{
    char word[105];
    int i1, j1, k1, len, t1, count;
    scanf("%d", &t1);
    for(i1=1; i1<=t1; i1++)
    {
        gets(word);
        len = strlen(word);
        if(len==0)
        {
            i1--;
            continue;
        }
        count = 0;
        for(j1=0; j1<len; j1++)
        {
            switch(word[j1])
            {
            case 'a':
            case 'd':
            case 'g':
            case 'j':
            case 'm':
            case 'p':
            case 't':
            case 'w':
            case ' ':
                count = count + 1;
                break;

            case 'b':
            case 'e':
            case 'h':
            case 'k':
            case 'n':
            case 'q':
            case 'u':
            case 'x':
                count = count + 2;
                break;

            case 'c':
            case 'f':
            case 'i':
            case 'l':
            case 'o':
            case 'r':
            case 'v':
            case 'y':
                count = count + 3;
                break;

            case 's':
            case 'z':
                count = count + 4;
                break;
            }
        }
        printf("Case #%d: %d\n", i1, count);
    }
    return 0;
}
