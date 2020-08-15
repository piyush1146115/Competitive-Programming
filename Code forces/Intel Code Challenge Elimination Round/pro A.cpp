#include<bits/stdc++.h>
using namespace std;
int main()
{
    int h, n, i, j;
    string s;

    cin >> h >> s;

    if(h == 12){
        if(s[0] == '0' && s[1] == '0')
            s[0]++;
        if(s[0] == '1' && s[1] > '2')
            s[1] = '0';
        if(s[0] > '1' && s[1] != '0')
            s[0] = '0';
            if(s[0] >'1' && s[1] == '0')
                s[0] = '1';
    }
    else{
        if(s[0] == '2' && s[1] > '3')
            s[1] = '3';
        if(s[0] > '2')
            s[0] = '1';

    }

    if(s[3] >= '6')
        s[3] = '5';

        cout << s << endl;
}


/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    while(1){
    int p,h,m;
    char c;
    cin>>p>>h>>c>>m;

    if(h>p)
        printf("%02d:",h%10);
    else if(h == 24 && p == 24)
        printf("04:");
    else if(h == 00 && p == 12)
        printf("01:");
    else
        printf("%02d:",h);
    if(m>59)
        printf("%02d",m%10);
    else
        printf("%02d",m);
    }
}
*/
