#include<bits/stdc++.h>
using namespace std;
int ara[50];

bool palin(char str[], int len)
{
    int i = 0, j = len -1;

    while(i <= j){
             if(str[i] == '0' || str[i] == 'O'){
            if(str[j] == '0' || str[j] == 'O'){
                i++;
                j--;
                continue;
            }
            else{
                return false;
            }
        }

        if(str[i] == str[j]){
            i++;
            j--;
        }
        else{
            return false;
        }
    }
    if(i > j){
        return true;
    }
}


bool mirror(char st[],int len)
{
    int i = 0,j = len -1, b, a;

    while(i <= j){
        if(st[i] == '0' || st[i] == 'O'){
            if(st[j] == '0' || st[j] == 'O'){
                i++;
                j--;
                continue;
            }
            else{
                return false;
            }
        }
    else if(st[i] >= 'A' && st[i] <= 'Z'){
        b = st[i] - 'A';
        if(ara[b] > 0){
            if(st[j] == ara[b]){
                i++;
                j--;
                continue;
            }
            else{
                return false;
            }
        }
        else
            return false;
    }
    else if(st[i] >= '1' && st[i] <= '9'){
        b = st[i] - 23;
         if(ara[b] > 0){
            if(st[j] == ara[b]){
                i++;
                j--;
                continue;
            }
            else{
                return false;
            }
        }
        else
            return false;
    }
    }
if(i == j)
    return true;
}

int main()
{
ara[0] = 'A', ara[4] = '3', ara[7] = 'H', ara[8] = 'I', ara[9] = 'L', ara[11] = 'J', ara[12] = 'M', ara[14] = 'O',ara[18] = '2', ara[19] = 'T';
ara[20] = 'U', ara[21] = 'V', ara[22] = 'W', ara[23] = 'X', ara[24] = 'Y', ara[25] = '5',ara[26] = '1', ara[27] = 'S' , ara[28] = 'E';
ara[30] = 'Z', ara[33] = '8';

    char st[25], i, j, k, len;

    while(gets(st)){
    len = strlen(st);


   if(palin(st, len) && mirror(st, len)){
    printf("%s -- is a mirrored palindrome.\n\n",st);
   }
   else if(palin(st, len)){
    printf("%s -- is a regular palindrome.\n\n",st);
   }
   else if(mirror(st, len)){
    printf("%s -- is a mirrored string.\n\n",st);
   }
   else{
    printf("%s -- is not a palindrome.\n\n",st);
   }

}
return 0;
}
