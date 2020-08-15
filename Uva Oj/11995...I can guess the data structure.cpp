#include<bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue <int> pq;
    queue <int> qu;
    stack <int> st;
    int value, com, test, i, j, k, n, p, q, s;

    while(scanf("%d", &test) == 1){
        p = q = s = 1;
        for(i = 1; i <= test; i++){
            scanf("%d %d",&com, &value);

            if(com == 1){
                pq.push(value);
                st.push(value);
                qu.push(value);
            }
            else if(com == 2 && !pq.empty()){
                n = pq.top();
                pq.pop();
                if(n != value)
                    p = 0;
                n = st.top();
                st.pop();
                if(n != value)
                    s = 0;
                n = qu.front();
                qu.pop();
                if(n != value)
                    q = 0;
            }
            else{
                p = q = s = 0;
            }
        }
        if(p == 0 && q == 0 && s == 0)
            printf("impossible\n");
        else if((p == 1 && q == 1) || (q == 1 && s == 1) || (p == 1 && s == 1))
            printf("not sure\n");
        else if(p == 1)
            printf("priority queue\n");
        else if(s == 1)
            printf("stack\n");
        else if(q == 1)
            printf("queue\n");

        while(!pq.empty()){
            pq.pop();
            qu.pop();
            st.pop();
        }
    }
    return 0;
}
