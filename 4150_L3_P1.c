#include <stdio.h>

int main()
{
    int n;
    printf("Enter the no of columns in Sparse");
    scanf("%d", &n);
    int s[n][3], t[100][3];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &s[i][j]);
        }
    }
    int k = 1;
    for (int i = 0; i <= s[0][1]; i++)
    {
        for (int j = 1; j <= s[0][1]; j++)
        {
            if (s[j][1] == i)
            {
                t[k][0] = s[j][1];
                t[k][1] = s[j][0];
                t[k][2] = s[j][2];
                k++;
            }
        }
    }
    t[0][0] = s[0][1];
    t[0][1] = s[0][0];
    t[0][2] = s[0][2];
    printf("R C V\n");
    for (int i = 0; i < k; i++)
    {
        if (i != 1)
        {

            for (int j = 0; j < 3; j++)
            {
                printf("%d ", t[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}