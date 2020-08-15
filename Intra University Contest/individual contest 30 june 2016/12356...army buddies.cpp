/**Process
 Soldiers that already died are not included in the L and R values,
 so we can maintain two arrays LS and RS that hold the index of the next surviving soldier
  to the left of and right of index i respectively. After each death listing, we update this indices.
**/
#include<cstdio>

using namespace std;

int S, B, L, R;
int LS[1000100];
int RS[1000100];

int main() {
    for(;;) {
        scanf("%d %d", &S, &B);
        if(S == 0 & B == 0) break;
        for(int i = 0; i < S + 1; i++) {
            LS[i] = i - 1;
            RS[i] = i + 1;
        }
        for(int i = 0; i < B; i++) {
            scanf("%d %d", &L, &R);
            if(LS[L] < 1) printf("* ");
            else printf("%d ", LS[L]);
            if(RS[R] > S) printf("*\n");
            else printf("%d\n", RS[R]);

            LS[RS[R]] = LS[L];
            RS[LS[L]] = RS[R];
        }
        printf("-\n");
    }
}
