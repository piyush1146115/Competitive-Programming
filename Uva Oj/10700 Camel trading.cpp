#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long num, i, j, k, sum, val, res[3], test, m;
    string s;

    scanf("%lld", &test);

    while(test--){
        cin >> s;
        val = 1;
        sum = 0;
        for(i = 0; i <  s.size(); i++){
                num = 0;
                while(s[i] >= '0' && s[i] <= '9' && i < s.size()){
                    num = ((s[i] - 48) + num * 10);
                i++;
                }
                //cout << num << endl;
                sum += num;

                if(i  == s.size()){
                    val *= sum;
                    break;
                }
                if(s[i] == '*'){
                    val *= sum;
                 //   cout << sum << endl;
                    sum = 0;
                }
        }

        res[1] = val;
        //cout << val << endl;

        val = 0;
        sum = 1;
        for(i = 0; i <  s.size(); i++){
                num = 0;
                while(s[i] >= '0' && s[i] <= '9' && i < s.size()){
                    num = ((s[i] - 48) + num * 10);
                i++;
                }
        //        cout << num << endl;
                sum *= num;

                if(i  == s.size()){
                    val += sum;
                    break;
                }
                if(s[i] == '+'){
                    val += sum;
                    sum = 1;
                 //   cout << sum << endl;
                }
        }

        res[2] = val;
        //cout << res[1] << " " << res[2] << endl;
    printf("The maximum and minimum are %lld and %lld.\n",res[1], res[2]);
    }
    return 0;
}
