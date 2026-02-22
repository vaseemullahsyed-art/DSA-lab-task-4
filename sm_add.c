#include <stdio.h>
#define MAX 100

void addSparse(int a[MAX][3], int b[MAX][3], int result[MAX][3]) {
    int i = 1, j = 1, k = 1;
    int termsA = a[0][2];
    int termsB = b[0][2];

    result[0][0] = a[0][0];
    result[0][1] = a[0][1];

    while (i <= termsA && j <= termsB) {
        if (a[i][0] < b[j][0] ||
           (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            result[k][0] = a[i][0];
            result[k][1] = a[i][1];
            result[k][2] = a[i][2];
            i++;
        }
        else if (b[j][0] < a[i][0] ||
                (b[j][0] == a[i][0] && b[j][1] < a[i][1])) {
            result[k][0] = b[j][0];
            result[k][1] = b[j][1];
            result[k][2] = b[j][2];
            j++
        }
        else {
            result[k][0] = a[i][0];
            result[k][1] = a[i][1];
            result[k][2] = a[i][2] + b[j][2];
            i++; j++;
        }
        k++;
    }

    while (i <= termsA) {
        result[k][0] = a[i][0];
        result[k][1] = a[i][1];
        result[k][2] = a[i][2];
        i++; k++;
    }

    while (j <= termsB) {
        result[k][0] = b[j][0];
        result[k][1] = b[j][1];
        result[k][2] = b[j][2];
        j++; k++;
    }

    result[0][2] = k - 1;
}

int main() {
    int A[MAX][3], B[MAX][3], C[MAX][3];
    int termsA, termsB;

    printf("Enter non-zero elements in Matrix A: ");
    scanf("%d", &termsA);

    A[0][0] = 3; A[0][1] = 3; A[0][2] = termsA;
    printf("Enter row col value for A:\n");
    for (int i = 1; i <= termsA; i++)
        scanf("%d %d %d", &A[i][0], &A[i][1], &A[i][2]);

    printf("Enter non-zero elements in Matrix B: ");
    scanf("%d", &termsB);

    B[0][0] = 3; B[0][1] = 3; B[0][2] = termsB;
    printf("Enter row col value for B:\n");
    for (int i = 1; i <= termsB; i++)
        scanf("%d %d %d", &B[i][0], &B[i][1], &B[i][2]);

    addSparse(A, B, C);

    printf("\nResultant Sparse Matrix:\n");
    for (int i = 0; i <= C[0][2]; i++)
        printf("%d %d %d\n", C[i][0], C[i][1], C[i][2]);

    return 0;
}
