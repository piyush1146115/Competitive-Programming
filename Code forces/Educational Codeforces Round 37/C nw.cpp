#include<bits/stdc++.h>
using namespace std;
#define mx 55
int Low[55][55], Left[mx][mx], Right[mx][mx];
int n,m;
string s[mx];
int main()
{
    for(int i=0; i<55; i++)
    {
        for(int j=0; j<55; j++)
        {
            Low[i][j] = 1;
            Left[i][j] = 1;
            Right[i][j] = 1;
        }
    }
    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> s[i];

    for(int i=0; i<n; i++)
    {
        for(int j=1; j<m; j++)
        {
            if(s[i][j]==s[i][j-1])
            {
                Left[i][j] = Left[i][j-1]+1;
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=m-2; j>=0; j--)
        {
            if(s[i][j]==s[i][j+1])
            {
                Right[i][j] = Right[i][j+1]+1;
            }
        }
    }

    for(int j=0; j<m; j++)
    {
        for(int i=n-2; i>=0; i--)
        {
            if(s[i][j]==s[i+1][j])
            {
                Low[i][j] = Low[i+1][j]+1;
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout << Low[i][j] << " ";
        }
        cout << endl;
    }

    bool exist = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            char ch = s[i][j];
            if(Low[i][j]>1 && Right[i][j]>1)
            {
                int clo = Low[i][j];
                int cr = Right[i][j];
                for(int k=j+1; k<j+cr; k++)
                {
                    if(Low[i][k]>1 && s[i][k]==ch)
                    {
                        int nlo = Low[i][k];
                        for(int l=i+1; l<i+nlo; l++)
                        {
                            if(Left[l][k]>=k-j+1)
                            {
                                exist = true;
                            }
                        }
                    }
                }
            }
        }
    }
    if(exist) cout << "Yes" << endl;
    else cout << "No" << endl;
}
