#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<string> res;
  void dfs(string str, int left, int right, int n) {
    if (str.length() == 2*n) {
      res.push_back(str);
      return;
    }
    if (left < n) {
      dfs(str+"(", left+1, right, n);
    }
    if (right < left) {
      dfs(str+")", left, right+1, n);
    }
  }

  vector<string> generateParenthesis(int n) {
    if (n < 1) return res;
    dfs("", 0, 0, n);
    return res;
  }
};

int main() {
  int n = 3;
  Solution solv;
  vector<string> vec = solv.generateParenthesis(n);
  for (int i = 0; i < vec.size(); i++)
    cout << vec[i] << endl;
}
