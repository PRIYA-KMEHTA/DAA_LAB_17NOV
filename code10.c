/*Performance Comparison of Rabin-Karp, Knuth-Morris-Pratt (KMP), and Naive String-Matching Algorithms

String-matching algorithms find occurrences of a **pattern** string in a **text** string. Their performance varies based on the problem size, pattern characteristics, and preprocessing requirements. Here's a comparison of these algorithms:


1. Naive String-Matching Algorithm

How It Works:
- Compares the pattern with each substring of the text, character by character.
- If a mismatch occurs, shifts the pattern by one position in the text and repeats.

Time Complexity:
Best Case: \(O(n)\), when mismatches occur at the first character for each position.
Worst Case: \(O(nm)\), when the pattern and text have many matching prefixes.
  - \(n\): Length of the text.
  - \(m\): Length of the pattern.

Space Complexity:
- \(O(1)\), as no additional data structures are used.

Strengths:
- Simple to implement.
- Useful for small text and pattern sizes.

Weaknesses:
- Inefficient for large texts or patterns with many repetitive characters.



2. Rabin-Karp Algorithm

How It Works:
- Uses hashing to compare pattern and text substrings.
- Computes a hash for the pattern and for each substring of the text of the same length.
- Matches occur when the hash values are the same (and an additional character-by-character check confirms the match).

Time Complexity:
- Average Case: \(O(n + m)\), with good hash functions and few hash collisions.
- Worst Case: \(O(nm)\), when many hash collisions occur, requiring multiple character comparisons.

Space Complexity:
- \(O(1)\), as only hash values and a few variables are maintained.

Strengths:
- Effective for single-pattern matching in large texts when hash collisions are rare.
- Easily extendable for multi-pattern matching.

Weaknesses:
- Hash collisions degrade performance.
- Requires a good hash function for efficiency.

---

3. Knuth-Morris-Pratt (KMP) Algorithm

How It Works:
- Preprocesses the pattern to construct a partial match table (LPS array).
- Uses the LPS array to avoid redundant comparisons, effectively skipping parts of the text.

Time Complexity:
- Preprocessing: \(O(m)\), for building the LPS array.
- Search: \(O(n)\), as each character is compared at most once.
- Overall: \(O(n + m)\).

Space Complexity:
- \(O(m)\), for storing the LPS array.

Strengths:
- Guarantees linear time complexity for all inputs.
- Efficient for large texts with repetitive patterns.

Weaknesses:
- Requires preprocessing of the pattern.
- More complex to implement than naive and Rabin-Karp algorithms.

---

Performance Comparison

1. Efficiency:
- Naive: Performs well for small inputs but is inefficient for large inputs.
- Rabin-Karp: Efficient for single-pattern matching with low collision rates but degrades to \(O(nm)\) with many collisions.
- KMP: Always performs in \(O(n + m)\), making it robust for all inputs.

2. Use Cases:
- **Naive**: Small inputs, educational purposes, or rare use cases where simplicity matters.
- **Rabin-Karp**: Large texts with single or multiple patterns, especially if a good hash function minimizes collisions.
- **KMP**: General-purpose, large-scale string matching with guaranteed linear performance.

3. Complexity:
- Naive: Simple and straightforward.
- Rabin-Karp: Relatively simple but requires hash function implementation.
- KMP: More complex due to LPS preprocessing.

---

Example Application Scenarios

1. Naive: Useful when:
   - Text and pattern sizes are small.
   - Performance is not critical.

2. Rabin-Karp: Ideal for:
   - Detecting plagiarism or substring matching in large documents.
   - Searching multiple patterns using a single hash function.

3. KMP: Best suited for:
   - Large-scale, high-performance applications.
   - Repeated searches of a fixed pattern in a long text.

---
Conclusion

- For guaranteed linear performance, KMP is the best choice.
- When hashing is effective, Rabin-Karp is efficient for large-scale problems.
- For simple or small problems, the Naive algorithm is sufficient.*/
