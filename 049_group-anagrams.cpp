#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。*/
class Solution {
public:
  vector<vector<string> > groupAnagrams(vector<string>& strs) {
    vector<vector<string> > res;
    map<string,vector<string> > M;
    for(int i=0; i<strs.size(); i++){
      string key = strs[i];
      std::sort(key.begin(),key.end());
      M[key].push_back(strs[i]);
    }

    map<string,vector<string> >::iterator ite;
    for(ite=M.begin(); ite!=M.end(); ite++)
      res.push_back(ite->second);
    return res;
  }
};

int main() {
  return 0;
}
