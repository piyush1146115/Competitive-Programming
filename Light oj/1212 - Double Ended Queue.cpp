#include<bits/stdc++.h>
using namespace std;
int main()
{
	
    int test;
    
    scanf("%d", &test);
    
    for(int tc = 1; tc <= test; tc++) {
        deque<int> dq;
    
        int n, m;
        int cnt = 0;
    
        string s;
        cin >> n >> m;
        
        printf("Case %d:\n",tc);

        while(m--){
			
            cin >> s;
            int val;

            if(s == "pushLeft") {
                
                cin >> val;
                
                if(cnt == n)
                {
                    printf("The queue is full\n");
                    continue;
                }
                printf("Pushed in left: %d\n",val);
                dq.push_back(val);
                cnt++;
            }
            
            else if(s == "pushRight") {
                cin >> val;
                if(cnt == n)
                {
                    printf("The queue is full\n");
                    continue;
                }
                printf("Pushed in right: %d\n",val);
                dq.push_front(val);
                cnt++;
            }
            else if(s == "popLeft") {
                if(cnt == 0) {
                    printf("The queue is empty\n");
                    continue;
                }
                printf("Popped from left: %d\n",dq.back());
                dq.pop_back();
                cnt--;
            }
            else if(s == "popRight") {
                if(cnt == 0) {
                    printf("The queue is empty\n");
                    continue;
                }
                printf("Popped from right: %d\n",dq.front());
                dq.pop_front();
                cnt--;
            }
        }

    }
return 0;
}
