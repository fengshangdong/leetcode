#include <map>
#include <vector>
#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;

#if 0
/* 不支持c++11 */
class Solution {
public:
  map<char, string> table{
    {'0', " "}, {'1',"*"}, {'2', "abc"},
      {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
      {'6',"mno"}, {'7',"pqrs"},{'8',"tuv"},
      {'9',"wxyz"}};  
  vector<string> res;
  vector<string> letterCombinations(string digits) {
    if(digits == "") return res;
    dfs("", digits, 0);
    return res;
  }

  void dfs(string str, string &digits, int k){
    if(str.size() == digits.size()){
      res.push_back(str);
      return;
    }

    string tmp = table[digits[k]];
    for(int i = 0; i < tmp.length(); i++) {
      str.push_back(tmp[i]);
      dfs(str, digits, k+1);
      str.pop_back();
    }
    return ;
  }
};
#endif

int main() {
  return 0;
}
