#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
  string largestNumber(vector<int>& nums) {
    if(nums.size() == 0) return "";
    else if(nums.size() == 1) return to_string(nums[0]);
    vector<string> v(nums.size());
    bool allZero = true;
    for(int i = 0;i < nums.size();i++){
      if(nums[i] != 0) allZero = false;
      v[i] = to_string(nums[i]);
    }
    if(allZero) return "0";
    quickSort(v, 0, v.size() - 1);
    string ans = "";
    for(int i = 0;i < v.size();i++){
      ans += v[i];
    }
    return ans;
  }

  void quickSort(vector<string>&v, int lo, int hi){
    if(hi - lo < 1) return;
    if(hi - lo == 1){
      if(smallerThan(v[lo], v[hi])) swap(v[lo], v[hi]);
      return;
    }
    int mi = partition(v, lo, hi);
    quickSort(v, lo, mi);
    quickSort(v, mi+1, hi);
  }

  int partition(vector<string>&v, int lo, int hi){
    swap(v[lo], v[lo + rand()%(hi - lo + 1)]);
    string pivot = v[lo];
    while(lo < hi){
      while(lo < hi){
        if(smallerThan(v[hi], pivot)) hi--;
        else{
          v[lo++] = v[hi];
          break;
        }
      }
      while(lo < hi){
        if(smallerThan(pivot, v[lo])) lo++;
        else{
          v[hi--] = v[lo];
          break;
        }
      }
    }
    v[lo] = pivot;
    return lo;
  }

  bool smallerThan(string& s, string& t){
    int i;
    for(i = 0;i < min(s.size(), t.size());i++){
      if(s[i] < t[i]) return true;
      if(s[i] > t[i]) return false;
    }
    if(i == s.size() && i == t.size()) return true;
    else if(i == s.size()){
      string sub = t.substr(i);
      return smallerThan(s, sub);
    }else{
      string sub = s.substr(i);
      return smallerThan(sub, t);
    }
  }

  string to_string(int n) {
    char chr[32] = {0};
    sprintf(chr, "%d", n);
    return string(chr);
  }
};

int main() {
  return 0;
}
