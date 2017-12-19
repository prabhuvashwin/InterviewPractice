//
//  main.cpp
//  LinkedList
//
//  Created by Ashwin V Prabhu on 12/18/17.
//  Copyright © 2017 Ashwin V Prabhu. All rights reserved.
//

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

class LinkedList {
    Node *head;
    Node *tail;
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    
    Node * GetHead() {
        return head;
    }
    
    void InsertNodeAtEnd(int value) {
        Node *temp = new Node;
        temp->data = value;
        temp->next = nullptr;
        
        if (head == nullptr) {
            head = temp;
            tail = temp;
            temp = nullptr;
        } else {
            tail->next = temp;
            tail = temp;
        }
        
        cout << "Node " << value << " inserted at tail" << endl;
    }
    
    void InsertNodeAtStart(int value) {
        Node *temp = new Node;
        temp->data = value;
        temp->next = nullptr;
        
        if (head == nullptr) {
            head = temp;
            tail = temp;
            temp = nullptr;
        } else {
            temp->next = head;
            head = temp;
        }
        
        cout << "Node " << value << " inserted at head" << endl;
    }
    
    void InsertNodeAtPosition(int value, int position) {
        Node *prev = new Node;
        Node *curr = new Node;
        Node *temp = new Node;
        temp->data = value;
        temp->next = nullptr;
        int i = 0;
        curr = head;
        while (i < position) {
            prev = curr;
            curr = curr -> next;
        }
        prev->next = temp;
        temp->next = curr;
        
        cout << "Node " << value << " inserted at position " << position << endl;
    }
    
    void DeleteAtStart() {
        Node *temp = new Node;
        
        if (head == nullptr) {
            cout << "List is empty" << endl;
        } else {
            temp = head;
            head = head->next;
            cout << "Node at head is deleted." << endl;
        }
    }
    
    void DeleteAtEnd() {
        Node *prev = new Node;
        Node *curr = new Node;
        curr = head;
        while (curr->next != nullptr) {
            prev = curr;
            curr = curr->next;
        }
        tail = prev;
        prev->next = nullptr;
        cout << "Node at tail is deleted." << endl;
        delete curr;
    }
    
    void DeleteAtPosition(int position) {
        Node *prev = new Node;
        Node *curr = new Node;
        curr = head;
        int i = 0;
        while (i < position) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next = nullptr;
        cout << "Node at position " << position << " is deleted." << endl;
        delete curr;
    }
    
    void DisplayInReverse(Node *node) {
        if (node == nullptr) {
            cout << "List is empty" << endl;
        } else if (node->next != nullptr) {
            DisplayInReverse(node->next);
            cout << node->data << " ";
        } else {
            cout << node->data << " ";
        }
    }
    
    void Display() {
        Node *iter = head;
        
        while (iter != nullptr) {
            cout << iter->data << " ";
            iter = iter->next;
        };
        
        cout << endl;
    }
    
    Node * ReverseLinkedList(Node *node) {
        if (node == nullptr || node->next == nullptr)
            return node;
        
        Node *prev = nullptr;
        Node *curr = node;
        Node *next = nullptr;
        
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        head = prev;
        
        return node;
    }
    
    int GetNodeValueAtN(Node *node, int posFromTail) {
        int i = 0;
        Node *curr = node;
        Node *res = node;
        while (curr != nullptr) {
            curr = curr->next;
            if (i++ > posFromTail) {
                res = res->next;
            }
        }
        return res->data;
    }
    
    bool HasCycle() {
        Node *curr = head;
        Node *next = head;
        
        while (next != nullptr && next->next != nullptr) {
            curr = curr->next;
            next = next->next->next;
            if (curr == next)
                return 1;
        }
        return 0;
    }
    
    int GetMiddleElement() {
        Node *slow = head;
        Node *fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow->data;
    }
    
    void DeleteMiddleElement() {
        Node *prev = head;
        Node *slow = head;
        Node *fast = head;
        int count = 0;
        
        while (fast != nullptr && fast->next != nullptr) {
            if (count > 0)
                prev = prev->next;
            slow = slow->next;
            fast = fast->next->next;
            count++;
        }
        
        prev->next = slow->next;
        
        cout << "Middle element " << slow->data << " deleted." << endl;
    }
    
    void RemoveDuplicates() {
        Node *curr = head;
        Node *next = head->next;
        
        while (next != nullptr) {
            if (curr->data == next->data) {
                curr->next = next->next;
                next = next->next;
            } else {
                curr = next;
                next = next->next;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    
    LinkedList *ll = new LinkedList();
    ll->InsertNodeAtEnd(2);
    ll->InsertNodeAtEnd(2);
    ll->InsertNodeAtEnd(2);
    ll->InsertNodeAtEnd(2);
    ll->InsertNodeAtEnd(2);
    ll->InsertNodeAtEnd(2);
    ll->InsertNodeAtEnd(2);
    ll->InsertNodeAtEnd(10);
    ll->Display();
    
    ll->RemoveDuplicates();
    ll->Display();
    
    return 0;
}
