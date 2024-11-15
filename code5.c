/*The Matrix Chain Multiplication (MCM) problem determines the most efficient way to multiply a given sequence of matrices. The goal is to minimize the total number of scalar multiplications by choosing the optimal placement of parentheses.

Dynamic Programming Approach
The problem can be solved using Dynamic Programming by computing the cost of multiplying subchains of matrices and storing the results to avoid redundant calculations.

Steps to Solve
Identify the Problem Substructure:

To multiply matrices 𝐴1,𝐴2,…,𝐴𝑛A 1​,A 2,…,A n, we try every possible split point k and compute:

Cost=Cost(𝐴1…𝐴𝑘)+Cost(𝐴𝑘+1…𝐴𝑛)+Multiplication_CostCost=Cost(A 1…A k)+Cost(A k+1 …A n)+Multiplication_Cost
where Multiplication_Cost=𝑝[𝑖−1]⋅𝑝[𝑘]⋅𝑝[𝑗]
Multiplication_Cost=p[i−1]⋅p[k]⋅p[j].
Define the Table:

Let dp[i][j] represent the minimum cost to multiply matrices from 𝑖i to 𝑗j.
Recursive Relation:

𝑑𝑝[𝑖][𝑗]=min 𝑖<𝑘<𝑗(𝑑𝑝[𝑖][𝑘]+𝑑𝑝[𝑘+1][𝑗]+𝑝[𝑖−1]⋅𝑝[𝑘]⋅𝑝[𝑗])
dp[i][j]= i≤k<j 
min(dp[i][k]+dp[k+1][j]+p[i−1]⋅p[k]⋅p[j])
Base Case:

When i=j, 𝑑𝑝[𝑖][𝑗]=0
dp[i][j]=0 since a single matrix requires no multiplication.
Fill the Table:

Use an iterative approach to calculate costs for subchains of increasing lengths.
*/
#include <stdio.h>
#include <limits.h>

void matrixChainMultiplication(int p[], int n) {
    int dp[n][n];   
    int brackets[n][n]; 

    for (int i = 1; i < n; i++)
        dp[i][i] = 0;

 
    for (int length = 2; length < n; length++) {
        for (int i = 1; i < n - length + 1; i++) {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;

         
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + p[i-1] * p[k] * p[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    brackets[i][j] = k;
                }
            }
        }
    }

    printf("Minimum number of multiplications: %d\n", dp[1][n-1]);

  
    printf("Optimal parenthesization: ");
    printParenthesis(1, n - 1, brackets, n);
    printf("\n");
}


void printParenthesis(int i, int j, int brackets[][100], int n) {
    if (i == j) {
        printf("A%d", i);
        return;
    }
    printf("(");
    printParenthesis(i, brackets[i][j], brackets, n);
    printParenthesis(brackets[i][j] + 1, j, brackets, n);
    printf(")");
}

int main() {
    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    matrixChainMultiplication(arr, n);

    return 0;
}
/* How Parenthesis Positioning Affects Performance
Example:
Input dimensions: 
[40,20,30,10,30][40,20,30,10,30]

Different Parenthesizations:
((𝐴1×𝐴2)×(𝐴3×𝐴4))((A1×A2)×(A3×A4
​))
Cost:
40⋅20⋅30+20⋅30⋅10+40⋅10⋅30=36000
(𝐴1×(𝐴2×(𝐴3×𝐴4)))(A1×(A2×(A3×A4)))
Cost: 20⋅30⋅10+40⋅20⋅10+40⋅10⋅30=54000
20⋅30⋅10+40⋅20⋅10+40⋅10⋅30=54000
Optimal Parenthesization:
Cost: 40⋅20⋅10+40⋅10⋅30+20⋅30⋅10=26000
40⋅20⋅10+40⋅10⋅30+20⋅30⋅10=26000
Key Takeaway:
The order of multiplication dramatically impacts the computational cost. Using the DP approach ensures we find the optimal solution, minimizing the total scalar multiplications.*/

