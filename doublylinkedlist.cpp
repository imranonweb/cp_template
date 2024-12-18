#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Function to print the elements of the doubly linked list 
void print(Node* ptr) {
    while (ptr != nullptr) {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
    cout << endl;
}

// Insert at the beginning of the list
Node* insertAtFirst(Node* head, int data) {
    Node* ptr = new Node();
    ptr->data = data;
    ptr->next = head;
    ptr->prev = nullptr;
    if (head != nullptr) {
        head->prev = ptr;
    }
    return ptr;
}

// Insert at a specific index in the list
Node* insertAtAny(Node* head, int data, int index) {
    Node* ptr = new Node();
    ptr->data = data;
    if (index == 0) {
        return insertAtFirst(head, data);
    }
    Node* p = head;
    int i = 0;
    while (i != index - 1 && p != nullptr) {
        p = p->next;
        i++;
    }
    if (p == nullptr) {
        cout << "Index out of bounds" << endl;
        delete ptr;
        return head;
    }
    ptr->next = p->next;
    ptr->prev = p;
    if (p->next != nullptr) {
        p->next->prev = ptr;
    }
    p->next = ptr;
    return head;
}

// Insert at the end of the list
Node* insertAtEnd(Node* head, int data) {
    Node* ptr = new Node();
    ptr->data = data;
    ptr->next = nullptr;
    if (head == nullptr) {
        ptr->prev = nullptr;
        return ptr;
    }
    Node* p = head;
    while (p->next != nullptr) {
        p = p->next;
    }
    p->next = ptr;
    ptr->prev = p;
    return head;
}

// Delete the first element
Node* deleteAtFirst(Node* head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return head;
    }
    Node* temp = head;
    head = head->next;
    if (head != nullptr) {
        head->prev = nullptr;
    }
    delete temp;
    return head;
}

// Delete an element at a specific index
Node* deleteAtAny(Node* head, int index) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return head;
    }
    if (index == 0) {
        return deleteAtFirst(head);
    }
    Node* p = head;
    int i = 0;
    while (i != index && p != nullptr) {
        p = p->next;
        i++;
    }
    if (p == nullptr) {
        cout << "Index out of bounds!" << endl;
        return head;
    }
    if (p->next != nullptr) {
        p->next->prev = p->prev;
    }
    if (p->prev != nullptr) {
        p->prev->next = p->next;
    }
    delete p;
    return head;
}

// Delete the last element
Node* deleteAtEnd(Node* head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return head;
    }
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    Node* p = head;
    while (p->next != nullptr) {
        p = p->next;
    }
    p->prev->next = nullptr;
    delete p;
    return head;
}

// Search for a value in the doubly linked list
int search(Node* head, int value) {
    Node* temp = head;
    int index = 0;
    while (temp != nullptr) {
        if (temp->data == value) {
            return index; // Value found at this index
        }
        temp = temp->next;
        index++;
    }
    return -1; // Value not found
}

int main() {
    Node* head = nullptr;

    // Insert elements
    head = insertAtEnd(head, 6);
    head = insertAtEnd(head, 7);
    head = insertAtEnd(head, 9);
    head = insertAtEnd(head, 8);

    cout << "After traversing:" << endl;
    print(head);

    cout << "After addition at the beginning:" << endl;
    head = insertAtFirst(head, 0);
    print(head);

    cout << "After adding at index 2:" << endl;
    head = insertAtAny(head, 5, 2);
    print(head);

    cout << "Adding at the end:" << endl;
    head = insertAtEnd(head, 10);
    print(head);

    // Search for an element
    int searchValue = 5;
    int searchIndex = search(head, searchValue);
    if (searchIndex != -1) {
        cout << "Value " << searchValue << " found at index " << searchIndex << "." << endl;
    } else {
        cout << "Value " << searchValue << " not found in the list." << endl;
    }

    // Deleting elements
    cout << "Deleting the first element:" << endl;
    head = deleteAtFirst(head);
    print(head);

    cout << "Deleting at index 2:" << endl;
    head = deleteAtAny(head, 2);
    print(head);

    cout << "Deleting the last element:" << endl;
    head = deleteAtEnd(head);
    print(head);

    return 0;
}
