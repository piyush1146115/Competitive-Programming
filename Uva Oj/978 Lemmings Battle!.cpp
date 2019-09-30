#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);

    priority_queue <int> g, b;
    vector <int> vb, vg;
    int bt, sg, sb, i, j, k, test, tg, tb;

    scanf("%d", &test);

    while(test--){
        scanf("%d %d %d",&bt, &sg, &sb);
    for(i = 0; i < sg; i++){
        scanf("%d", &k);
        g.push(k);
    }
    for(i = 0; i < sb; i++){
        scanf("%d", &k);
        b.push(k);
    }
    vb.clear();
    vg.clear();

    while(!b.empty() && !g.empty()){
        for(i = 0; i < bt; i++){
            if(b.empty() || g.empty())
                break;

            tg = g.top();
            g.pop();
            tb = b.top();
            b.pop();
            if(tg > tb){
                vg.push_back(tg - tb);
            }
            else if(tb > tg){
                vb.push_back(tb - tg);
            }
        }
        for(i = 0; i < vg.size(); i++)
            g.push(vg[i]);

        for(i = 0; i < vb.size(); i++)
            b.push(vb[i]);

        vb.clear();
        vg.clear();
    }
    if(b.empty() && g.empty()){
        printf("green and blue died\n");
    }
    else if(b.empty()){
        printf("green wins\n");
        while(!g.empty()){
            printf("%d\n",g.top());
            g.pop();
        }
    }
    else if(g.empty()){
        printf("blue wins\n");

        while(!b.empty()){
            printf("%d\n",b.top());
            b.pop();
        }
    }
    while(!b.empty()){
        b.pop();
    }
    while(!g.empty()){
        g.pop();
    }
    if(test)
        printf("\n");

    }
    return 0;
}
