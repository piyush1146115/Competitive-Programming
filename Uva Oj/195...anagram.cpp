#include<bits/stdc++.h>
using namespace std;
bool comp(char a, char b){
	if(tolower(a) == tolower(b)){
		return a<b;
	}
	return tolower(a) < tolower(b);
}
int main()
{
    char s[10000];
    int i, j, test;

    cin >> test;

    while(test--){
        cin >> s;
        int len = strlen(s);

        sort(s, s + len, comp);
        do{
            printf("%s\n",s);
        }while(next_permutation(s, s + len, comp));
    }
    return 0;
}
