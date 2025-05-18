#include <stdio.h>

int bucket[10001];

int main()
{
    int n, ans = 0;
    while(scanf("%d", &n) != EOF)
    {
        bucket[n] = 1;
        int flag = 0;
        while(!bucket[flag]) flag++;
        ans = (ans < n - flag) ? n - flag : ans;
    }
    printf("%d", ans);
    return 0;
}
