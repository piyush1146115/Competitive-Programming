#include<bits/stdc++.h>
using namespace std;
struct DNA{
string st;
int val;
/*bool operator < (const DNA &b)
{
    if(val < b.val)
        return 1;
    else
        return 0;
}*/
}d[500];

bool comp(DNA a, DNA b){
return a.val < b.val;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, l, i, j, k, test, con;
    string s;
    scanf("%d",&test);

    while(test--){
        scanf("%d %d",&l, &n);

        for(i = 0; i < n;i++){
            cin >> d[i].st;
            con = 0;
            for(j = 0; j < l -1; j++){
                for(k = j + 1; k < l; k++){
                    if(d[i].st[j] > d[i].st[k]){
                        con++;
                    }
                }
            }
            d[i].val = con;
        }

        stable_sort(d, d + n, comp);
        for(i = 0; i < n; i++)
            cout << d[i].st << endl;

            if(test)
                printf("\n");
    }
    return 0;
}
