#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string dic[105], word, temp;
    int sum[105], len = 0, i, j;
    while(cin >> dic[len]){
        if(dic[len] == "XXXXXX")
            break;
        len++;
    }
    sort(dic, dic + len);


    while(cin >> word){
        if(word == "XXXXXX")
            break;
            int flag = 0;

        sort(word.begin(), word.end());

       for(i = 0; i < len; i++){
        temp = dic[i];
        sort(temp.begin(), temp.end());
        if(temp == word){
            cout << dic[i] << endl;
            flag = 1;
        }
        }
        if(flag)
            printf("******\n");
        else
            printf("NOT A VALID WORD\n******\n");
       }
return 0;

}
