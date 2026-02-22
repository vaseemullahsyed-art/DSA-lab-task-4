#include <stdio.h>

#define MAX 100

void transpose(int sparse[MAX][3], int result[MAX][3]) {
    int rows = sparse[0][0];
    int cols = sparse[0][1];
    int terms = sparse[0][2];

    result[0][0] = cols;
    result[0][1] = rows;
    result[0][2] = terms;

    int k = 1;

    for (int i = 0; i < cols; i++) {
        for (int j = 1; j <= terms; j++) {
            if (sparse[j][1] == i) {
                result[k][0] = sparse[j][1];
                result[k][1] = sparse[j][0];
                result[k][2] = sparse[j][2];
                k++;
            }
        }
    }
}

int main() {
    int sparse[MAX][3], result[MAX][3];
    int terms;

    printf("Enter number of non-zero elements: ");
    scanf("%d", &terms);

    printf("Enter row, column, value:\n");

    sparse[0][0] = 4;   // Example rows
    sparse[0][1] = 4;   // Example columns
    sparse[0][2] = terms;

    for (int i = 1; i <= terms; i++)
        scanf("%d %d %d", &sparse[i][0], &sparse[i][1], &sparse[i][2]);

    transpose(sparse, result);

    printf("\nTranspose Matrix (3-Tuple Form):\n");
    for (int i = 0; i <= terms; i++)
        printf("%d %d %d\n", result[i][0], result[i][1], result[i][2]);

    return 0;
}
