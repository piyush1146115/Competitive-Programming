/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    long long int flag, i, j, k, ans, m, c = 0;
    double temp;
    string s, bin;

    while(cin >> s){
            if(s == "~")
            break;
        if(s == "#"){
                //cout << bin << endl;
                k = 0;
                ans = 0;
                reverse(bin.begin(), bin.end());
                if(bin.size() != 0){
            for(i = bin.size() - 1; i >= 0; i--){
                m = (bin[i] - 48);
                temp = pow(2, i);
                ans += m * temp;
            }
            }
            //flag = 0;
            cout << ans << endl;
            bin.clear();
            c = 0;
        }
        if(c == 0){
            flag = 1;
            c = 1;
            continue;
        }
       else if(s.size() == 1){
        flag = 1;
        continue;
       }
       else if(s.size() == 2){
        flag = 0;
        continue;
       }
       else{
        j = s.size() - 2;
        while(j--)
        bin.push_back(flag + 48);
       }
    }
    return 0;
}
*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,i;

    char s1[]= {"hate"},s2[]= {"love"};

    scanf("%d",&n);

    if(n==1)
    {
        printf("I hate it\n");
    }
    else
    {
        for(i=1; i<n; i++)
        {
            if(i%2==0)
                printf("I %s that ",s2);

            else
                printf("I %s that ",s1);

        }
        if(n%2==0)
            printf("I love it\n");
        else
            printf("I hate it\n");
    }


    return 0;

}
