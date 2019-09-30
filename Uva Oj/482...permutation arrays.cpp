#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s, num[10005];
    vector <int> v;
    int i, j, test, t = 0;

    cin >> test;
    //getchar();

    while(test--){
      scanf("\n");
      getline(cin, s);

      istringstream is(s);

      while(is >> j)
            v.push_back(j);

      for(i = 0; i < v.size(); i++){
        cin >> num[v[i]];
      }
        //getchar();
      for(i = 1; i <= v.size(); i++){
        cout << num[i] << endl;
      }
      if(test > 0)
        cout << endl;

    v.clear();
    }
    return 0;
}
/*
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<string.h>

using namespace std;

int main()
{
   // freopen("in.txt","r",stdin);
    int t,i,j,l,k;
    char a1[100000];
    int ii[10000];

    string st[10000],tmp;
    scanf("%d\n",&t);

    while(t--)
    {
        scanf("\n");
        gets(a1);
        stringstream ss(a1);
        j=0;
        while(ss >> ii[j])
            j++;
//            for(i=0;i<j;i++)
//                printf("%d ",ii[i]);
//                    puts("");
        for(i=0; i<j; i++)
            cin>>st[ii[i]];

        for(i=1; i<=j; i++)
            cout<<st[i]<<endl;
        if(t>0)
            printf("\n");
    }

    return 0;
}
*/
