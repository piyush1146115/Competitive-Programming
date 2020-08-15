#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string st;
    map<string , int> m;
    set <string> s;
    int test, cont , i = 0;
    char c;
    double per;

    scanf("%d\n\n", &test);

    while(test--){
            i++;
            cont = 0;
        while(getline(cin, st) && st != ""){
                //getchar();
            m[st]++;
            s.insert(st);
            cont++;
        }
       // cout << cont << endl;
        set <string> :: iterator it;
        if(i > 1)
            printf("\n");

        for(it = s.begin(); it != s.end(); it++){
            cout << *it;
            per = ((double)m[*it] / (double)cont) * 100;
            printf(" %.4lf\n",per);
        }
        s.clear();
        m.clear();
    }
    return 0;
}

