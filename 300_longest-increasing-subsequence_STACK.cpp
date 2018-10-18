#include<vector>
#include<cstdio>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		vector<int> stack;
		if (!nums.empty()) {
			stack.push_back(nums[0]);
		}

		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] > stack.back()) {
				stack.push_back(nums[i]);
			}
			else {
				for (int j = 0; j < stack.size(); j++) {
					if (stack[j] >= nums[i]) {
						stack[j] = nums[i];
						break;
					}
				}
			}
		}

		return stack.size();
	}
};

int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(4);

	Solution solve;
	printf("%d\n", solve.lengthOfLIS(nums));
}
