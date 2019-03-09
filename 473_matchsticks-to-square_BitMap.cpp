#include<vector>
#include<cstdio>

using namespace std;

class Solution {
public:
  bool makesquare(vector<int>& nums) {
    if (nums.size() < 4) {
      return false;
    }

    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
    }
    if (sum % 4) {
      return false;
    }

    /* side数组是组成边的元素, half是两条边的元素 */
    vector<int> side;
    vector<int> half;
    int target = sum / 4;
    int all = 1 << nums.size();
    for (int i = 0; i < all; i++) {
      int _sum = 0;
      /* 遍历nums,把加起来等于一条边的元素存放在side中 */
      for (int j = 0; j < nums.size(); j++) {
        if (i & (1 << j)) {
          _sum += nums[j];
        }
      }

      if (_sum == target) {
        side.push_back(i);
      }
    }

    /* 如果组成的边没有重复元素,把两条边存在half中 */
    for (int i = 0; i < side.size(); i++) {
      for (int j  = i+1; j < side.size(); j++) {
        if ((side[i]&side[j]) == 0) {
          half.push_back(side[i] | side[j]);
        }
      }
    }

    /* 如果有两个干净的half,返回true */
    for (int i = 0; i < half.size(); i++) {
      for (int j = i+1; j < half.size(); j++) {
        if ((half[i] & half[j]) == 0) {
          return true;
        }
      }
    }

    return false;
  }
};

int main()
{
  vector<int> square;
  square.push_back(3);
  square.push_back(1);
  square.push_back(2);
  square.push_back(1);
  square.push_back(2);
  square.push_back(3);

  Solution solve;
  printf("%d\n",solve.makesquare(square));
}
