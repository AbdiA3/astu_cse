/******************************
*     Doubly Linked List     *
*     Author - Abdi Adem     *
******************************/
#include <iostream>
using namespace std;

struct node {
	int data;
	struct node *next;
	struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;

// Checks whether the linked list empty or not
bool empty() {
	return head == NULL ? true : false;
}

// check whether the element you sent is in the linked list or not
bool has(int element) {
	struct node *p;
	p = head;
	while(p->data != element && p != NULL) {
		p = p->next;
	} 
	
	if(p == NULL) {
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
	temp->prev = NULL;
	if(empty()) {
		head = temp;
		tail = temp;
	} else {
		p = tail;
		p->next = temp;
		temp->prev = p;
		tail = temp;
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
		tail = temp;
	} else {
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
}

// insert the given value after the given element
void insert_after_element(int element, int value) {
	struct node *temp, *p, *q;
	temp = new struct node;
	temp->data = value;
	temp->next = NULL;
	temp->prev = NULL;
	if(empty() || !has(element)) {
		if(empty()) cout << "The linked list empty" << endl;
		else cout << "There is no node with the given element" << endl;
		return;
	} else {
		if(element == tail->data) {
			p = tail;
			p->next = temp;
			temp->prev = p;
			tail = temp;
		} else {
			p = head;
			while(p->data != element) { 
				p = p->next; 
			}
			temp->next = p->next; 
			p->next->prev = temp;
			p->next = temp;
			temp->prev = p;
		}
	}
}

// insert the given value before the given element
void insert_before_element(int element, int value) {
	struct node *temp, *p, *q;
	temp = new struct node;
	temp->data = value;
	temp->next = NULL;
	temp->prev = NULL;
	if(empty() || !has(element)) {
		if(empty()) cout << "The linked list empty" << endl;
		else cout << "There is no node with the given element" << endl;
		return;
	} else {
	   if(element == head->data) {
			p = head;
			p->prev = temp;
			temp->next = p;
			head = temp;
		} else {
			p = head;
			while(p->data != element) {
				p = p->next; 
			}
			temp->prev = p->prev;
			p->prev->next = temp;
			temp->next = p;
			p->prev = temp;
		}
	}
}

// print the entire linked list in the forward direction
void print_forward() { 
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

// print the entire linked list in the backward direction
void print_backward() { 
	struct node *p;
	if(empty()) {
		cout << "The linked list is empty." << endl;
		return;
	} else {
		p = tail;
		while(p != NULL) {
			cout << p->data << endl;
			p = p->prev;
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
			p = head;
			while(p->data != element) { 
				p = p->next; 
			}
			q = p->prev;
			q->prev->next = p;
			p->prev = q->prev;
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
			q = p->next;
			p->next = p->next->next;
			p->next->prev = p;
			q = NULL;
			delete q;       
		}
	} else {
		cout << "The element you provided is not in the linked list." << endl;
		return;
	}
}

// delete a given node 
void delete_element(int element) {
	struct node *p, *q, *r;
	if(has(element)) {

		if(tail->data == element) {
			p = tail->prev;
			tail = p;
			tail->next = NULL;
			p = NULL;
			delete p;
		} else if(head->data == element) {
			p = head->next;
			head = p;
			head->prev = NULL;
			p = NULL;
			delete p;
		} else {
			p = head;
			while(p->data != element) {
				p = p->next;
			}

			q = p->prev;
			r = p->next;

			q->next = r;
			r->prev = q;
			p = NULL;
			delete p;
		}

	} else {
		cout << "The element you provided is not in the linked list." << endl;
		return;
	}
}

// delete at the end
void delete_at_end() {
    struct node *p;
    if(empty()) {
        cout << "The linked list is empty." << endl;
        return;
    } else {
        p = tail;
        tail = p->prev;
        tail->next = NULL;
        delete p;
    }    
}

// delete at the start
void delete_at_start() {
    struct node *p;
    if(empty()) {
        cout << "The linked list is empty." << endl;
        return;
    } else {
        p = head;
        head = p->next;
        head->prev = NULL;
        delete p;
    }    
}

int main() {
	// This is where you will manupilate the linked list as you want
}
