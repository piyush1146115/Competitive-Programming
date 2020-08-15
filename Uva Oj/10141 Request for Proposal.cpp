/*#include<bits/stdc++.h>
using namespace std;
double r, n, mx_c, mx_p, price[100000], comp[100000];
string s, name[100000];
int main()
{
   // freopen("input.txt", "r", stdin);
    int  p, i, j, cs = 0, ind = 0;


    while(cin >> n >> p){
            //cout << n << endl;
            getchar();
        if(n == 0 && p == 0)
            break;
        j = n;
        while(j--){
            getline(cin, s);
        }

        for(i = 0; i < p; i++){
            getline(cin, name[i]);
            cin >> price[i] >> r;
            comp[i] = r / n;
          //  cout << comp[i] << " " << r << endl;
            getchar();
            while(r--){
                getline(cin, s);
            }
        }

        mx_c = 0.0;
        for(i = 0; i < p; i++){
            if(comp[i] > mx_c){
                ind = i;
                mx_c = comp[i];
                mx_p = price[i];
            }
        }

         for(i = 0; i < p; i++){
            if(comp[i] == mx_c){
                if(price[i] < mx_p){
                    ind = i;
                    mx_p = price[i];
                }
            }
        }

        if(cs > 0)
            printf("\n");
        printf("RFP #%d\n",++cs);

        cout << name[ind] << endl;
    }
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
struct pro{
string name;
double price, com;
int r, pos;
}pr[100000];

bool comp(pro a, pro b)
{
    // greater compliance should come first
    if (a.com > b.com) return true;

    if (a.com == b.com) {
        // lower price should come first
        if (a.price < b.price) return true;
    }
    return false;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, p, i, j, cs = 0;
    string s;

    while(cin >> n >> p){
            getchar();
        if(n == 0 && p == 0)
            break;
	j = n;
        while(j--){
            getline(cin, s);
        }

        for(i = 0; i < p; i++){
            getline(cin, pr[i].name);
            cin >> pr[i].price >> pr[i].r;
            getchar();
            pr[i].com = (double)pr[i].r / (double)n;
            pr[i].pos = i;

            while(pr[i].r--){
                getline(cin, s);
            }
        }

        sort(pr, pr + p, comp);
        if(cs > 0)
            printf("\n");
        printf("RFP #%d\n",++cs);

        cout << pr[0].name << endl;

    }
    return 0;
}
