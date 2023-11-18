#include <stdio.h>

struct Poly{
    int coeff;
    int expo;
};

int main(){
    int n;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    struct Poly polynomial[n];
    for(int i=0; i<n; i++){
        printf("Enter coefficient: ");
        scanf("%d", &polynomial[i].coeff);
        printf("Enter exponent: ");
        scanf("%d", &polynomial[i].expo);
    }

    printf("The representation of the polynomial is ");
    for(int i=0; i<n-1; i++){
        printf("%d^%d + ", polynomial[i].coeff, polynomial[i].expo);
    }
    printf("%d^%d\n", polynomial[n-1].coeff, polynomial[n-1].expo);
    return 0;
}