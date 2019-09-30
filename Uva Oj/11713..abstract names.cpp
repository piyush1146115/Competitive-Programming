#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test, i, j, len1, len2, flag;
    char name[25], name2[25];

    scanf("%d", &test);

    while(test--){

            flag = 1;
        scanf("%s", name);
        scanf("%s", name2);

        len1 = strlen(name);
        len2 = strlen(name2);

        if(len1 != len2){
            flag = 0;
        }
        else{
            for(i = 0; i < len1; i++){
                if(name[i] == 'a' || name[i] == 'e' || name[i] == 'i' || name[i] == 'o' || name[i] == 'u'){
                    if(name2[i] == 'a' || name2[i] == 'e' || name2[i] == 'i' || name2[i] == 'o' || name2[i] == 'u'){
                        continue;
                    }
                    else{
                        flag = 0;
                        break;
                    }
                }
                else{
                    if(name[i] == name2[i]){
                        continue;
                    }
                    else{
                        flag = 0;
                        break;
                    }
                }
            }
        }
    if(flag == 1){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    }
    return 0;
}
