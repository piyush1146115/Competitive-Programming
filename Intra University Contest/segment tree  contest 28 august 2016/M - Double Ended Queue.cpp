#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int n, m, c, i, j, k, test, cs = 0;



    scanf("%d", &test);

    while(test--){

         deque <int> d;
        deque <int> :: iterator it;

        scanf("%d %d", &n, &m);
        c = 0;

        printf("Case %d:\n", ++cs);
        while(m--){
        cin >> s;

        if(s == "pushLeft"){
            scanf("%d", &k);
            c++;
            if(c > n){
                printf("The queue is full\n");
                c--;
                continue;
            }
            printf("Pushed in left: %d\n",k);
            d.push_back(k);
        }

        else if(s == "pushRight"){
        scanf("%d", &k);
            c++;
            if(c > n){
                printf("The queue is full\n");
                c--;
                continue;
            }
            printf("Pushed in right: %d\n", k);
            d.push_front(k);
        }

        else if(s == "popLeft"){
            if(d.empty()){
                printf("The queue is empty\n");
                continue;
            }
            else{
                    it = d.end();
                    it--;
                    c--;
                printf("Popped from left: %d\n", *it);
                 d.pop_back();
            }
        }
        else if(s == "popRight"){
            if(d.empty()){
                printf("The queue is empty\n");
                continue;
            }
            else{
                    it = d.begin();
                printf("Popped from right: %d\n", *it);
                d.pop_front();
                c--;
            }
        }
        }

    }
return 0;
}
