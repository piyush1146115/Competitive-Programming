#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;

int main()
{
    string ara;
    int a, b, l, count, sum, test;

    scanf("%d", &test);
    getchar();
    while(test--){
        getline(cin, ara);

        l = ara.size();
        count = 0;
        sum = 0;
        for(a = 0; a  < l; a++){
            if(ara[a] == 'O'){
                count++;
            }
            else{
                count = 0;
            }
            sum += count;
        }
        printf("%d\n",sum);
    }
    return 0;
}
