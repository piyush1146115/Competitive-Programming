#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test, len1, len2, i, j, a, sp, wa, c;
    char in[50], out[50];

    scanf("%d", &test);
    getchar();

    for(a = 1; a <= test; a++){
        gets(in);
        gets(out);

        sp = 0;
        wa = 0;
        c = 0;

        len1 = strlen(in);
        len2 = strlen(out);

        for(i = 0; i < len1; i++){
            if(in[i] != ' ')
                c++;
        }
        if(c != len2){
            wa = 1;
        }

        i = 0;
        j = 0;

        if(wa == 0)
        while(i < len1 && j < len2){
            if(in[i] != out[j]){
                if(in[i] == ' '){
                    sp++;
                    i++;
                    continue;
                }
                else{
                    wa = 1;
                    break;
                }
            }
            else{
                i++;
                j++;
            }
        }

        while(i < len1 && wa == 0){
            if(in[i] == ' '){
                sp++;
            }
            else{
                wa = 1;
            }
            i++;
        }

        if(wa == 1)
            printf("Case %d: Wrong Answer\n",a);
        else if(sp >= 1)
            printf("Case %d: Output Format Error\n",a);
        else
            printf("Case %d: Yes\n",a);
    }
    return 0;
}
