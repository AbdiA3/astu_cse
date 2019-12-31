#include <iostream>
using namespace std;

// stack implementation using structure and array

// set the size of our stack and named it SIZE
#define SIZE 100 

struct Stack {
	int elements[SIZE];
	int top = -1;
};

Stack *stack;

// push the item into the stack
void push(Stack *stack, int item) {
	if(stack->top > SIZE) {
		cout << "Stack Overflow" << endl;
		exit(1);
	} else {
		stack->top++;
		stack->elements[stack->top] = item;
	}

}

// pop function removes the last item and return it
int pop(Stack *stack) {
	if(stack->top == -1) {
		cout << "Stack is empty - Underflow" << endl;
		exit(1);
	} else {
		int temp = stack->elements[stack->top];
		stack->top--;
		return temp;
	}
}

int main() {
	Stack *stack = new Stack;
	push(stack, 10); // push 10 at the end of the stack
	push(stack, 20); // push 20 at the end of the stack
	cout << pop(stack) << endl; // pop the last item from the stack - 20
	cout << pop(stack) << endl; // pop the last item from the stack - 10
	cout << pop(stack) << endl; // pop the last item from the stack - Stack is empty - Underflow

}
