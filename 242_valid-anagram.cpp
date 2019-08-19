#include <string>
#include <stdio.h>
using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    int count[26] = {0};
    for (int i = 0; i < s.size(); i++)
      count[s[i]-'a'] += 1;
    for (int i = 0; i < t.size(); i++)
      count[t[i]-'a'] -= 1;

    for (int i = 0; i < 26; i++)
      if (count[i] != 0)
        return false;

    return true;
  }
};

int main()
{
  bool t = true;
  bool f = false;
  string s1("anagram");
  string s2("nagaram");
  string s3("rat");
  string s4("car");

  Solution solv;
  bool b1 = solv.isAnagram(s1,s2);
  bool b2 = solv.isAnagram(s3,s4);
  printf("b1=%d,b2=%d\n",b1,b2);
  printf("t=%d,f=%d\n",t,f);
}
