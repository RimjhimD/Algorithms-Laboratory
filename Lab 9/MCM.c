#include <stdio.h>
#include <limits.h>

// Function to perform Matrix Chain Multiplication and print the M and K matrices
void MatrixChainM(int p[], int n) {

    int M[n + 1][n + 1];
    int K[n + 1][n + 1];
    int i, j, k, L, q;

    // Initialize M[i][i] to 0 for all i (base case)
    for (i = 1; i <= n; i++) {
        M[i][i] = 0;
    }

    // L is chain length
    for (L = 2; L <= n; L++) {
        for (i = 1; i <= n - L + 1; i++) {
            j = i + L - 1;
            M[i][j] = INT_MAX; // Initialize to a large number
            for (k = i; k < j; k++) {
                q = M[i][k] + M[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < M[i][j]) {
                    M[i][j] = q;
                    K[i][j] = k; // Record where the split occurs for optimal multiplication
                }
            }
        }
    }


    // Set the lower triangle of M  matrix to 0
    for (i = 1; i <= n; i++) {
        for (j = 1; j < i; j++) {
            M[i][j] = 0;
        }
    }

     // Set the lower triangle of K matrix to 0
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if(j<=i)
            K[i][j] = 0;
        
        }
    }


    // Print the minimum number of multiplications needed for the entire chain
    printf("Minimum number of multiplication needed  is %d\n", M[1][n]);

    // Print the M matrix
    printf("M matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%d\t", M[i][j]);
        }
        printf("\n");
    }

    // Print the K matrix
    printf("K matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%d\t", K[i][j]);
        }
        printf("\n");
    }
}

int main() 
{
    int n; // Number of matrices
    scanf("%d", &n);

    int p[n + 1]; // Array to store dimensions of matrices
    for (int i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    // Call the MatrixChainM function to perform the calculation and print the matrices
    MatrixChainM(p, n);

    return 0;
}

