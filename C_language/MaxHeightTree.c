//
// Created by lenovo on 3/2/2025.
//

#include <stdio.h>
#include <stdlib.h>

// Definition of the TreeNode structure
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;// 如果通过 typedef 定义就需要添加一个别名



// Helper function to create a new TreeNode
TreeNode* createTreeNode(int val, TreeNode* left, TreeNode* right) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    node->val = val;
    node->left = left;
    node->right = right;
    return node;
}

// Function to calculate maximum depth of binary tree
int maxDepth(TreeNode* root) {
    // Base case: if node is NULL, depth is 0
    if (root == NULL) {
        return 0;
    }

    // Recursively calculate depth of left and right subtrees
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    // Return the maximum of left and right depths plus 1 for current node
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}
//说一下
//条件运算符部分：(leftDepth > rightDepth ? leftDepth : rightDepth)
//这是一个三元运算符，格式为 条件 ? 表达式1 : 表达式2。
//
//条件：leftDepth > rightDepth，检查左子树的深度 (leftDepth) 是否大于右子树的深度 (rightDepth)。
//
//结果：
//如果条件为真（即 leftDepth > rightDepth），返回 leftDepth。
//
//如果条件为假（即 leftDepth <= rightDepth），返回 rightDepth。
//
//简单来说，这部分的作用是选择左子树和右子树中较大的深度。

// Main function to test the solution
int main() {
    // Create the example tree: [3,9,20,null,null,15,7]
    TreeNode* node15 = createTreeNode(15, NULL, NULL);
    TreeNode* node7 = createTreeNode(7, NULL, NULL);
    TreeNode* node20 = createTreeNode(20, node15, node7);
    TreeNode* node9 = createTreeNode(9, NULL, NULL);
    TreeNode* root = createTreeNode(3, node9, node20);

    // Calculate and print the maximum depth
    int depth = maxDepth(root);
    printf("Maximum depth: %d\n", depth);  // Should output: 3

    // Free allocated memory
    free(node15);
    free(node7);
    free(node20);
    free(node9);
    free(root);

    return 0;
}

