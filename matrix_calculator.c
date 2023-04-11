#include <stdio.h>

void new_matrix();
void add_matrices();
void sub_matrices();

int total_dim[8];
int i,j,k,dims = 0;
int matrices[4][10][10];


void main() {

    int operator;

    do {
    printf("\n\nChoose an operator\n");
    printf("1) New Matrix\n");
    printf("2) Adding Matrix\n");
    printf("3) Subtracting Matrix\n");
    printf("4) Transpose of Matrix\n");
    printf("5) Inverse of Matrix\n");
    printf("6) Matrix Multiplication\n");
    printf("7) EXIT\n");
    printf("Choose an operator : ");
    scanf("%d",&operator);

    if (operator == 1)
        new_matrix();
    else if (operator == 2)
        add_matrices();
    else if (operator == 3)
        sub_matrices();
    else if (operator == 7)
        break;

    
    }
    while (1);
    

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
    
}

void sub_matrices() {
    
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
                temp[i][j] = (matrices[a][i][j] - matrices[b][i][j]);
                printf("\t%d",temp[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    
}