//
// Created by lenovo on 3/2/2025.
//

#include "stdio.h"   //#include "stdio.h" 和 #include <stdio.h> 的效果通常是一样的
#include "stdlib.h"

//TreeNode 结构体
typedef struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;

} TreeNode;

//TreeNode函数
TreeNode* creatTreeNode(int val,TreeNode* left,TreeNode* right) {
    TreeNode* node =(TreeNode*)malloc(sizeof(TreeNode));
    if (node == NULL) {
        printf("内存分配失败\n");
        exit(1);

    }
    node->val = val;
    node->left = left;
    node->right = right;
    return node;

}

// 初始化 Result 结构体
typedef struct {
    int* array;
    int size;
    int capacity;

} Result;

// 初始化Result 结构体函数
Result* createResult(int initialCapacity){
    Result* res = (Result*)malloc(sizeof(Result));
    //这里展开讲下：
    // sizeof(Result) 计算的是 Result 结构体的大小
    // 假设 int* 是 8 字节，int 是 4 字节，
    // 那么 Result 的大小可能是 8 + 4 + 4 = 16 字节，具体取决于系统架构。
    //其次
    // malloc 返回一个 void* 类型的指针，表示分配的内存地址。
    // (Result*)是一个类型转换操作，告诉编译器把这个内存地址当作 Result 结构体的指针


    if (res == NULL) {
        printf("内存分配失败\n");
        exit(1);

    }
    res->array = (int*) malloc(initialCapacity * sizeof(int ));
    if (res->array == NULL){
        printf("内存分配失败");
        exit(1);
    }
    res->size=0;
    res->capacity = initialCapacity;
    return res;

}

//向Result 中添加元素
void appendtoResult(Result* res, int val){
    if (res->size >= res->capacity){
        res->capacity *= 2;
        res->array = (int*)realloc(res->array, res->capacity * sizeof(int));
        if (res->array==NULL){
            printf("内存重新分配失败");
            exit(1);
        }
    }
    res->array[res->size++] = val;
}

//C语言要求释放内存
void freeResult(Result* res) {
    free(res->array);
    free(res);

}

//中序遍历的辅助函数
void inorder(TreeNode* root, Result* res){
    if (root == NULL){
        return;
    }
    inorder(root->left, res);
    appendtoResult(res, root->val);
    inorder(root->right, res);

}

//中序遍历主函数
Result* inorderTraversal(TreeNode* root){
    Result* res = createResult(10);
    inorder(root,res);
    return res;

}