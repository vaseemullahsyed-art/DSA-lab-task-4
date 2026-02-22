#include <stdio.h>
#define MAX 50

void addPoly(int c1[], int e1[], int n1,
             int c2[], int e2[], int n2) {

    int i = 0, j = 0;

    while (i < n1 && j < n2) {
        if (e1[i] == e2[j]) {
            printf("%dx^%d + ", c1[i] + c2[j], e1[i]);
            i++; j++;
        }
        else if (e1[i] > e2[j]) {
            printf("%dx^%d + ", c1[i], e1[i]);
            i++;
        }
        else {
            printf("%dx^%d + ", c2[j], e2[j]);
            j++;
        }
    }

    while (i < n1) {
        printf("%dx^%d + ", c1[i], e1[i]);
        i++;
    }

    while (j < n2) {
        printf("%dx^%d + ", c2[j], e2[j]);
        j++;
    }

    printf("\b\b \n");
}

int main() {
    int c1[MAX], e1[MAX], c2[MAX], e2[MAX];
    int n1, n2;

    printf("Enter number of terms in polynomial 1: ");
    scanf("%d", &n1);

    printf("Enter coefficient and exponent:\n");
    for (int i = 0; i < n1; i++)
        scanf("%d %d", &c1[i], &e1[i]);

    printf("Enter number of terms in polynomial 2: ");
    scanf("%d", &n2);

    printf("Enter coefficient and exponent:\n");
    for (int i = 0; i < n2; i++)
        scanf("%d %d", &c2[i], &e2[i]);

    printf("\nResultant Polynomial:\n");
    addPoly(c1, e1, n1, c2, e2, n2);

    return 0;
}
