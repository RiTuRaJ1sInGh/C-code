#include <stdio.h>

int main()
{
    int n;
    printf("Enter the highest degree");
    scanf("%d", &n);
    int a[n];
    int b[n];
    int r[n];
    printf("Enter poly-1 from highest order to lowest");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter poly-2 from highest order to lowest");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < n; i++)
    {
        r[i] = a[i] + b[i];
    }
    int k = n - 1;
    for (int i = 0; i < n; i++)
    {
        printf("%d", r[i]);
        if (i != n - 1)
        {
            printf("x^%d+", k);
        }
        k--;
    }

    return 0;
}