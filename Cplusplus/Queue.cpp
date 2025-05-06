//
// Created by lenovo on 3/10/2025.
//
# include "iostream"
using namespace std;

template <typename T>
class ArrayQueue{
private:
    T* data;
    int capacity;
    int front;
    int rear;
public:
    ArrayQueue(int cap) : capacity(cap),front(0),rear(0){
        data = new T[capacity];
    }

    bool isempty() const {
        return front == rear;
    }

    bool isfull() const{
        return (rear + 1)% capacity == front; //要牺牲一个存储单元
    }

    bool enter(T val){
        if (isfull()){
            throw runtime_error("队列满了");

        }
        data[rear] = val;
        rear = (rear + 1) % capacity;

    }

    bool out(){
        if (isempty()){
            throw runtime_error("队列空的");

        }
        T val = data[front];
        front = (front + 1)% capacity;
        return val;

    }

    ~ArrayQueue(){
        delete []data;
    }
};

