#include <iostream>
#include "functions.h"
using namespace std;

//node class
Node::Node(int data){
    this->data=data;
    this-> next= nullptr;
}


void Node::setNext(Node* val) {
    next = val;
}

Node* Node::getNext() {
    return next;
}

void Node::setData(int data) {
    this->data = data;
}

int Node::getData() {
    return data;
}

Node::~Node() {}

//stack class========================================================

Stack::Stack() {
    top = nullptr;
    count = 0;
}

Stack::~Stack() {
    clear();
}

bool Stack::isEmpty() {
    return count==0;
}

void Stack::push(int data) {
    Node* newNode = new Node(data);
    newNode->setNext(top);
    top = newNode;
    count++;
}

void Stack::pop() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return ;
    }
    Node* temp = top;
    top = top->getNext();
    delete temp;
    count--;
}

int Stack::peek() {
    if (isEmpty()) {
        cout << "Stack is empty." << endl;
        return -1;
    }
    return top->getData();
}

int Stack::size() {
    return count;
}

void Stack::clear() {
    while (!isEmpty()) {
        pop();
    }
}

void Stack::printStack() {
    Node* current = top;
    while (current != nullptr) {
        cout << current->getData() << " ";
        current = current->getNext();
    }
    cout << endl;
}

//queue class========================================


Queue::Queue() {
    top = nullptr;
    end = nullptr;
    count = 0;
}

Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

bool Queue::isEmpty() {
    return top == nullptr;
}

void Queue::enqueue(int data) {
    Node* newNode = new Node(data);
    if (isEmpty()) {
        top = newNode;
        end = newNode;
    } else {
        end->setNext(newNode);
        end = newNode;
    }
    count++;
}

void Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    if (top == nullptr) {
        end = nullptr;
    }
    Node* temp = top;
    top = top->getNext();
    delete temp;
    count--;

}

int Queue::size() {
    return count;
}

void Queue::printQueue() {
    Node* current = top;
    while (current != nullptr) {
        cout << current->getData() << " ";
        current = current->getNext();
    }
    cout << endl;
}

