#include <bits/stdc++.h>
using namespace std;

int match(int A[][2], int B[][2]) {
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			if (A[i][j] != B[i][j])
				return 0;
	return 1;
}
void rotate(int A[][2]) {
	int B[2][2];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			B[1-j][i] = A[i][j];
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			A[i][j] = B[i][j];
}
int main() {
   // freopen("input.txt", "r", stdin);
	int test, cases = 0;
	scanf("%d", &test);
	while (test--) {
		int A[2][2], B[2][2];
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				scanf("%d", &A[i][j]);
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				scanf("%d", &B[i][j]);

		int same = 0;
		for (int i = 0; i < 4; i++) {
			if (match(A, B)){
				same = 1;
				 break;
			}
			rotate(B);
		}
		if(same)
            printf("Case #%d: POSSIBLE\n",++cases);
        else
            printf("Case #%d: IMPOSSIBLE\n",++cases);
	}
	return 0;
}

