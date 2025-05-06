#include <stdio.h>
#include <stdlib.h>

//链表节点结构体
typedef struct Node
{
    /* data */
    int data;
    struct Node* next;
} Node; //Node是这个结构体的标签(tag),在C语言中,这么写方便我们调用这个struct,而且必须有



//队列的结构体
typedef struct Queue {
    Node* front;
    Node* rear; //队尾指针
    int length; //队伍长度
} Queue;

//初始化队列
Queue* initQueue(){ //Queue* 这里的星号是用于表明函数返回一个指针类型
    Queue* q = (Queue*)malloc(sizeof(Queue)); //malloc 是一个标准库函数，用于在程序的运行时动态分配内存
    q->front = NULL; //q:是一个指向 Queue 结构体的指针，通常通过内存分配创建
    q->rear = NULL; //借助q的力量让front和rear两个指针归为NULL
    q->length = 0;
    return q;
}

//在队尾添加元素
void append(Queue* q, int x){
    Node* newNode = (Node*)malloc(sizeof(Node)); //(Node*) 的作用呢是把void类型转化为Node*类型
    newNode->data = x; //如果换成python的话应该等同于newNode.val=x
    newNode->next = NULL;
    if (q->rear == NULL){
        q->front = newNode;
        q->rear = newNode;
    } else{

        q->rear->next = newNode;
        q->rear = newNode; //把指针赋给newNode
    }
    q->length ++;


}

// 删除队列头部元素
int popLeft(Queue* q) {
    if (q->front == NULL){
        printf("Queue is empty!");
        exit(1);
    }
    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL){
        q->rear = NULL;
    }
    free(temp);
    q->length--;
    return data;
}

// 获取队头元素

int getLeft(Queue*q){
    if (q->front == NULL){
        printf("empty!");

        exit(1);

    }
    return q->front->data;

}

// 检查空队列

int isEmpty(Queue*q){
    return q->length == 0;

}

// 获取队列长度
int getLength(Queue* q){
    return q->length;
}

