#include <stdio.h>
#define MAX 100

int main() {
    int c1[MAX], e1[MAX], c2[MAX], e2[MAX];
    int c3[MAX] = {0};
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

    int maxExp = 0;

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            int exp = e1[i] + e2[j];
            c3[exp] += c1[i] * c2[j];
            if (exp > maxExp)
                maxExp = exp;
        }
    }

    printf("\nResultant Polynomial:\n");
    for (int i = maxExp; i >= 0; i--) {
        if (c3[i] != 0)
            printf("%dx^%d + ", c3[i], i);
    }

    printf("\b\b \n");
    return 0;
}
