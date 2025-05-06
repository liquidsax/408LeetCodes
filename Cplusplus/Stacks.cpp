//
// Created by lenovo on 3/9/2025.
//

//用代码实现Stack功能

class ArrayStack{
private:
    int data[100];
    int top;

public:
    ArrayStack() : top(-1){} //初始化
    bool push(int value){
        if (top >= 99) return false; //already full stack
        data[++top] = value; // push value on the top
        return true;

    }

    bool pop(int &value){
        if (top == -1) return false;
        value = data[top--];//top--是先使用top的当前值，再让top减1
        return true;
    };


    int peek() const{
        //const表示这个peek函数不会修改类的任何成员变量。
        //它只是读取栈顶元素的值并返回，而不会改变栈的状态。
        return (top != -1) ? data[top] : -1;
        //condition ? expression_if_true : expression_if_false;
    }
    bool isempty() const{
        return (top != -1);
    }

};


template <typename T>
//typename 是一个关键字，用于告诉编译器接下来的标识符T是一个类型参数。
//T 是一个占位符，表示任意类型。你可以在模板中使用T来代替具体的类型，比如int、double、std::string等。
class LinkedListStack{
private:
    struct Node{
        T data;
        Node* next;
        Node(T d,Node* n) : data(d), next(n){}
        //这是一个构造函数，用于初始化Node对象。
        //参数T d：节点要存储的数据。
        //参数Node* n：指向下一个节点的指针。
        //: data(d), next(n)：这是成员初始化列表，用于在构造函数中初始化成员变量data和next。

    };
    Node* topPtr;
    int count;

public:
    LinkedListStack() : topPtr(nullptr),count(0) {}//头部插入new node

    void push(T value){
        topPtr = new Node(value, topPtr);//node.val=value,node.next=topPtr
        count ++;

    }

    T pop(){
        if (topPtr == nullptr) throw "stack underflow";
        Node* temp = topPtr;
        T val = temp->data; //val=temp.data 但是C++中要声明类型
        topPtr = topPtr->next;
        delete temp;
        count --;
        return val;



    }



};