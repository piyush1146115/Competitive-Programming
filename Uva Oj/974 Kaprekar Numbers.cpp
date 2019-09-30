#include<bits/stdc++.h>
using namespace std;

bool chk(long long n, long long sq)
{
    string s;
    //cout << sq << " ";
    stringstream ss;
    ss << sq;

    s = ss.str();
    //cout << s << endl;
    int i, j, k;
    long long n1, n2, sum;

    n1 = 0;
    for(i = 0; i < s.size() - 1; i++){
        n1 = (s[i] - 48) + (n1 * 10);
        n2 = 0;
        for(j  = i + 1; j < s.size() ; j++){
            n2 = (s[j] - 48) + (n2 * 10);
        }
        if(n1 == 0 || n2 == 0)
            continue;

        if(n1 + n2 == n)
            return true;
    }
    return false;

}
set <int> ans;
void cal()
{
    int i, j;
    for(i = 4; i <= 40005; i++){
        if(chk(i, i*i)){
            ans.insert(i);
        }
    }
}
int main()
{
    cal();
    int low, high, i, j, cs = 0, flag, test;

    scanf("%d", &test);

    while(test--){

        scanf("%d %d", &low, &high);
        if(low > high)
            swap(low, high);
        flag = 1;

        printf("case #%d\n", ++cs);

        for(i = low; i <= high; i++){
            if(ans.count(i) > 0){
                printf("%d\n",i);
                flag = 0;
            }
        }
        if(flag){
            printf("no kaprekar numbers\n");
        }
        if(test)
            printf("\n");
    }
    return 0;
}
