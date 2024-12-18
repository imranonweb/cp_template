#include<bits/stdc++.h>
using namespace std;
#define nl '\n'
#define SIZE 10

int myqueue[SIZE];
int front = -1, rear = -1;

void enqueue(int item) {
    if (rear == SIZE - 1) { // Check if the queue is full
        cout << "Queue is full" << nl;
        return;
    }
    if (front == -1) { // Set front to 0 for the first element
        front = 0;
    }
    rear++;
    myqueue[rear] = item;
    cout << "Enqueued: " << item << nl;
}

int dequeue() {
    if (front == -1 || front > rear) { // Check if the queue is empty
        cout << "Queue is empty" << nl;
        return -1; // Return -1 to indicate an empty queue
    }
    int item = myqueue[front];
    front++;
    return item;
}
void display(){
    cout << "elements in the queue : " << nl;
    for(int i = front; i <= rear; i++){
        cout << myqueue[i] << nl;
    }
    cout << nl;
}

int main() {
    enqueue(5);
    enqueue(8);
    enqueue(7);
    display();
    cout << "Dequeued: " << dequeue() << nl; // Call dequeue with ()
    cout << "Dequeued: " << dequeue() << nl; // Dequeue again to test
    display();
    enqueue(10); // Add another element
    cout << "Dequeued: " << dequeue() << nl;
    display();
    return 0;
}
