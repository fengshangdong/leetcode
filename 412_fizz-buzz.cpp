#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<string> fizzBuzz(int n) {
    vector<string> res(n);
    string str1 = "Fizz";
    string str2 = "Buzz";
    string str3 = "FizzBuzz";
    for (int i = 1; i <= n; i++) {
      if (i%15 == 0)
        res[i-1] =str3;
      else if (i%3 == 0)
        res[i-1] =str1;
      else if (i%5 == 0)
        res[i-1] =str2;
      else
        res[i-1] =to_string(i);
    }

    return res;
  }

private:
  string to_string(int n) {
    char chr[32] = {0};
    sprintf(chr, "%d", n);
    return string(chr);
  }
};

int main()
{
  Solution solv;
  int n = 15;
  vector<string> vec = solv.fizzBuzz(n);
  for (int i = 0; i < vec.size(); i++)
    cout << vec[i]<<" "<<endl;
}
