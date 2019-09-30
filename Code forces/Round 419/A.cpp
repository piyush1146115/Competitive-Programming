#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	string s;
	
	cin >> s;
	
	int h1 = s[0] - '0';
	int h2 = s[1] - '0';
	int m1 = s[3] - '0';
	int m2 = s[4] - '0'; 
	
	int mp1 = h2;
	int mp2 = h1;
	
	int mm = m1*10 + m2;
	int mp = mp1 * 10 + mp2;
	int hh = h1 * 10 + h2;
	if(hh == 23 && mm > 32){
		printf("%d\n",60 - mm);
	}
	else if(hh == 23){
		printf("%d\n",32- mm);
	}
	else if(mp < 60 && mp >= mm){
		printf("%d\n",mp - mm);
	}
	else{
		
		while(1){
			h2++;
			if(h2 == 10){
				h2 = 0;
				h1++;
			}
			int hp = h1 * 10 + h2;
			
			mp1 = h2;
			mp2 = h1;
			mp = mp1 * 10 + mp2;
			if(mp < 60){
				int dif1 = hp - hh;
				dif1--;
				int dif2 = (60 - mm + mp);
				
		printf("%d\n",dif1 * 60 + dif2);
		break;
	}
		}
		
	} 
}
