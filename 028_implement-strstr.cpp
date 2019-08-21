#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    int i = 0, j = 0;
    int len1 = haystack.length(), len2 = needle.length();
    if (needle.empty()) return 0;
    if (len1 < len2) return -1;
    vector<int> vec(_next(needle));
    
    while(i < len1 && j < len2) {
      if (j < 0 || haystack[i] == needle[j]) {
        i++;j++;
      }
      else {
        j = vec[j];
      }
    }

    if (len1-len2 < i-j)
      return -1;

    return i-j;
  }
private:
  vector<int> _next(string s){
    int i = 0, len = s.length();
    vector<int> vec(len);
    int t = vec[0] = -1;
    while (i < len - 1)
      if (t < 0 || s[i] == s[t])
        vec[++i] = ++t;
      else
        t = vec[t];

    return vec;
  }
};

int main()
{
  string str1 = "mississippi";
  string str2 = "issip";
  Solution solv;
  int ret = solv.strStr(str1, str2);
  cout<<"ret="<<ret<<endl;
}
