#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int> > subsets(vector<int>& nums) {
    vector<vector<int> > res;
    for (int i = 0; i < nums.size(); i++) {
      vector<int> tmp;
      int len = res.size();
      for (int j = 0; j < len; j++) {//先遍历res里的集合，取出来加上nums[i]作为一个元素
        tmp = res[j];
        tmp.push_back(nums[i]);
        res.push_back(tmp);
      }

      vector<int> t;
      t.push_back(nums[i]);
      res.push_back(t);
    }
    res.push_back(vector<int>());//最后再加上空集合
    return res;
  }
};

int main() {
  vector<int> vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);
  Solution solv;
  vector<vector<int> > res = solv.subsets(vec);

  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      printf("%d ",res[i][j]);
    }
    printf("\n");
  }
}
