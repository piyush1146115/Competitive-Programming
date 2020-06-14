#include<bits/stdc++.h>
using namespace std;
#define mxx 10000

vector <int> pf[10005];
int ara[10005];

void sieve()
{
	for(int i = 1; i < mxx; i++){
	ara[i] = i;
	}
	
	int sq = sqrt(mxx);
	
	for(int i = 2; i <= sq; i++){
		for(int j = 2; j <= mxx; j++){
			if(ara[j] == j){
				if(j % i == 0)
				ara[j] = i;
			}
		}
	}
	
	/*for(int i = 2; i <= 1000; i++)
	cout << i << " " << ara[i] << endl;
*/
for(int i = 1; i <= 1000; i++)
{
	int tmp = i;
	while(ara[tmp] != tmp){
	pf[i].push_back(ara[tmp]);
	tmp = tmp / ara[tmp];
	}
	pf[i].push_back(tmp);
}

for(int i = 1; i <= 100;i++){
	cout << i << " >>>>>    ";
	for(int j = 0; j < pf[i].size(); j++){
	cout << pf[i][j] << " ";
	}
	cout << endl;
}

}

int main()
{
	sieve();
}
