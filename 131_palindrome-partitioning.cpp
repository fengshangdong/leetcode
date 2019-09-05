/* 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
 * 返回 s 所有可能的分割方案。*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<vector<string> > res;
  vector<vector<string> > partition(string s) {
    vector<string> curr;
    dfs(s, curr);
    return res;
  }

  void dfs(string s, vector<string>& curr) {
    if (s.empty()) {
      res.push_back(curr);
      return;
    }

    for (int i = 1; i <= s.length(); i++) {
      string temp = s.substr(0, i);
      if (check(temp)) {
        curr.push_back(temp);
        dfs(s.substr(i, s.length()), curr);
        curr.pop_back();
      }
    }
  }

  bool check(string& str) {
    int beg = 0, end = str.length()-1;
    while (beg < end) {
      if (str[beg++] != str[end--])
        return false;
    }

    return true;
  }
};

int main() {
  string s= "aaab";
  Solution solv;
  vector<vector<string> > res = solv.partition(s);
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << " ";
    }
    cout <<endl;
  }
}
