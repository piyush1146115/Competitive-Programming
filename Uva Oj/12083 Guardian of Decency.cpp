#include<bits/stdc++.h>
using namespace std;
int main()
{
  // freopen("input.txt", "r", stdin);
   //freopen("output.txt", "w", stdout);

    int  i, j, test, num,  he[505], c1, mx[5], c2;
    map<string , int> sport, sex;
    string s1, s2[505] , s3;
    scanf("%d", &test);

    while(test--){
        scanf("%d", &num);
        for(i = 0; i < num; i++){
            cin >> he[i] >> s1 >> s2[i] >> s3;
            sex[s1]++;
            sport[s3]++;
        }
       // sort(he, he + num);

        mx[0] = mx[2] = 0;

        for(i = 0; i < num; i++){
                c1 = 0;
                c2 = 0;
            for(j = 0; j < num; j++){
                if(abs(he[i] - he[j]) > 40){
                    c1++;
                }
                if(s2[i] != s2[j]){
                    c2++;
                }
            }
            mx[0] = max(c1, mx[0]);
            mx[2] = max(c2, mx[2]);
        }
           // mx[0] = max(c1, mx[0]);

            mx[1] = max(sex["F"], sex["M"]);
           // mx[2] = music.size();

            map<string , int> :: iterator it;
            mx[3] = 0;

            for(it = sport.begin(); it != sport.end(); it++){
              mx[3] =  max(mx[3], (*it).second);
            }

            sort(mx, mx + 4);
            cout << mx[3] << endl;

            sport.clear();
            sex.clear();
    }
    return 0;
}
