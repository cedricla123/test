#include <stdio.h>

void decimal_to_binary(int n) {
    int binary[32];
    int i = 0;

    while (n > 0) {
        binary[i] = n % 2;
        n = n / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");
}

int main() {
    int decimal;
    printf("Entrez un nombre entier: ");
    scanf("%d", &decimal);
    printf("Le nombre en binaire est: ");
    decimal_to_binary(decimal);
    return 0;
}