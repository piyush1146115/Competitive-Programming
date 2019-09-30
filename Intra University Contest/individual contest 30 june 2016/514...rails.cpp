/**Process
It took me a while to understand the problem directions properly at first.
The premise is that a train with cars 1 through N in increasing order is coming in to a station
in such a way that cars must back out onto track B. The entire train does not back out at once though,
each car can come into and out of the station independently. So for example,
cars 1 and 2 can come in, and 2 can back out onto track B. Then cars 3 and 4 can come in.
Then we’re left with 1, 3 and 4 at the station, 2 on track B, and 5, …, N on track A.
To solve the problem do a simulation with a stack. Add cars into the station until the input car is read,
and then pull it out. Continue the process and if the stack is empty, output Yes. Otherwise output No.
 Note that there is a ‘\n’ after the last output case.
 */
/*
 * Sai Cheemalapati
 * UVA 514: Rails
 *
 */

#include<cstdio>
#include<stack>

using namespace std;

int N, c;
stack<int> cars;

void marshal() {
    for(;;) {
        while(cars.size() > 0) cars.pop();
        int j = 0;
        for(int i = 0; i < N; i++) {
            scanf("%d", &c);
            if(c == 0) return;

            while(j < N && j != c) {
                if(cars.size() > 0 && cars.top() == c) break;
                j++;
                cars.push(j);
            }
            if(cars.top() == c) cars.pop();
        }
        if(cars.size() == 0) printf("Yes\n");
        else printf("No\n");
    }
}

int main() {
    for(;;) {
        scanf("%d", &N);
        if(N == 0) break;

        marshal();
        printf("\n");
    }
}
