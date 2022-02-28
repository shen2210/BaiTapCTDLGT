#include <iostream>
#define MAX 100
using namespace std;

struct Stack {
	int a[MAX];
	int top;
};

void init(Stack& s) {
	s.top = -1;
}

void push(Stack& s, int x) {
	s.top++;
	s.a[s.top] = x;
}

int pop(Stack& s) {
	int x = s.a[s.top];
	s.top--;
	return x;
}

bool isEmpty(Stack s) {
	return s.top < 0;
}

bool isFull(Stack s) {
	return s.top == MAX;
}

void input(long& n, int& x) {
	cout << "Enter value N : "; cin >> n;
	do {
		cout << "Enter value X (2 <= X <= 16) : "; cin >> x;
	} while (x < 2 || x > 16);
}

void convertDecToX(long n, int x) {
	Stack st;
	init(st);
	long number = n;
	while (number != 0) {
		int remainder = number % x;
		push(st, remainder);
		number /= x;
	}
	while (!isEmpty(st)) { 
		int temp = pop(st);
		if (temp == 10) {
			cout << "A";
		}
		else if (temp == 11){
			cout << "B";
		}
		else if (temp == 12) {
			cout << "C";
		}
		else if (temp == 13) {
			cout << "D";
		}
		else if (temp == 14) {
			cout << "E";
		}
		else if (temp == 15) {
			cout << "F";
		}
		else cout << temp;
	}
}

int main() {
	long n;
	int x;
	input(n, x);
	
	cout << "(" << n << ")10 is (";
	convertDecToX(n, x);
	cout << ")" << x << endl;

	return 0;
}