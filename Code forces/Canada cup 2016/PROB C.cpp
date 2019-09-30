#include<bits/stdc++.h>
using namespace std;

int freq[30];

int main()
{
    int i, j, k, n, x, y;
    string s, t[5];
    char ch, ans[30];

    cin >> s;

    for(i = 0; i < s.size(); i++)
        freq[s[i] - 'A']++;

    x = y = -1;

    for(i = 0; i < s.size(); i++)
    {
        if(freq[s[i] - 'A'] == 2){
            if(x == - 1){
                x = i;
            }
            else
                y = i;

                ch = s[i];
        }
    }


    if(y - x == 1){
        printf("Impossible\n");
    }
    else{

    ///pushing segment 1, 2, 3

    for(i = 0; i < x; i++)
        t[0].push_back(s[i]);


    for(i = x + 1; i < y; i++)
        t[1].push_back(s[i]);


    for(i = y + 1; i < s.size(); i++)
        t[2].push_back(s[i]);


    k = (t[1].size() / 2);


    j = 0;
    k--;

    for(i = k; i >= 0; i--){
        ans[i] = t[1][j];
        j++;
    }

    i = 13;
    while(j < t[1].size()){
        ans[i] = t[1][j];
        j++;
        i++;
    }

    ans[k + 1] = ch;

    j = t[0].size() - 1;

    while(i < 26){
        ans[i] = t[0][j];
        j--;
        i++;
    }

    i = 12;
    while(j >= 0){
        ans[i] = t[0][j];
        j--;
        i--;
    }

    j = k + 2;
    i = 0;

    while(i < t[2].size() && j < 13){
        ans[j] = t[2][i];
        i++;
        j++;
    }

    j = 25;
    while(i < t[2].size()){
        ans[j] = t[2][i];
        j--;
        i++;
    }

    for( i = 0; i < 13; i++)
        printf("%c",ans[i]);

    printf("\n");

    for(i = 13; i < 26; i++)
        printf("%c",ans[i]);

    printf("\n");
    }


}
