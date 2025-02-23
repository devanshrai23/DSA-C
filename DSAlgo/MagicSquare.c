#include <stdio.h>

void generateMagicSquare(int n) {
    if (n % 2 == 0) {
        printf("Magic square is only possible for odd dimensions\n");
        return;
    }

    int magicSquare[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            magicSquare[i][j] = 0;
        }
    }

    int i = 0;
    int j = n / 2;

    for (int num = 1; num <= n * n; num++) {
        magicSquare[i][j] = num;

        int nextI = (i - 1 + n) % n;
        int nextJ = (j + 1) % n;

        if (magicSquare[nextI][nextJ] != 0) {
            nextI = (i + 1) % n;
            nextJ = j;
        }

        i = nextI;
        j = nextJ;
    }

    printf("\nThe Magic Square of size %d is:\n", n);
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            printf("%d ", magicSquare[x][y]);
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the size of the magic square (odd number): ");
    scanf("%d", &n);

    generateMagicSquare(n);

    return 0;
}
