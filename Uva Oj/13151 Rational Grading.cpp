#include<bits/stdc++.h>
using namespace std;

long long power(long long b, long long p)
{
	if(p == 0)
	return 1;
	
	if(p % 2 == 0){
	long long q = power(b, p /2);
	return q * q;
	}
	else{
	return (power(b, p -1) * b);
	}
}

long long hex(string s)
{
	long long ans = 0, cnt = 0;
	for(long long i = s.size() - 1; i >= 2; i--){
		if(s[i] >= 'A' && s[i] <= 'F'){
		ans += ((s[i]- 55) * power(16,cnt));
		}
		else
		ans += ((s[i] - '0') * power(16 , cnt));
		
		cnt++;
	}
	return ans;
}


long long oct(string s)
{
	long long ans = 0, cnt = 0;
	for(int i = s.size() - 1; i >= 1; i--){
		ans += ((s[i] - '0') *power(8 , cnt));
		cnt++;
	}
	return ans;
}


long long dec(string s)
{
			long long ans = 0, cnt = 0;
	for(int i = s.size() - 1; i >= 0; i--){
		ans += ((s[i] - '0') *power(10 , cnt));
		cnt++;
	}
	return ans;
}

int main()
{
	string s1, s2;
		long long q;
		
	
	
	while(cin >> s1 >>   q){
		if(s1 == "0" && q == 0)
		break;
		
		
		long long num = 0;
		
		
		if(s1[0] == '0' && s1[1] == 'x'){
		num = hex(s1);
		}
			
		else if(s1[0] == '0'){
		num = oct(s1);
		}
		else{
			num = dec(s1);
		}	
		
		
		long long m, cnt = 0;
		for(int i = 0; i < q; i++){
		
		cin >> s2 >> m;
		
	
		if(s2 == "i++"){
			if(m == num){
				cnt++;
				num = m + 1;
			}
			else
			num = m + 1;
			 
		}
		else if(s2 == "++i"){
			if(m == num + 1){
			cnt++;
			}
			num = m;
		}
		else if(s2 == "i--"){
			if(m == num){
			cnt++;
			num = m - 1;
			}
			else{
				num = m - 1;
			}
		}
		else if(s2 == "--i"){
		if(m == num - 1)
		cnt++;
		
		num = m;
		}
		
		else if(s2 == "i"){
		if(m == num)
		cnt++;
		
		num = m;
		}
				//cout << num << " " << s2 << " " << cnt << endl;
	}
		
	printf("%lld\n", cnt);
}
	
}
