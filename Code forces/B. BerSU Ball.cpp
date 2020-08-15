#include<bits/stdc++.h>
using namespace std;
int bo[105], gi[105];
int main()
{
    int pb, pg, i, j, k, n, m;


    cin >> n;

    for(i = 0; i < n; i++)
        scanf("%d",&bo[i]);

    cin >> m;

    for(i = 0; i < m; i++)
        scanf("%d",&gi[i]);

    pb = 0, pg = 0;

    int co = 0;

    sort(bo, bo + n);
    sort(gi, gi + m);

    /*for(i = 0; i < n; i++)
        cout << bo[i] << endl;

    for(i = 0; i < m; i++)
        cout << gi[i] << endl;
*/
    while(pb < n && pg < m){
    //        cout << bo[pb] << "  " << gi[pg] << endl;

            if(abs(bo[pb] - gi[pg]) <= 1){
                co++;
                pb++;
                pg++;
            }
            else if(bo[pb] < gi[pg]){
                pb++;
            }
            else{
                pg++;
            }
    }

    cout << co << endl;
}
