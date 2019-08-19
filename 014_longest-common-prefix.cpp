#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
  public:
    string longestCommonPrefix(vector<string>& strs) {
      if(strs.empty()||strs[0].empty()) return "";

      int n=strs.size();
      int n1=strs[0].size();
      for(int i=0;i<n1;i++){ //遍历flower的长度
        char c=strs[0][i];
        for(int j=1;j<n;j++){//遍历三个字符串
          if(strs[j][i]!=c){
            return (i==0)?"":strs[0].substr(0,i);
          }
        }
      }
      return strs[0];
    }
};

class Solution2 {
public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    return _longestCommonPrefix(strs, 0 , strs.size() - 1);
  }

private:
  string _longestCommonPrefix(vector<string>& strs, int left, int right) {
    if (left == right) {
      return strs[left];
    }
    else {
      int mid = (left + right)/2;
      string lcpLeft =  _longestCommonPrefix(strs, left , mid);
      string lcpRight = _longestCommonPrefix(strs, mid + 1,right);
      return commonPrefix(lcpLeft, lcpRight);
    }
  }

  string commonPrefix(string strleft, string strright) {
    int min = std::min(strleft.length(), strright.length());
    for (int i = 0; i < min; i++) {
      if ( strleft[i] != strright[i] )
        return strleft.substr(0, i);
    }
    return strleft.substr(0, min);
  }
};

int main() {
  vector<string> vec;
  vec.push_back("hellowolrd");
  vec.push_back("heliowolrd");
  vec.push_back("heloowolrd");
  Solution solv;
  string str = solv.longestCommonPrefix(vec);
  cout << "str=" << str << endl;
}
