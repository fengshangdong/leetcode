#include<cstdlib>
#include<vector>
#include<cstdio>

using namespace std;

class Solution {
public:
  /* 将元素值减1作为数组下标,取相反数, 则可以排除未出现的值 */
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
      int m = abs(nums[i]) - 1;
      nums[m] = (nums[m] > 0) ? -nums[m] : nums[m];
    }

    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0) {
        res.push_back(i+1);
      }
    }

    return res;
  }
};

void print(vector<int>& vec)
{
  for (int i = 0; i < vec.size(); i++)
    printf("%d ", vec[i]);
  printf("\n");
}

int main()
{
  int arr[] = {4, 3, 2, 7, 8, 2, 3, 1};
  vector<int> vec;
  for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
    vec.push_back(arr[i]);
  }

  Solution solve;
  print(vec);
  vector<int> res = solve.findDisappearedNumbers(vec);
  print(res);
}
