//
//  main.cpp
//  Test
//
//  Created by Ashwin V Prabhu on 8/25/17.
//  Copyright © 2017 Ashwin V Prabhu. All rights reserved.
//

//
// Question: Implement queue using a stack
//

#include <iostream>
#include <vector>
using namespace std;

class Queue {
private:
    vector<int> first, second;
    
public:
    Queue() {
        first = {};
        second = {};
    }
    
    void Push(int item) {
        first.push_back(item);
        cout << item << " has been pushed onto the queue" << endl;
    }
    
    void Pop() {
        if (second.empty()) {
            while (!first.empty()) {
                int item = first.back();
                second.push_back(item);
                first.pop_back();
            }
        }
        
        int item = second.back();
        second.pop_back();
        cout << item << " has been popped from the queue" << endl;
    }
};

int main() {
    
    Queue *queue = new Queue();
    
    queue->Push(1);
    queue->Push(2);
    queue->Push(3);
    queue->Pop();
    queue->Push(4);
    queue->Pop();
    queue->Push(5);
    queue->Pop();
    queue->Pop();
    queue->Pop();
    
    return 0;
}
