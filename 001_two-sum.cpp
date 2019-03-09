#include<map>
#include<vector>
#include<cstdio>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> hash;
    vector<int> result;
    /* key - value */
    for (int i = 0; i < nums.size(); i++) {
      int numberToFind = target - nums[i];
      if (hash.find(numberToFind) != hash.end()) {
        result.push_back(hash[numberToFind]);
        result.push_back(i);
        return result;
      }
      hash[nums[i]] = i;
    }
    return result;
  }
};

int main()
{
  int arr[] = {2,11,7,15};
  vector<int> vec;
  for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
    vec.push_back(arr[i]);
  }

  Solution solve;
  vector<int> res = solve.twoSum(vec, 9);
  for (int i = 0; i < res.size(); i++) {
    printf("%d ", res[i]);
  }
  printf("\n");
}
