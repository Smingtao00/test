#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAXWORD 201

int main()
{
    char s[MAXWORD];
    int len;
    int sum = 0, ans = 0, k = 0;

    scanf("%s", s + 1);
    s[0] = 's';
    len = strlen(s);
    for(int i = len; i >= 0; i--)
    {
        if(isdigit(s[i])) {
            sum += (s[i] - '0') * pow(10, k);
            k++;
        }
        else {
            if(s[i] == '-') {
                sum = 0 - sum;
                k = 0;
            }
            else {
            ans += sum;
            sum = 0;
            k = 0;
            }
        }
    }
    printf("%d", ans);
    return 0;
}
