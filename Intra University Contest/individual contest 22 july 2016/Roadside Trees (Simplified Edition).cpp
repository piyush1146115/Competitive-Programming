#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n, h, h0 = 0;
    scanf("%d", &n);
    int time = n + n - 1;
    while (n--)
    {
        scanf("%d", &h);
        time += abs(h - h0);
        h0 = h;
    }
    printf("%d\n", time);
    return 0;
}
