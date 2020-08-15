#include<bits/stdc++.h>
using namespace std;
int main()
{
    char in[] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
    char out[] = "`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg'~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\"";
    string s;
    int i, j, l, m;

    l =  strlen(in);

    while(getline(cin, s)){
        for(i = 0; i < s.size(); i++){

            for(j = 0; j < l; j++){
                if(s[i] == in[j]){
                    printf("%c",out[j]);
                    break;
                }
            }
            if(j == l)
                printf("%c",s[i]);
        }
        printf("\n");
    }
}
