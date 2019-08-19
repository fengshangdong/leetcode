#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
  int firstUniqChar(string s) {
    if (s.empty()) return -1;

    int arr[27] = {0};
    for (int i = 0; i < s.length(); i++)
      arr[s.at(i)-97]++;

    for (int i = 0; i < s.length(); i++)
      if (arr[s.at(i)-97]==1)
        return i;

    return -1;
  }
};

int main(){
  string s = "leetcodel";
  Solution solv;
  int ret = solv.firstUniqChar(s);
  cout<<ret<<endl;

}
