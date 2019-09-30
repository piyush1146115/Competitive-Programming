#include<bits/stdc++.h>
using namespace std;
int main()
{
    string  s,s1,s2, s3, s4;

    int test, i, j, cs = 0;

    scanf("%d", &test);
    getchar();

    while(test--){
        getline(cin, s);

        for(i = 0; i < s.size(); i++){
            if(isalpha(s[i]) || (s[i] >= '0' && s[i] <= '9')){
                s1.push_back(s[i]);
            }
        }

        //cout << s1 << endl;



        int sz = s1.size();

        double sq = sqrt(sz);

        printf("Case #%d:\n", ++cs);


        if(sq != (int)sq){
            printf("No magic :(\n");
            s1.clear();
            continue;
        }
        s2 = s1;
        reverse(s2.begin(), s2.end());

        for(i = 0; i < (int)sq; i++){
            for(j = i; j < sz; j += (int)sq){
                s3.push_back(s1[j]);
            }
        }


        for(i = 0; i < (int)sq; i++){
            for(j = i; j < sz; j += (int)sq){
                s4.push_back(s2[j]);
            }
        }

        if(s1== s2 && s2 == s3 && s3 == s4){
            printf("%d\n",(int)sq);
        }

        else{
            printf("No magic :(\n");
        }

        s1.clear();
        s2.clear();
        s3.clear();
        s4.clear();
    }
}
