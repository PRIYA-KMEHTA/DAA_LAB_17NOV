/* The 0/1 Knapsack Problem involves selecting items with given weights and values to maximize the total value while staying within a weight limit. Let's compare the Greedy and Dynamic Programming (DP) approaches for solving the problem using the same dataset.


Problem Setup
You have:
- A set of items, each with a value \(v_i\) and weight \(w_i\).
- A knapsack with a maximum weight capacity \(W\).

Your goal is to maximize the total value of selected items while keeping the total weight \(\leq W\).

---

Greedy Approach
1. Strategy: The greedy method sorts items by a specific criterion, usually the **value-to-weight ratio** (\(v_i / w_i\)).
2. Steps:
   - Sort items in descending order of \(v_i / w_i\).
   - Pick items in this order, fully including them until the knapsack cannot accommodate the next item.
3. Limitations:
   - Does **not guarantee the optimal solution** for the 0/1 Knapsack problem because selecting based on a single criterion (e.g., \(v_i / w_i\)) may miss globally optimal combinations.
   - Only optimal for **fractional knapsack** problems where items can be partially included.
4. Time Complexity: \(O(n \log n)\) for sorting, where \(n\) is the number of items.

---

Dynamic Programming Approach
1. Strategy: DP uses a table to calculate the optimal solution by evaluating all possible combinations of items up to the given weight capacity.
2. Steps:
   - Define a 2D DP array \(dp[i][w]\), where \(i\) represents the first \(i\) items and \(w\) is the current weight limit.
   - Recurrence relation:
     \[
     dp[i][w] = \max(dp[i-1][w], dp[i-1][w-w_i] + v_i)
     \]
     - If the item is excluded: \(dp[i-1][w]\).
     - If the item is included: \(dp[i-1][w-w_i] + v_i\) (only if \(w_i \leq w\)).
   - Compute \(dp[i][w]\) iteratively for all items and weight limits.
3. Output:
   - The value at \(dp[n][W]\) gives the maximum value that can be achieved.
   - The included items can be found by backtracking through the table.
4. Time Complexity: \(O(nW)\), where \(W\) is the maximum weight capacity.

---

Comparison for the Same Dataset

Example Dataset:
- Items: \( \{(v_1=60, w_1=10), (v_2=100, w_2=20), (v_3=120, w_3=30)\} \)
- Capacity: \(W = 50\).

Greedy Approach
1. Sort by \(v_i / w_i\): 
   - Item 1: \(60/10 = 6.0\)
   - Item 2: \(100/20 = 5.0\)
   - Item 3: \(120/30 = 4.0\).
2. Select items in order:
   - Add Item 1 (\(w = 10\), \(v = 60\)).
   - Add Item 2 (\(w = 20\), \(v = 100\)).
   - Cannot fully add Item 3 (\(w = 30\)) as capacity is exceeded.
3. Total value: \(160\).

Dynamic Programming Approach
1. Build the DP table:
   - Consider all combinations of items up to \(W = 50\).
   - \(dp[3][50] = 220\) (Items 2 and 3 selected).
2. Total value: \(220\).



Analysis
- Optimality: The greedy approach gives a suboptimal solution (\(160\)) because it prioritizes local criteria (value-to-weight ratio). The DP approach finds the globally optimal solution (\(220\)).
- Efficiency:
  - Greedy is faster (\(O(n \log n)\)) but less accurate.
  - DP takes \(O(nW)\) time, which can be computationally expensive for large \(W\).



Conclusion
- Use the Greedy approach when the dataset is large, \(W\) is very high, or approximate solutions are acceptable.
- Use the Dynamic Programming approach for accurate results when \(W\) is moderate or when optimality is critical.*/
