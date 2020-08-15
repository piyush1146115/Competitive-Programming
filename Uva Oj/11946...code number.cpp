
/*#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    char str[150000], ch;
    int i, j, k,test, len;

    cin >> test;
    getchar();
    while(test--){
            while(gets(str)!='\0'){
        len = strlen(str);

        for(i = 0; i < len; i++){
            ch = str[i];
            switch(ch){
        case '1':
            str[i] = 'I';
            break;
        case '2':
            str[i] = 'Z';
            break;
         case '3':
            str[i] = 'E';
            break;
             case '4':
            str[i] = 'A';
            break;
             case '5':
            str[i] = 'S';
            break;
             case '6':
            str[i] = 'G';
            break;
             case '7':
            str[i] = 'T';
            break;
             case '8':
            str[i] = 'B';
            break;
             case '9':
            str[i] = 'P';
            break;


            }
        }
        }
        printf("%s\n",str);
        if(test)
            printf("\n");
    }
    return 0;
}
*/
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int main()
{
    char s[92];
    int t,i,j,k,l,n,d,f;


cin>>t;
{
getchar();
    for(j=0;j<t;j++)
    {
        while(gets(s)!='\0')
        {

            l=strlen(s);
            if(l==0){break;}

        for(i=0;i<l;i++)
          {

           if(s[i]=='4') cout<<"A";
           else     if(s[i]=='8')cout<<"B";
           else     if(s[i]=='3')cout<<"E";
           else     if(s[i]=='6')cout<<"G";
           else     if(s[i]=='1')cout<<"I";
           else     if(s[i]=='0')cout<<"O";
           else     if(s[i]=='9')cout<<"P";
           else     if(s[i]=='5')cout<<"S";
           else     if(s[i]=='7')cout<<"T";
           else     if(s[i]=='2')cout<<"Z";
           else cout<<s[i];

          }
          cout<<endl;

        }
       if(j!=t-1)cout<<endl;
    }}

    return 0;
}
