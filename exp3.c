#include <stdio.h>
#include <stdlib.h>

int rows, cols;

struct Sparse{
    int row;
    int col;
    int value;
};

void sparseMatrix(int matrix[rows][cols]){
    struct Sparse* sparseMat = (struct Sparse*) malloc(sizeof(struct Sparse));
    sparseMat->row = rows;
    sparseMat->col = cols;
    sparseMat->value = 0;

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(matrix[i][j] != 0){
                sparseMat->value++;

                sparseMat = (struct Sparse*) realloc(sparseMat, sparseMat->value * sizeof(struct Sparse));
                (sparseMat+(sparseMat->value))->row = i;
                (sparseMat+(sparseMat->value))->col = j;
                (sparseMat+(sparseMat->value))->value = matrix[i][j];
            }
        }
    }

    for(int i=0; i<sparseMat->value+1; i++){
        printf("%d %d %d\n", (sparseMat+i)->row, (sparseMat+i)->col, (sparseMat+i)->value);
    }
}

int main(){
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of cols: ");
    scanf("%d", &cols);

    int matrix[rows][cols];
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("Element [%d]: ", i);
            scanf("%d", &matrix[i][j]);
        }
    }

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("SPARSE:\n");
    sparseMatrix(matrix);
}