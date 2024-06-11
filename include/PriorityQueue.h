#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <vector>
#include <string>

#include "student.h"
#include "input.h"
using namespace std;



// Node class
class Node {
public:
    student data;
    int priority;
    Node* next;

    Node(Student d, int p) : data(d), priority(p), next(nullptr) {}
};

// PriorityQueue class
class PriorityQueue {
    vector<Node*> heap;
    Node* head;

    void heapifyUp(int index) {
        if (index && heap[parent(index)]->priority > heap[index]->priority) {
            swap(heap[index], heap[parent(index)]);
            heapifyUp(parent(index));
        }
    }

    void heapifyDown(int index) {
        int left = leftChild(index);
        int right = rightChild(index);
        int smallest = index;

        if (left < heap.size() && heap[left]->priority < heap[smallest]->priority)
            smallest = left;

        if (right < heap.size() && heap[right]->priority < heap[smallest]->priority)
            smallest = right;

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

public:
    PriorityQueue() : head(nullptr) {}

    void push(Student data, int priority) {
        Node* newNode = new Node(data, priority);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        heap.push_back(newNode);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* nodeToRemove = heap[0];

        if (head == nodeToRemove) {
            head = head->next;
        } else {
            Node* temp = head;
            while (temp->next != nodeToRemove) {
                temp = temp->next;
            }
            temp->next = nodeToRemove->next;
        }

        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heapifyDown(0);
        }

        delete nodeToRemove;
    }

    student top() {
        if (heap.empty()) {
            cout << "Queue is empty" << endl;
            return student("", -1);  // Return an empty student in case of error
        }
        return heap[0]->data;
    }

    bool empty() {
        return heap.empty();
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "Name: " << temp->data.name << ", Grade: " << temp->data.grade << ", Priority: " << temp->priority << endl;
            temp = temp->next;
        }
    }
};

#endif // PRIORITYQUEUE_H
