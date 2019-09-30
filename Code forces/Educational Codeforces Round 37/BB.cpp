/// This is a code for Basic KMP Implementation
/// Complexity: O(n+m)

/**
    This Code Will find all the occurrence of 'p' in 'text'.
    And the Position of those occurrence in text.
*/
#include<bits/stdc++.h>
using namespace std;
string text;
int temp[1000100];
string ss[1000010];
vector<int> tmp[1000010];
vector<int> make_temp(string p)
{
    memset(temp, 0, sizeof(temp));
//    string p;
    int j=0;
    int i=1;
    temp[0] = 0;
    for(i=1; i<p.size(); i++)
    {
        if(p[i]==p[j])
        {
            temp[i] = ++j;
        }
        else
        {
            while(j>0)
            {
                j = temp[j-1];
                if(p[i]==p[j])
                {
                    temp[i] = ++j;
                    break;
                }
            }
        }
    }
    int sz = p.size();
    vector<int>v(temp,temp+sz);
    return v;
}

int Match(int id)
{
    int cnt = 0;
    int i=0, j = 0;
    for(i =0; i<text.size(); i++)
    {
        if(ss[id][j] == text[i])
        {
            j++;
            if(j==ss[id].size())
            {
                if(text[i-j]==' ')cnt++;
                j--;
                while(j>0)
                {
                    j = tmp[id][j-1];
                    if(text[i]==ss[id][j])
                    {
                        j++;
                        break;
                    }
                }
            }
        }
        else
        {
            while(j>0)
            {
                j = tmp[id][j-1];
                if(text[i]==ss[id][j])
                {
                    j++;
                    break;
                }
            }
        }
    }
    return cnt;
}
int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        string s;
        cin >> ss[i];
        tmp[i] = make_temp(ss[i]);
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        text = "";
        int nn,th;
        scanf("%d %d",&nn,&th);
        for(int i=0; i<nn; i++)
        {
            string stri;
            cin >> stri;
            text += ' '+ stri;
        }
        int sum = 0;
        int ans=-1;
        for(int i=0; i<n; i++)
        {
            sum += Match(i);
            if(sum>=th){ans=i+1;break;}
        }
        printf("%d\n",ans);
    }
}
