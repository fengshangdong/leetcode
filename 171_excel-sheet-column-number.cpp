#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

class Solution {
public:
  int titleToNumber(string s) {
    int size = s.size();
    int sum = 0;
    for (int i = 0; i < size; i++){
      sum = sum*26;
      sum = sum + (s[i]-'A'+1);
    }
    return sum;
  }
};

int main(){
  string s1("A");
  string s2("AA");
  string s3("AB");
  string s4("ZY");

  Solution solv;
  int ret1 = solv.titleToNumber(s1);
  int ret2 = solv.titleToNumber(s2);
  int ret3 = solv.titleToNumber(s3);
  int ret4 = solv.titleToNumber(s4);

  printf("ret=%d,%d,%d,%d\n", ret1,ret2,ret3,ret4);
}
