#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;

    scanf("%d", &test);

    for(int tc = 1; tc <= test; tc++) {

        string cmd, cur = "http://www.lightoj.com/";
        stack<string> forwd, backward;


        printf("Case %d:\n",tc);

        while(1) {
            cin >> cmd;
            if(cmd == "QUIT")
                break;

            if(cmd == "VISIT") {
                backward.push(cur);
                cin >> cur;
                cout << cur << endl;

                while(!forwd.empty())
                {
                    forwd.pop();
                }
            }
            else if(cmd == "BACK"){

                if(backward.empty()){
                    printf("Ignored\n");
                }
                else {
                    if(cur.size() > 0)
                    {
                        forwd.push(cur);
                    }

                    cur = backward.top();
                    backward.pop();
                    cout << cur << endl;
                }
            }
            else if(cmd == "FORWARD")
            {

                if(forwd.empty()) {
                    printf("Ignored\n");
                }
                else {
                    if(cur.size() > 0)
                        backward.push(cur);

                    cur = forwd.top();
                    forwd.pop();

                    cout << cur << endl;
                }
            }
        }
    }
}
