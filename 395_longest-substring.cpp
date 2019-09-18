#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

class Solution {
public:
  int longestSubstring(string s, int k) {
    if (k <= 1) return s.size();
    if (s.empty() || s.size() < k) return 0;

    vector<int> hash(128, 0);
    for (int i = 0; i < s.length(); i++)
      ++hash[s[i]];

    int i = 0;
    while (i < s.size() && hash[s[i]] >= k)
      ++i;

    if (i == s.size())
      return s.size();

    int l = longestSubstring(s.substr(0, i), k);
    while (i < s.size() && hash[s[i]] < k)
      ++i;

    int r = longestSubstring(s.substr(i), k);

    return max(l, r);
  }
};

int main() {
  string s = "caaabb";
  Solution solv;
  int count = solv.longestSubstring(s,3);
  printf("count=%d\n",count);
  return 0;
}
