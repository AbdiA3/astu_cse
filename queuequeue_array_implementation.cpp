#include <iostream>
using namespace std;

#define SIZE 100

struct Queue {
	int elements[SIZE];
	int front = 0, back = -1;
};

Queue *queue;

// put an item into the queue
void en_queue(Queue *queue, int item) {
	queue->back++;
	queue->elements[queue->back] = item;
}

// remove the first item from the queue and return it's value
int de_queue(Queue *queue) {
	if(queue->front > queue->back){
		cout << "The queue is empty" << endl;
		exit(1);
	} else {
		int temp = queue->elements[queue->front];
		queue->front++;
		return temp;
	}
}


int main() {
	Queue *queue = new Queue;
	en_queue(queue, 10); //
	en_queue(queue, 20);
	en_queue(queue, 30);

	cout << de_queue(queue) << endl; // remove first item - 10  
	cout << de_queue(queue) << endl; // remove first item - 20 
	cout << de_queue(queue) << endl; // remove first item - 30
	cout << de_queue(queue) << endl; // remove first item - The queue is empty
}
