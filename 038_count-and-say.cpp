#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
  string countAndSay(int n) {
    string str = "1", res = "1";
    int count;
    for (int i = 2; i <= n; i++) {
      res = "";
      count = 1;
      for (int j = 1; j < str.size(); j++) {
        if (str[j] == str[j-1]) {
          count ++;
        }
        else {
          res += to_string(count);
          res += str[j-1];
          count = 1;
        }
      }

      res += to_string(count);
      res += str[str.length()-1];
      str = res;
    }
    return res;
  }
private:
  string to_string(int n) {
    char str[64] = {0};
    sprintf(str,"%d",n);
    return string(str);
  }
};

int main()
{
  int n1 = 2;
  int n2 = 3;
  int n3 = 4;
  int n4 = 5;
  int n5 = 6;
  Solution solv;
  string str1 = solv.countAndSay(n1);
  string str2 = solv.countAndSay(n2);
  string str3 = solv.countAndSay(n3);
  string str4 = solv.countAndSay(n4);
  string str5 = solv.countAndSay(n5);
  cout << "str1=" << str1 << " str2=" << str2 << " str3=" <<str3 << endl;
  cout << "str4=" << str4 << " str5=" << str5 << endl;
}

