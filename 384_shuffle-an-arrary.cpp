#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  vector<int> ori_nums;
  vector<int> rnd_nums;
  int N;
  Solution(vector<int>& nums) {
    ori_nums = nums;
    N = ori_nums.size();
    rnd_nums = nums;
  }

  /** Resets the array to its original configuration and return it. */
  vector<int> reset() {
    // rnd_nums = ori_nums;
    return ori_nums;
  }

  /** Returns a random shuffling of the array. */
  vector<int> shuffle() {
    for(int i=0; i < ori_nums.size(); i++) {
      int tmp = i+ rand()%(N-i);
      swap(rnd_nums[i], rnd_nums[tmp]);
    }

    return rnd_nums;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */


int main() {
  return 0;
}
