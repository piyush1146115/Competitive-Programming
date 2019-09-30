///copied

#include <cstdio>

int main() {
	int n; scanf("%d", &n);
	int d, p = 0; char dd[105];
	bool f = true;
	while(n-- and f) {
		scanf("%d%s", &d, dd);
		if(dd[0] == 'E' or dd[0] == 'W') {
			if(p == 20000 or p == 0) f = false;
			continue;
		}
		else if(dd[0] == 'N') p -= d;
		else p += d;
		if(p > 20000 or p < 0) f = false;
	}
	if(p) f = false;
	puts(f? "YES": "NO");
}
