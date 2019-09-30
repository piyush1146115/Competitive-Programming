#include<iostream>
#include<string>

using namespace std;

int main()
{
	string names[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
	int x = 1,n;
	cin >> n;
	while(x * 5 < n)
	{
		n -= (x * 5);
		x *= 2;
	}
	cout << names[(n-1)/x] << endl;
	return 0;
}
