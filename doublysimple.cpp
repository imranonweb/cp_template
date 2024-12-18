#include<bits/stdc++.h>
using namespace std;
#define nl '\n'

struct node {
    int data;
    node* next;
    node* prev;
};

void print(node* ptr) {
    while (ptr != nullptr) {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
    cout << endl;
}

node* insertatfirst(node* head, int data) {
    node* newnode = new node();
    newnode->data = data;
    newnode->next = head;
    newnode->prev = nullptr;
    if (head != nullptr) {
        head->prev = newnode;
    }
    return newnode;
}

node* insertatindex(node* head, int data, int index) {
    node* newnode = new node();
    newnode->data = data;
    node* temp = head;
    int i = 1;
    while (i != index - 1) {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
    if (newnode->next != nullptr) {
        newnode->next->prev = newnode;
    }
    return head;
}

node* insertatend(node* head, int data) {
    node* newnode = new node();
    newnode->data = data;
    newnode->next = nullptr;
    
    // Case when the list is empty
    if (head == nullptr) {
        return newnode;
    }
    
    node* p = head;
    while (p->next != nullptr) {
        p = p->next;
    }

    p->next = newnode;
    newnode->prev = p;

    return head;
}

    node* deleteatfirst(node* head){
        node* temp = head;
        head = head->next;
        if(head != nullptr){
            head->prev = nullptr;
        }
        delete temp;
        return head;
    }

    node* deleteatany(node* head,int index){
        node* temp = head;
        int i = 1;
        while(i != index){
            temp = temp->next;
            i++;
        }
        if(temp->prev != nullptr)
        temp->prev->next = temp->next;
        if(temp->next != nullptr)
        temp->next->prev = temp->prev;
        delete temp;
        return head;
    }

    node* deleteatend(node* head){
        node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->prev->next = nullptr;
        temp->prev = nullptr;
        delete temp;
        return head;
    }

int main() {
    node* head = nullptr;

    head = insertatend(head, 9);
    head = insertatend(head, 8);
    head = insertatend(head, 7);
    head = insertatend(head, 0);

    cout << "After traversing:" << endl;
    print(head);

    head = insertatindex(head, 10, 3);
    cout << "Inserting at index 3" << nl;
    print(head);

    head = insertatfirst(head, 100);
    cout << "After inserting at the first position:" << nl;
    print(head);

    cout << "deleting at first" << nl;
    head = deleteatfirst(head);
    print(head);
    cout << "deleting at index" << nl;
    head = deleteatany(head,3);
    print(head);
    cout << "deleting at last" << nl;
    head = deleteatend(head);
    print(head);

    return 0;
}
