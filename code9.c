// Backtracking Approach
#include <stdio.h>

int knapsack_backtrack(int w[], int v[], int n, int W, int index, int current_weight, int current_value) {
    if (index == n || current_weight == W) {
        return current_value;  // Base case: No more items or knapsack full
    }

    int exclude = knapsack_backtrack(w, v, n, W, index + 1, current_weight, current_value);

    int include = 0;
    if (current_weight + w[index] <= W) {
        include = knapsack_backtrack(w, v, n, W, index + 1, current_weight + w[index], current_value + v[index]);
    }

    return (include > exclude) ? include : exclude;
}







//Branch & Bound Approach


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int level, profit, weight;
    float bound;
} Node;

float bound(Node u, int n, int W, int w[], int v[]) {
    if (u.weight >= W) return 0;

    float profit_bound = u.profit;
    int j = u.level + 1;
    int total_weight = u.weight;

    while (j < n && total_weight + w[j] <= W) {
        total_weight += w[j];
        profit_bound += v[j];
        j++;
    }
    if (j < n) {
        profit_bound += (W - total_weight) * ((float)v[j] / w[j]);
    }
    return profit_bound;
}

int knapsack_branch_bound(int W, int w[], int v[], int n) {
    Node Q[100];  // Priority queue
    int front = -1, rear = -1;

    Node u, v_node;
    u.level = -1, u.profit = 0, u.weight = 0;
    Q[++rear] = u;

    int max_profit = 0;

    while (front < rear) {
        u = Q[++front];

        if (u.level == n - 1) continue;

        v_node.level = u.level + 1;

        v_node.weight = u.weight + w[v_node.level];
        v_node.profit = u.profit + v[v_node.level];

        if (v_node.weight <= W && v_node.profit > max_profit) {
            max_profit = v_node.profit;
        }
        v_node.bound = bound(v_node, n, W, w, v);

        if (v_node.bound > max_profit) {
            Q[++rear] = v_node;
        }

        v_node.weight = u.weight;
        v_node.profit = u.profit;
        v_node.bound = bound(v_node, n, W, w, v);

        if (v_node.bound > max_profit) {
            Q[++rear] = v_node;
        }
    }

    return max_profit;
}






//Dynamic Programming Approach

#include <stdio.h>

int knapsack_dp(int w[], int v[], int n, int W) {
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (w[i - 1] <= j) {
                dp[i][j] = (v[i - 1] + dp[i - 1][j - w[i - 1]] > dp[i - 1][j]) ? 
                            v[i - 1] + dp[i - 1][j - w[i - 1]] : dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][W];
}


/* Performance Comparison
Backtracking:
Guarantees correctness but explores all subsets.
Least efficient for large datasets due to redundant calculations.

Branch & Bound:
Prunes unnecessary exploration intelligently, making it faster than backtracking.
Performance depends on the quality of the bounding function.

Dynamic Programming:
Optimal for small to medium knapsack capacities.
Efficient in terms of time for most cases but can use significant memory for large capacities.
*/
