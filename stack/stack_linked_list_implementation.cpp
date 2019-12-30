#include <iostream>
using namespace std;

struct node {
	int data;
	node *next;
};

node *head = NULL;
node *top = head; // set the top on the head of the stack

// check whether the stack is empty or not
bool empty() {
	return head == NULL;
}

void push(int item) {
	node *temp;
	temp = new node;
	temp->data = item;
	temp->next = NULL;
	if(!temp) {
		// if there is not memory allocated in the RAM then it is stack overflow
		cout << "Stack Overflow" << endl; 
		exit(1);
	} else {
		if(empty()) {
			head = temp;	
			top = temp;
		} else {
			top->next = temp;
			top = temp;
		}
	}
}

int pop() {
	node *p, *q;
	if(empty()) {
		cout << "Stack is empty - Undeflow" << endl;
		exit(1);
	} else {
		int temp = top->data;
		p = head;
		if(head == top) {
			head = NULL;
			top = NULL;
			return temp;
		} else {
			while(p->next != top) {
				p = p->next;
			}
			q = top;
			top = p;
			delete q;
			return temp;
		}
	}
	
}

int main() {
	push(10);
	push(20);
	push(30);
	
	cout << pop() << endl;
	cout << pop() << endl;
	cout << pop() << endl;
	cout << pop() << endl;
}
