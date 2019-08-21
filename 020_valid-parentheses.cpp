#include <string>
#include <stack>
#include <iostream>
#include <stdio.h>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    if (s.empty()) return true;
    
    stack<char> stk;
    for(int i = 0; i < s.length(); i++) {
      if (stk.empty() || is_left(s.at(i))) {
        stk.push(s.at(i));
      }
      else {
        if (!is_eq(stk.top(), s.at(i))) return false;
        stk.pop();
      }
    }

    if (stk.empty())
      return true;
    else
      return false;
  }

private:
  bool is_left(char c) {
    return (c == '(' || c == '[' || c == '{');
  }

  bool is_eq(char c1, char c2) {
    return ((c1 == '(' && c2 == ')') || (c1 == '[' && c2 ==']') || (c1 == '{' && c2 == '}'));
  }
};

int main() {
  string s1 = "{";
  string s2 = "{()[}]";
  Solution solv;
  int ret1 = solv.isValid(s1);
  int ret2 = solv.isValid(s2);
  printf("%d\n",ret1);
  printf("%d\n",ret2);
}
