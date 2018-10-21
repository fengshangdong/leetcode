#include<queue>
#include<cstdio>

using namespace std;

class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {
	}

	/** Push element x onto stack. */
	void push(int x) {
		q1.push(x);
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		while (q1.size() != 1) {
			int data = q1.front();
			q1.pop();
			q2.push(data);
		}    

		while (!q2.empty()) {
			int data = q2.front();
			q2.pop();
			q1.push(data);
		}

		int res = q1.front();
		q1.pop();
		return res;
	}

	/** Get the top element. */
	int top() {
		return q1.back();
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q1.empty();
	}
private:
	queue<int> q1;
	queue<int> q2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */

int main()
{
	MyStack stack;
	for (int i = 1; i <= 5; i++) {
		stack.push(i);
		printf("%d ", stack.top());
	}
	printf("\n");

	while (!stack.empty()) {
		printf("%d ", stack.top());
		stack.pop();
	}
	printf("\n");
}
