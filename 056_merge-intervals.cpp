#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<vector<int> > merge(vector<vector<int> >& intervals) {
    if (intervals.empty())
      return intervals; 

    sort(intervals.begin(), intervals.end());
    vector<vector<int> > ans;
    ans.push_back(intervals[0]);

    int n = intervals.size();
    for(int i = 0; i < n; i ++){
      if(ans.back()[1] >= intervals[i][0]){
        ans.back()[1] = max(intervals[i][1], ans.back()[1]);
        continue;
      }
      else{
        ans.push_back(intervals[i]);
        continue;
      }
    }
    return ans;

  }
};

int main() {
  return 0;
}
