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

  void dfs(string s, vector<string>& curr){
    if(s.empty()){
      res.push_back(curr);
    }
    else{
      for(int i = 1; i <= s.size(); ++i){
        string temp = s.substr(0,i);
        if(check(temp)){
          curr.push_back(temp);
          dfs(s.substr(i,s.size()), curr);
          curr.pop_back();
        }
      }
    }
  }

  bool check(string& s){
    int head = 0;
    int tail = s.size()-1;
    while(head < tail){
      if(s[head++] != s[tail--]) return false;
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
