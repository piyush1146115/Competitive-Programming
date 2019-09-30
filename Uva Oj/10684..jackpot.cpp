#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int sum, mx, n, i, num;

    while(cin >> n, n){
        sum = 0;
        mx = 0;

        for(i = 1; i <= n; i++){
            cin >> num;

            sum += num;

            if(sum > mx)
                mx = sum;


            if(sum < 0)
                sum = 0;
        }
        if(mx > 0){

            printf("The maximum winning streak is %lld.\n",mx);
        }
        else
            printf("Losing streak.\n");
    }
    return 0;
}
/*
#include <cstdio>
using namespace std;

int main() {
	int n, i, x[100000];

	while (scanf("%d", &n), n) {
		for (i = 0; i < n; i++) {
			scanf("%d", &x[i]);
		}

		int max = 0, temp = 0;
		for (i = 0; i < n; i++) {
			temp += x[i];
			if (temp > max)
				max = temp;
			if (temp < 0)
				temp = 0;
		}

		if (max > 0)
			printf("The maximum winning streak is %d.\n", max);
		else
			printf("Losing streak.\n");
	}

	return 0;
}
*/
