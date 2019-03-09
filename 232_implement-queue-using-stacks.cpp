#include<stack>
#include<cstdio>

using namespace std;

class MyQueue {
public:
  /** Initialize your data structure here. */
  MyQueue() {
  }

  /** Push element x to the back of queue. */
  void push(int x) {
    s1.push(x);
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    while (s1.size() != 1) {
      int data = s1.top();
      s1.pop();
      s2.push(data);
    }
    int res = s1.top();
    s1.pop();

    while (!s2.empty()) {
      int data = s2.top();
      s2.pop();
      s1.push(data);
    }

    return res;
  }

  /** Get the front element. */
  int peek() {
    while (s1.size() != 1) {
      int data = s1.top();
      s1.pop();
      s2.push(data);
    }
    int res = s1.top();

    while (!s2.empty()) {
      int data = s2.top();
      s2.pop();
      s1.push(data);
    }

    return res;
  }

  /** Returns whether the queue is empty. */
  bool empty() {
    return s1.empty();
  }
private:
  stack<int> s1;
  stack<int> s2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */

int main() {
  MyQueue q;
  for (int i = 1; i < 5; i++) {
    printf("%d ", i);
    q.push(i);
  }
  printf("\n");

  while (!q.empty()) {
    printf("%d ", q.peek());
    q.pop();
  }
  printf("\n");
}
