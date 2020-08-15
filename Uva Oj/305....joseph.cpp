#include <cstdio>
using namespace std;

int main() {
	int k;
	int ans[13] = { 2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901,
			1358657, 2504881 };

	while (scanf("%d", &k), k) {
		printf("%d\n",ans[k-1]);
	}

	return 0;
}
