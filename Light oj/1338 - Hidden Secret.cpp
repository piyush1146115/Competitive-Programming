#include<bits/stdc++.h>
using namespace std;
int main()
{
    int fq[30], fq2[30];

    int test;

    scanf("%d", &test);
    getchar();

    for(int tc = 1; tc <= test; tc++){
        string s1, s2;

        getline(cin, s1);
        getline(cin, s2);

        memset(fq, 0, sizeof(fq));
        memset(fq2, 0, sizeof(fq2));

        for(int i = 0; i < s1.size(); i++)
        {
			if(s1[i] == ' ')
			continue;
			
        fq[tolower(s1[i]) - 'a']++;
        //cout << s1[i] << " " << tolower(s1[i])<< " " <<  fq[tolower(s1[i]) - 'a'] << endl; 
        }

        int flag = 1;

        for(int i = 0; i < s2.size(); i++)
        {
			if(s2[i] == ' ')
			continue;
			
             fq2[tolower(s2[i]) - 'a']++;

        }

        for(int i = 0; i < s2.size(); i++)
        {
			if(s2[i] == ' ')
			continue;
			
           if( fq[tolower(s2[i]) - 'a'] != fq2[tolower(s2[i]) - 'a'])
				flag = 0;
        }

        for(int i = 0; i < s1.size(); i++)
        {
			if(s1[i] == ' ')
			continue;
			
           if( fq[tolower(s1[i]) - 'a'] != fq2[tolower(s1[i]) - 'a'])
				flag = 0; 
        }
        
        if(flag)
        printf("Case %d: Yes\n",tc);
        else
        printf("Case %d: No\n",tc);

    }
}
