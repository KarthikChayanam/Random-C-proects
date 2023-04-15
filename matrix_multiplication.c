
// THIS PROJECT IS NOT OVER, THE DETERMINANT AND INVERSE FUNCTIONS ARE YET TO BE COMPLETED


#include <stdio.h>

int m1, n1, i, j, m2, n2;

int checklegal()
{
    int legal;
    legal = (n1 == m2) ? 1 : 0;

    return legal;
}

int main()
{
    printf("\n");
    printf("Enter array dimensions of the first array : ");
    scanf("%d %d", &m1, &n1);
    int arr1[m1][n1];

    printf("Enter the elements : ");
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < n1; j++)
            scanf("%d", &arr1[i][j]);
    }

    printf("The array is\n\n");
    for (i = 0; i < m1; i++)
    {
        for (j = 0; j < n1; j++)
            printf("\t%d", arr1[i][j]);
        printf("\n");
    }

    printf("\n");

    printf("Enter array dimensions of the second array : ");
    scanf("%d %d", &m2, &n2);
    int arr2[m2][n2];

    printf("Enter the elements : ");
    for (i = 0; i < m2; i++)
    {
        for (j = 0; j < n2; j++)
            scanf("%d", &arr2[i][j]);
    }

    printf("The array is\n\n");
    for (i = 0; i < m2; i++)
    {
        for (j = 0; j < n2; j++)
            printf("\t%d", arr2[i][j]);
        printf("\n");
    }

    if (checklegal() == 0)
        printf("Cannot multiply both matrices");
    else
    {
        int rows, cols, sum, k;
        rows = m1;
        cols = n2;
        int mult[rows][cols];

        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < cols; j++)
            {
                sum = 0;
                for (k = 0; k < m2; k++)
                    sum = sum + (arr1[i][k] * arr2[k][j]);
                mult[i][j] = sum;
            }
        }

        printf("\nThe multiplied array is \n\n");

        for (i = 0; i < m2; i++)
        {
            for (j = 0; j < n2; j++)
                printf("\t%d", mult[i][j]);
            printf("\n");
        }
    }

    return 0;
}
