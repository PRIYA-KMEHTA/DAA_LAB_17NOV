#include<stdio.h>
struct Node{
int key;
struct Node* left,right= NULL;
}
struct Node* newNode(int key){
    struct Node* node=(struct Node*)malloc(sizeof(struct Node*));
    node->key=key;
    node->left = node->right = NULL;
    return node;
}
struct Node* recursive_insert(struct Node* node,int key){
    if(node==NULL)
        return newNode(key);
    else if(node->key < key)
        recursive_insert(node->right,key);
    else
        recursive_insert(node->left,key);
}
struct Node* iterative_insert(struct Node* root,int key){
    struct Node* node=newNode(int key);
    if(root==NULL)
        return node;
    struct Node* current=root;
    struct Node* parent=NULL;
    while(current!=NULL){
        parent=current;
        if(current->key < key)
            current=current->left;
        else
            current=current->right;
    }
    if(key < parent->key)
        parent->left=node;
    else
        parent->right=node;
    return root;
}
/* 1. Time Complexity 
Both recursive and iterative insertions have the same time complexity:
Best Case: 𝑂(log𝑛)
O(logn) (in a balanced BST)
Worst Case: 𝑂(𝑛)
O(n) (in a skewed BST, like a linked list)
This is because in both cases, the algorithm must traverse the tree from the root to the appropriate leaf node where the new key will be inserted.

2. Space Complexity

Recursive Insertion:
Space complexity: 𝑂(ℎ)
O(h), where ℎ
h is the height of the tree.
This is due to the function call stack in recursion. For a balanced tree, ℎ=log𝑛
h=logn, while for a skewed tree, ℎ=𝑛
h=n.

Iterative Insertion:
Space complexity: 𝑂(1)O(1).
The iterative method does not use a call stack; it uses only a few extra variables for traversal, making it more memory-efficient.

3. Overhead

Recursive Insertion:
Overhead: Function calls create additional overhead due to pushing and popping from the call stack.
Stack overflow risk: If the tree is highly skewed and deep, recursion may lead to a stack overflow error.

Iterative Insertion:
Overhead: None. It uses a simple loop for traversal, avoiding the recursive call overhead.
No stack overflow: Suitable for deep or highly skewed trees.

4. Code Complexity and Readability

Recursive Insertion:
Simpler code: The recursive approach is generally more concise and easier to understand for beginners.
Natural to implement: Tree traversal is inherently recursive, so recursive code closely mirrors the logical structure of the tree.

Iterative Insertion:
More complex code: Managing parent pointers and maintaining traversal states can make the code more verbose and harder to read.
Preferred for large trees: Despite complexity, iterative methods are safer and more scalable for larger datasets.

5. Practical Use Cases

Recursive Insertion:
Ideal for small or balanced trees where recursion depth is not a concern.
Easier to debug and maintain due to simpler implementation.

Iterative Insertion:
Better for production systems with large or unpredictable tree depths.
Preferred in performance-critical systems to minimize memory usage and prevent stack overflow.*/

