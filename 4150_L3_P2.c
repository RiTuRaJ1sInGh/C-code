#include <stdio.h>
#include <stdlib.h>

void InputSparse(int Mat[][3]);

void PrintSparse(int Mat[][3]);

char rel(int a, int b);

void add(int Mat1[][3], int Mat2[][3], int Mat3[][3]);

int main()
{

    int SMat1[10][3], SMat2[10][3], SMat3[10][3];

    printf("Enter the number of rows-->\n");
    scanf("%d", &SMat1[0][0]);

    printf("Enter the number of columns-->\n");
    scanf("%d", &SMat1[0][1]);

    printf("Enter the number of non zero elements-->\n");
    scanf("%d", &SMat1[0][2]);

    // Sorting the values of  the first sparse matrix from user

    InputSparse(SMat1);

    // Printing the Sparse matrix

    PrintSparse(SMat1);

    // For 2nd Sparse matrix

    printf("Enter the number of rows of 2nd Sparse matrix-->\n");
    scanf("%d", &SMat2[0][0]);

    printf("Enter the number of columns of 2nd Sparse matrix-->\n");
    scanf("%d", &SMat2[0][1]);

    printf("Enter the number of non zero elements of 2nd Sparse matrix-->\n");
    scanf("%d", &SMat2[0][2]);

    // Input of 2nd Sparse matrix

    InputSparse(SMat2);

    // Printing the 2nd sparse matrix

    PrintSparse(SMat2);
    if ((SMat1[0][0] != SMat2[0][0]) || (SMat1[0][1] != SMat2[0][1]))
    {
        printf("Invalid operation\n");
    }
    else
    {
        add(SMat1, SMat2, SMat3);

        printf("Sum of the two sparse matrix is -->\n");

        PrintSparse(SMat3);
    }

    return 0;
}

void InputSparse(int Mat[][3])
{
    for (int i = 1; i <= Mat[0][2]; i++)
    {
        printf("Enter the position of row -->\n");
        scanf("%d", &Mat[i][0]);

        printf("Enter the position of column -->\n");
        scanf("%d", &Mat[i][1]);

        printf("Enter the non zero element -->\n");
        scanf("%d", &Mat[i][2]);
    }
}

void PrintSparse(int Mat[][3])
{
    for (int i = 0; i <= Mat[0][2]; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%4d", Mat[i][j]);
        }
        printf("\n");
    }
}

char rel(int a, int b)
{
    if (a < b)
    {
        return '<';
    }
    else if (a > b)
    {
        return '>';
    }
    else
    {
        return '=';
    }
}

void add(int Mat1[][3], int Mat2[][3], int Mat3[][3])
{
    int i = 1, j = 1, k = 0, m, n;

    if ((Mat1[0][0] != Mat2[0][0]) || (Mat1[0][1] != Mat2[0][1]))
    {
        printf("Invalid operation\n");
        return;
    }

    Mat3[0][0] = Mat1[0][0];
    Mat3[0][1] = Mat1[0][1];
    m = Mat1[0][2];
    n = Mat2[0][2];

    while (i <= m && j <= n)
    {
        k++;

        switch (rel(Mat1[i][0], Mat2[j][0]))
        {
        case '=':
            switch (rel(Mat1[i][1], Mat2[j][1]))
            {
            case '=':
                Mat3[k][0] = Mat1[i][0];
                Mat3[k][1] = Mat1[i][1];
                Mat3[k][2] = Mat1[i][2] + Mat2[j][2];
                i++;
                j++;
                break;

            case '<':
                Mat3[k][0] = Mat1[i][0];
                Mat3[k][1] = Mat1[i][1];
                Mat3[k][2] = Mat1[i][2];
                i++;
                break;

            case '>':
                Mat3[k][0] = Mat2[j][0];
                Mat3[k][1] = Mat2[j][1];
                Mat3[k][2] = Mat2[j][2];
                j++;
                break;
            }
            break;

        case '<':
            Mat3[k][0] = Mat1[i][0];
            Mat3[k][1] = Mat1[i][1];
            Mat3[k][2] = Mat1[i][2];
            i++;
            break;

        case '>':
            Mat3[k][0] = Mat2[j][0];
            Mat3[k][1] = Mat2[j][1];
            Mat3[k][2] = Mat2[j][2];
            j++;
            break;
        }
    }

    while (i <= m)
    {
        k++;
        Mat3[k][0] = Mat1[i][0];
        Mat3[k][1] = Mat1[i][1];
        Mat3[k][2] = Mat1[i][2];
        i++;
    }

    while (j <= n)
    {
        k++;
        Mat3[k][0] = Mat2[j][0];
        Mat3[k][1] = Mat2[j][1];
        Mat3[k][2] = Mat2[j][2];
        j++;
    }

    Mat3[0][2] = k;
}