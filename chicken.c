#include <stdio.h>
#include <math.h>

int cmp(const void *a, const void *b)
{
    return (*(double*)b - *(double*)a);
}

int main()
{
    int n, k;
    double c[1001];
    double ans = 0;

    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
    {
        scanf("%lf", &c[i]);
    }

    qsort(c, n, sizeof(double), cmp);
    c[n] = 0;
    while(fabs(c[k - 1]) >= 0.001)
    {
        int l = k - 1, r = k - 1;
        while((l - 1) >= 0 && c[l - 1] == c[k - 1]) l--;
        while(c[r + 1] == c[k - 1]) r++;
        if(l == r) {
            double dx = c[l] - c[l + 1];
            for(int i = 0; i < k; i++) c[i] -= dx;
            ans += dx;
            continue;
        }
        if(l == 0) {
            for(int i = 0; i < n; i++)
                ans += c[i] / k;
            break;
        }
        double dx1 = (c[l - 1] - c[l]) * (r - l + 1) / (r - k + 1);
        double dx2 = (c[r] - c[r + 1]) * (r - l + 1) / (k - l);
        double dx = (dx1 < dx2) ? dx1 : dx2;
        double dy = (k - l) * dx / (r - l + 1);
        ans += dx;
        for(int i = 0; i < l; i++) c[i] -= dx;
        for(int i = l; i <= r; i++) c[i] -= dy;
    }

    printf("%.3lf", ans);
    return 0;
}