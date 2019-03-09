#include<climits>
#include<vector>
#include<cstdio>

using namespace std;

class MinStack {
public:
  /** initialize your data structure here. */
  MinStack() {
  }

  void push(int x) {
    v1.push_back(x);

    if (v2.empty()) {
      v2.push_back(x);
    }
    else 
    {
      if (x > v2.back()) {
        x = v2.back();
      }
      v2.push_back(x);
    }
  }

  void pop() {
    if (v1.empty()) {
      return;
    }

    v1.pop_back();
    v2.pop_back();
  }

  int top() {
    return v1.back();
  }

  int getMin() {
    return v2.back();
  }

private:
  vector<int> v1;
  vector<int> v2;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main() {
  MinStack s;
  s.push(-2);
  printf("%d ", s.top());
  s.push(0);
  printf("%d ", s.top());
  s.push(-3);
  printf("%d\n", s.top());

  printf("%d\n", s.getMin());
  s.pop();
  printf("%d\n", s.getMin());
}
