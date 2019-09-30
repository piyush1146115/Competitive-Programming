#include<bits/stdc++.h>
using namespace std;
int main()
{
    char name[50000], author[50000], in1[50], in2[50];
    int i, j, k, len1, len2;

    while(gets(author)){
        gets(name);

        len1 = strlen(author);
        len2 = strlen(name);
        int flag = 0, k = 0;
        for(i = 0; i < len1; i++){
            if(isalpha(author[i]) && flag == 0){
                in1[k++] = author[i];
                flag = 1;
            }
            if(author[i] == ' ')
                flag = 0;
        }

        flag = 0, j = 0;
        for(i = 0; i < len2; i++){
            if(isalpha(name[i]) && flag == 0){
                in2[j++] = name[i];
                flag = 1;
            }
            if(name[i] == ' ')
                flag = 0;
        }

        int l = 0;

        for(i = 0; i < k; i++){
            while(l < j){
                if(in1[i] == in2[l])
                    break;
                l++;
            }
            if(l == j)
                break;
        }
    if(i == k)
        printf("yes\n");
    else
        printf("no\n");
    }
    return 0;
}
