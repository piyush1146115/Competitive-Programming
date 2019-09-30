#include<bits/stdc++.h>
using namespace std;
map<char, int> m;
map<char, char> md;
bool comp(char a, char b)
{
    return m[a] > m[b];
}

int main()
{
        string s1, s2;
    int i, j, k, l, test;

    scanf("%d", &test);

    while(test--)
    {
        cin >>s1 >> s2;

        for(i = 0; i < s1.size(); i++){
            m[s1[i]]++;
        }
        sort(s1.begin(), s1.end(), comp);
        m.clear();


        for(i = 0; i < s2.size(); i++){
            m[s2[i]]++;
        }
        sort(s2.begin(), s2.end(), comp);
        m.clear();
        j = 0;
        for(i = 0; i < s2.size(); i++){
          /*  while( i < s2.size() - 1 && s2[i] == s2[i + 1])
                i++;
            while(j < s1.size() - 1 && s1[i] == s1[i + 1])
                j++;*/

            md[s2[i]] = s1[j];
            j++;
        }
        for(i = 0; i < s2.size(); i++){
            cout << md[s2[i]] << endl;
        }
        md.clear();
    }
    return 0;
}
