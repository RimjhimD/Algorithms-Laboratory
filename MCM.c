#include <stdio.h>
#include <limits.h>

int MatrixChainM(int p[], int n, int M[n][n]) { // p[] = dimension of the matrices in the chain
                                                 //  n = the number of matrix
                                                 // M[n][n]= the M matrix

    int i, j, k, L, q;

    for (i = 1; i <= n; i++)
        M[i][i] = 0;

    // L is chain length
    for (L = 2; L <= n; L++) {
        for (i = 1; i <= n - L + 1; i++) {
            j = i + L - 1;
            M[i][j] = INT_MAX; // Initialize to a large number
            for (k = i; k < j; k++) {
                q = M[i][k] + M[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < M[i][j])
                    M[i][j] = q;
            }
        }
    }

    // Return the minimum number of multiplications needed for the entire chain
    return M[1][n];
}

int main() {
    int n; // Number of matrices
    scanf("%d", &n);

    int p[n + 1]; // Array to store dimensions of matrices
    for (int i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    // Declare M matrix with size n x n
    int M[n + 1][n + 1];

    int minMultiplications = MatrixChainM(p, n, M);



    printf("Minimum number of multiplications is %d\n", minMultiplications);
  
    return 0;
}
