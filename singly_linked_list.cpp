/******************************
*     Singly Linked List     *
*     Author - Abdi Adem     *
******************************/
#include <iostream>
using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Checks whether the linked list empty or not
bool empty() {
    return head == NULL ? true : false;
}

// check whether the element you sent is in the linked list or not
bool has(int element) {
    struct node *p;
    p = head;
    while(p->data != element && p->next != NULL) {
        p = p->next;
    } 
    
    if(p->next == NULL) {
        return false;
    } else {
        return true;
    }
}

// append the given element at the end of the linked list
void append(int element) {
    struct node *temp, *p;
    temp = new struct node;
    temp->data = element;
    temp->next = NULL;
    if(empty()) {
        head = temp;
    } else {
        p = head;
        while(p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
        
    }
}

// add the given element at the beginning of the linked list
void prepend(int element) {
    struct node *temp, *p;
    temp = new struct node;
    temp->data = element;
    temp->next = NULL;
    if(empty()) {
        head = temp;
    } else {
        p = head;
        head = temp;
        head->next = p;
    }
}

// insert the given value after the given element
void insert_after_element(int element, int value) {
    struct node *temp, *p, *q;
    temp = new struct node;
    temp->data = value;
    temp->next = NULL;
    if(empty() || !has(element)) {
        if(empty()) cout << "The linked list empty" << endl;
        else cout << "There is no node with the given element" << endl;
        return;
    } else {
        p = head;
        while(p->data != element) {
            p = p->next;
        }
        q = p->next;
        p->next = temp;
        temp->next = q;
    }
}

// insert the given value before the given element
void insert_before_element(int element, int value) {
    struct node *temp, *p, *q;
    temp = new struct node;
    temp->data = value;
    temp->next = NULL;
    if(empty() || !has(element)) {
        if(empty()) cout << "The linked list empty" << endl;
        else cout << "There is no node with the given element" << endl;
        return;
    } else {
        if(element == head->data){
            prepend(value);
        } else {
            p = head;
            while(p->next->data != element) {
                p = p->next;
            }
            q = p->next;
            p->next = temp;
            temp->next = q;  
        }
        
    }
}

// print the entire linked list
void print() { 
    struct node *p;
    if(empty()) {
        cout << "The linked list is empty." << endl;
        return;
    } else {
        p = head;
        while(p != NULL) {
            cout << p->data << endl;
            p = p->next;
        }
    }
}

// delete the given value before the given element
void delete_before_element(int element) {
    struct node *p, *q;
    
    if(has(element)) {
        p = head;
        while(p->next->next->data != element) {
            p = p->next;
        }
        
        if(element == head->data) {
            cout << "There is no element before " << element << endl;
            return;
        } else {
            q = p->next;
            p->next = q->next;
            q = NULL;
            delete q;        
        }
    } else {
        cout << "The element you provided is not in the linked list." << endl;
        return;
    }
}

// delete the given value after the given element
void delete_after_element(int element) {
    struct node *p, *q, *r;
    
    if(has(element)) {
        p = head;
        while(p->data != element && p->next != NULL) {
            p = p->next;
        }
        if(p->next == NULL) {
            cout << "There is no element after " << element << endl;
            return;
        } else {
            q = p->next->next;
            r = p->next;
            p->next = q;
            r = NULL;
            delete r;        
        }
    } else {
        cout << "The element you provided is not in the linked list." << endl;
        return;
    }
}

int main() {
    // This is where you will manupilate the linked list as you want
}
