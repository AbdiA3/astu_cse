#include <iostream>
using namespace std;
/* 
	NB: - the top in the function of pop and push is the address
		  of the top because the value of the top has to change
*/


void push(int stack[], int &top, int n, int item) {
	if(top+1 < n) {
		top++;
		stack[top] = item;
	} else {
		// if the top > n then top is outside our stack
		cout << "Stack Overflow" << endl;
	}
}

int pop(int stack[], int &top, int n) {
	if(top == -1) {
		// if the top is back to -1 then the stack is empty
		cout << "Stack Underflow" << endl;
		return -1;
	} else {
		int temp = stack[top];
		top--;
		return temp;
	}
}

int main() {
	int n; // size of the stack
	cout << "Enter the size of your stack: ";
	cin >> n;
	int stack[n]; // declare an array of type integer with size 'n' as our stack
	int top = -1; // initialize the top of your stack as -1
	push(stack, top, n, 10); // push item 10
	push(stack, top, n, 20); // push item 20
	cout << pop(stack, top, n) << endl; // remove 20 then display
	cout << pop(stack, top, n) << endl; // remove 10 then display
}

