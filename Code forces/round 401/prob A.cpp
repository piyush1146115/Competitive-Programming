#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, pos;
	
	cin >> n >> pos;
	
	if(n % 6 == 0)
	cout << pos << endl;
	else if(n% 6 == 1){
		if(pos == 0)
		cout << 1 << endl;
		else if(pos == 1)
		cout << 0 << endl;
		else
		cout << pos <<endl;
	}
	else if(n% 6 == 2){
		if(pos == 1)
		cout << 2 << endl;
		else if(pos == 2)
		cout << 0 << endl;
		else if(pos == 0)
		cout << 1 <<endl;
	}
	
	else if(n% 6 == 3)
	{
		if(pos == 0)
		cout << 0 << endl;
		else if(pos == 1)
		cout << 1 << endl;
		else if(pos == 2)
		cout << 0 <<endl;
	}
	else if(n% 6 == 4)
	{
		if(pos == 0)
		cout << 2 << endl;
		else if(pos == 1)
		cout << 0 << endl;
		else if(pos == 2)
		cout << 1 <<endl;
	}
	else if(n% 6 == 5){
		if(pos == 0)
		cout << 0 << endl;
		else if(pos == 1)
		cout << 2 << endl;
		else if(pos == 2)
		cout << 1 <<endl;
	}
	
	
}
