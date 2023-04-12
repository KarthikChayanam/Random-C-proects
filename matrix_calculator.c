#include <stdio.h>
#include <stdlib.h>

void new_matrix();
void add_matrices();
void sub_matrices();
void transpose_matrix();
int determinant(int a);
void inverse_matrix();
void matrix_mult();


int total_dim[8];
int i,j,k,dims = 0;
int matrices[4][10][10];


void main() {

    int operator,a;

    do {
    printf("\n\nChoose an operator\n");
    printf("1) New Matrix\n");
    printf("2) Adding Matrix\n");
    printf("3) Subtracting Matrix\n");
    printf("4) Transpose of Matrix\n");
    printf("5) Determinant of Matrix\n");
    printf("6) Inverse of Matrix\n");
    printf("7) Matrix Multiplication\n");
    printf("8) EXIT\n");
    printf("Choose an operator : ");
    scanf("%d",&operator);

    if (operator == 1)
        new_matrix();
    else if (operator == 2)
        add_matrices();
    else if (operator == 3)
        sub_matrices();
    else if (operator == 4)
        transpose_matrix();
    else if (operator == 5) {
        printf("\n\nSelect 1 Matrix");
        printf("\nfrom 1 to %d : ",((dims+1)/2));
        scanf("%d",&a);
        a--;
        printf("%d",determinant(a));
    }
    else if (operator == 6)
        inverse_matrix();
    else if (operator == 7)
        matrix_mult();
    else if (operator == 8)
        break;
    
    }
    while (1);

    printf("Thank you");
    

}


void new_matrix() {

    printf("\n\nThere can be a total of 4 Matrices\n");
    printf("There are %d matrices left\n",(4-(dims+1)/2));
    printf("Enter the dimensions of the Matrix : ");
    scanf("%d %d",&total_dim[dims],&total_dim[dims+1]);
    printf("Enter the elements of the Matrix : ");

    for (i=0; i<total_dim[dims]; i++) {
        for (j=0; j<total_dim[dims+1]; j++)
            scanf("%d",&matrices[(dims)/2][i][j]);
    }

    printf("\nThe Matrix is\n");
    for (i=0; i<total_dim[dims]; i++) {
        for (j=0; j<total_dim[dims+1]; j++)
            printf("\t%d",matrices[(dims)/2][i][j]);
        printf("\n");
    }

    dims += 2;

}

void add_matrices() {
    
    int a,b,c;
    printf("\n\nSelect 2 Matrices");
    printf("\nfrom 1 to %d : ",((dims+1)/2));
    scanf("%d %d",&a, &b);
    a--;
    b--;

    printf("\n\n");

    if (total_dim[2*a] == total_dim[2*b] && total_dim[2*a + 1] == total_dim[2*b + 1]) {
        int temp[total_dim[2*a]][total_dim[2*a + 1]];
        for (i=0; i<total_dim[2*a]; i++) {
            for (j=0; j<total_dim[2*a + 1]; j++) {
                temp[i][j] = (matrices[a][i][j] + matrices[b][i][j]);
                printf("\t%d",temp[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    else {
        printf("Matrices cannot be added\nBecause they are not the same order");
    }
    
}

void sub_matrices() {
    
    int a,b;
    printf("\n\nSelect 2 Matrices");
    printf("\nfrom 1 to %d : ",((dims+1)/2));
    scanf("%d %d",&a, &b);
    a--;
    b--;

    printf("\n\n");

    if (total_dim[2*a] == total_dim[2*b] && total_dim[2*a + 1] == total_dim[2*b + 1]) {
        int temp[total_dim[2*a]][total_dim[2*a + 1]];
        for (i=0; i<total_dim[2*a]; i++) {
            for (j=0; j<total_dim[2*a + 1]; j++) {
                temp[i][j] = (matrices[a][i][j] - matrices[b][i][j]);
                printf("\t%d",temp[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    else {
        printf("Matrices cannot be subtraceted\nBecause they are not the same order");
    }
    
}

void transpose_matrix() {

    int a;
    printf("\n\nSelect 1 Matrix");
    printf("\nfrom 1 to %d : ",((dims+1)/2));
    scanf("%d",&a);
    a--;

    printf("\n\n");
    
    for (i=0; i<total_dim[2*a + 1]; i++) {
        for (j=0; j<total_dim[2*a]; j++) {
            int temp[total_dim[2*a + 1]][total_dim[2*a]];
            temp[i][j] = matrices[a][j][i];
            printf("\t%d",temp[i][j]);
        }
        printf("\n");
    }

}


int determinant(int a) {

    int m,n,det;
    m = total_dim[2*a];
    n = total_dim[2*a + 1];
    int temp[m][n];

    for(i=0; i<m; i++) {
        for(j=0 ; j<m; j++)
            temp[i][j] = matrices[a][i][j];
    }

    printf("\n\n");

    if (m != n) {
        printf("Cannot find determinant\nDimensions error");
    }
    else if (m == 1) {
        det = temp[0][0];
        return ("The determinant of Matrix %d is %d",((dims+1)/2),det);
    }
    else if (m == 2) {
        det = ((temp[0][0]*temp[1][1]) - (temp[0][1]*temp[1][0]));
        return ("The determinant of Matrix %d is %d",((dims+1)/2),det);
    }


}


void inverse_matrix() {

    int a,m,n,det;
    printf("\n\nSelect 1 Matrix");
    printf("\nfrom 1 to %d : ",((dims+1)/2));
    scanf("%d",&a);
    a--;

    det = determinant(a);


}


void matrix_mult() {

    int a,b,k,m,n,sum;
    printf("\n\nSelect 2 Matrix");
    printf("\nfrom 1 to %d : ",((dims+1)/2));
    scanf("%d %d",&a, &b);
    a--;
    b--;

    m = total_dim[2*a];
    n = total_dim[2*b + 1];

    printf("\n\n");

    if (total_dim[2*a + 1] == total_dim[2*b]) {
        int temp[m][n];
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                sum = 0;
                for (k = 0; k < m; k++)
                    sum = sum + (matrices[a][i][k] * matrices[a][k][j]);
                temp[i][j] = sum;
            }
        }

        printf("\nThe multiplied array is \n\n");

        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
                printf("\t%d", temp[i][j]);
            printf("\n");
        }
    }
    else {
        printf("Matrices cannot be multiplies\nDimension Error");
    }
}
