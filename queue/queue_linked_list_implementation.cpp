#include <iostream>
using namespace std;
/* 
this is the simplest form of queue implementation
it can be made so complicated but here, if you understand the fundamentals
you can write more advanced forms 
*/

struct node {
	int data;
	node *next;
};

node *front = NULL;
node *back = NULL;

// put item into the queue
void en_queue(int item) {
	node *temp = new node;
	temp->data = item;
	temp->next = NULL;

	if(front == NULL) {
		front = temp;
		back = temp;
	} else {
		back->next = temp;
		back = temp;
	}
}

// remove the first item from the queue and return it's data
int de_queue() {
	if(front == NULL){
		cout << "The queue is empty" << endl;
		exit(1);
	} else {
		int temp = front->data;
		node *p = front;
		front = front->next;
		if(front == NULL) {
			back = NULL;
		}
		return temp;
	}
}

int main() {
	en_queue(10);
	en_queue(20);

	cout << de_queue() << endl;
	cout << de_queue() << endl;
	cout << de_queue() << endl;
}