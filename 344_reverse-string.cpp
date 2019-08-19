#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
  void reverseString(vector<char>& s) {
    if (s.empty()) return;
    int len = s.size();

    for(int i = 0; i < len/2; i++)
      swap(s[i],s[len-i-1]);
  }
};

int main()
{
  vector<char> s;
  s.push_back('h');
  s.push_back('e');
  s.push_back('l');
  s.push_back('l');
  s.push_back('o');
  s.push_back('-');
  s.push_back('w');
  s.push_back('o');
  s.push_back('r');
  s.push_back('l');
  s.push_back('d');
  for (int i = 0; i < s.size(); i++)
    cout << s[i];
  cout<<'\n';
  Solution solv;
  solv.reverseString(s);
  for (int i = 0; i < s.size(); i++)
    cout << s[i];
  cout<<'\n';
}
