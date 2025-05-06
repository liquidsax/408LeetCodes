//
// Created by lenovo on 3/4/2025.
//
#include "iostream"
using namespace std;

class node{
public:
    int val;
    node *next;
    node(int data){
        val=data;
        next= nullptr;
    }
};

class MyLinkedList{
public:
    node* head;
    MyLinkedList(){
        head = nullptr;
    }
    int length(){
        int count = 0;
        node* temp=head;
        while (temp!= nullptr){
            count++;
            temp=temp->next;
        }
    return count;
    }

    int get(int k) {
        int len = length();
        if (head == nullptr){
            return -1;

        } else if (len < k){return -1;}
        else{
            int count = 0;
            node* temp = head;
            while (count < k){
                temp=temp->next;
                count++;
            }
            if (temp == nullptr){
                return -1;
            }
            return temp->val;
        }

    }

    void addAtHead(int value){
        node *newNode = new node(value);
        newNode->next=head;
        head=newNode;

    }

    void addAtTail(int value){
        node *newNode =new node(value);
        if (head== nullptr){
            head= newNode;

        } else{

            node *temp = head;
            while (temp->next != nullptr){
                temp = temp->next;
            }
            temp->next=newNode;

        }

    }

    void addAtIndex(int k,int value){
        if (k==0){
            addAtHead(value);
        } else{
            int count = 0;
            node *newNode = new node(value);
            node *temp = head;
            while(temp != nullptr && count<k-1){
                temp = temp->next;
                ++count;
            }
            node *right=temp->next;
            temp->next=newNode;
            newNode->next=right;

        }
    }

    void deleteAtIndex(int k){
        if (head== nullptr) return;
        else if (k==0){
            node *del =head;
            head=head->next;
            delete del;
        } else{
            node *temp=head;
            int count = 0;
            while(count<k-1){
                temp=temp->next;
                ++count;

            }
            if (temp == nullptr || temp->next == nullptr) return;
            node *del=temp->next;
            temp->next=temp->next->next;
            delete del;

        }

    }





};