#include<bits/stdc++.h>
using namespace std;
int main()
{
	int h, m, s, t1, t2;
	
	cin >> h >> m >> s >> t1 >> t2;
	int temp;
	temp = s;
	
	s = (s / 5); 
	if(temp % 5 != 0)
	s++;
	temp = m;
	//cout << s << endl;
	m = (m / 5);
	
	if(m % 5 != 0){
		m++;
	}
	else if(s > 0)
	m++;
	
	
	if(m > 0)
	h++;
	
	if(h != 12)
	h = h % 12;
	
	if (m == 0)
	m = 12;
	
	if(s == 0)
	s = 12;
	
	if(t1 < t2)
	swap(t1, t2);
	int flag = 1;
	
	for(int i = t2 + 1; i <= t1; i++){
		if(i == h || i == s || i == m)
		flag = 0;
	}
	if(flag){
		printf("YES\n");
		return 0;
	}
	flag = 1;
	
	for(int i = t1 + 1; i <= 12; i++){
		if(i == h || i == s || i == m)
		flag = 0;
	}
	
	for(int i = 1; i <= t2; i++){
		if(i == h || i == s || i == m)
		flag = 0;
	}
	//cout << h << " " << m <<" " << s << endl;
	if(flag)
	printf("YES\n");
	else
	printf("NO\n");
}
