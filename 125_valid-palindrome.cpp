#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    if (s.empty()) return true;
    string t;
    transform(s.begin(),s.end(),s.begin(),::tolower);
    for (int i = 0; i < s.length(); i++)
      if (isCondition(s.at(i)))
        t.push_back(s.at(i));

    for (int i = 0, j = t.length()-1; i < j; i++, j--)
      if (t.at(i)!=t.at(j))
        return false;

    return true;
  }

private:
  bool isCondition(char c) {
    return (c>=48 && c<=57) || (c>=97 && c<=122) || (c>=65 && c<=90);
  }
};

int main() {
  string s = "Hello World";
  string s1 = "Hello Worlddlrowolleh";
  cout << s << endl;
  cout << s1 << endl;
  Solution solv;
  int ret = solv.isPalindrome(s);
  int ret1 = solv.isPalindrome(s1);
  cout << ret << endl;
  cout << ret1 << endl;
}
