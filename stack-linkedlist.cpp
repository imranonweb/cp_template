#include <iostream>
using namespace std;

// Define the structure for a node
struct Node {
    int data;
    Node* next;
};

// Push operation: Add an element to the top of the stack
Node* push(Node* top, int item) {
    Node* newNode = new Node();
    newNode->data = item;
    newNode->next = top;  // Point to the previous top
    return newNode;       // Return the new top
}

// Pop operation: Remove the top element from the stack
Node* pop(Node* top, int& poppedItem) {
    if (top == nullptr) {  // Underflow condition
        cout << "Underflow: Stack is empty." << endl;
        return nullptr;
    }
    Node* temp = top;
    poppedItem = top->data;
    top = top->next;  // Update top to the next node
    delete temp;      // Free the memory of the removed node
    return top;
}

// Display the stack elements
void display(Node* top) {
    if (top == nullptr) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack elements are: ";
    while (top != nullptr) {
        cout << top->data << " ";
        top = top->next;
    }
    cout << endl;
}

int main() {
    Node* top = nullptr;  // Initialize the stack as empty
    int poppedItem;

    // Test the stack implementation
    top = push(top, 5);
    top = push(top, 8);
    top = push(top, 2);

    cout << "After pushing elements:" << endl;
    display(top);

    top = pop(top, poppedItem);
    cout << "The popped item is: " << poppedItem << endl;

    top = push(top, 10);
    cout << "After pushing 10:" << endl;
    display(top);

    top = pop(top, poppedItem);
    cout << "The popped item is: " << poppedItem << endl;

    cout << "Final stack state:" << endl;
    display(top);

    return 0;
}
