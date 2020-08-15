#include<bits/stdc++.h>
using namespace std;

int main()
{
    int h, m , s, c, TS, TSD;
    int dec_h, dec_m, dec_S, S;
    char str[10];

    while(gets(str)){
        h = (str[1] - 48) + ((str[0] - 48) * 10);
        m = (str[3] - 48) + ((str[2] - 48) * 10);
        s = (str[5] - 48) + ((str[4] - 48) * 10);
        c = ((str[7] - 48) + ((str[6] - 48) * 10));

        TS = (h * 3600) + (m * 60) + s;
        TS *= 100;

        TS += c;
        TSD =  (125 *TS) / 108;


        printf("%07d\n", TSD);
    }
    return 0;
}
/*
#include<iostream>
#include<cstring>
#include<cstdio>
#define db(a) cout << #a << " = " << a << endl;
#define db2(a, b) cout << #a << " = " << a << " -- "<< #b << " = " << b << endl;
#define foreach(it, l) for(typeof(l.begin()) it = l.begin(); it != l.end(); it++)
using namespace std;
int main(){
	string t;
	int HH, MM, SS, CC, g;
	while(cin >> t){
		HH = (t[0] - 48)*10 + (t[1] - 48);
		MM = (t[2] - 48)*10 + (t[3] - 48);
		SS = (t[4] - 48)*10 + (t[5] - 48);
		CC = (t[6] - 48)*10 + (t[7] - 48);
		g = HH * 3600 + MM * 60 + SS;
		g *= 100;
		g += CC;
		g = (125 * g) / 108;
		printf("%07d\n", g);
	}
	return 0;
}
*/
