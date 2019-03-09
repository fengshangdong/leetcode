#include<vector>
#include<cstdio>

using namespace std;

class Solution {
public:
  int majorityElement(vector<int>& nums) {
    int count = 1;
    int element = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == element) {
        count++;
      }
      else {
        count--;
      }

      /* 遇到相同的元素就加1,否则减一 */
      /* 当count为0时,用别的元素进行比较,count重置为1 */
      if (count == 0){
        element = nums[i];
        count = 1;
      }
    }

    return element;
  }
};

int main() {
  int arr[] = {2,2,1,1,1,2,2};
  vector<int> vec;
  for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
    vec.push_back(arr[i]);
  }

  Solution solve;
  printf("%d\n", solve.majorityElement(vec));
}
