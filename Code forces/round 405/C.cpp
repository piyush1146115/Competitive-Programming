#include<bits/stdc++.h>
using namespace std;
int main()
{
	string st[55];
	
	st[0] = "A";
	st[1] = "B";
	st[2] = "C";
	st[3] = "D";
	st[4] = "E";
	st[5] = "F";
	st[6] = "G";
	st[7] = "H";
	st[8] = "I";
	st[9] = "J";
	st[10] = "K";
	st[11] = "L";
	st[12] = "M";
	st[13] = "N";
	st[14] = "O";
	st[15] = "P";
	st[16] = "Q";
	st[17] = "R";
	st[18] = "S";
	st[19] = "T";
	st[20] = "U";
	st[21] = "V";
	st[22] = "W";
	st[23] = "X";
	st[24] = "Y";
	st[25] = "Z";
	st[26] = "Aa";
	st[27] = "Ab";
	st[28] = "Ac";
	st[29] = "Ad";
	st[30] = "Ae";
	st[31] = "Af";
	st[32] = "Ag";
	st[33] = "Ah";
	st[34] = "Ai";
	st[35] = "Aj";
	st[36] = "Ak";
	st[37] = "Al";
	st[38] = "Am";
	st[39] = "An";
	st[40] = "Ao";
	st[41] = "Ap";
	st[42] = "Aq";
	st[43] = "Ar";
	st[44] = "As";
	st[45] = "At";
	st[46] = "Au";
	st[47] = "Av";
	st[48] = "Aw";
	st[49] = "Ax";
	st[50] = "Ay";
	st[51] = "Az";
	
	int n, k;
	string s;
	
	cin >> n >> k;
	
	for(int i = k - 1; i < n; i++)
	{
		cin >> s;
		if(s == "NO")
		st[i] = st[i - k + 1];
	}
	cout << st[0];
	for(int i = 1; i < n; i++)
	cout << " " << st[i];
	
	cout << endl;
}
