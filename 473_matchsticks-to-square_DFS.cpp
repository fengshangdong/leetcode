#include <vector>
#include <algorithm>
#include <cstddef>
#include <cstdio>

using namespace std;

class Solution {
public:
	bool makesquare(vector<int>& nums) {
		/* 4个以下的元素个数不能构成正方形 */
		if (nums.size() < 4) {
			return false;
		}

		int sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
		}
		
		/* 正方形周长对4取模不能有余数*/
		if (sum % 4) {
			return false;
		}

		/* 数组按从大到小排序 */
		std::sort(nums.rbegin(), nums.rend());
		int bucket[4] = { 0 };
		return DFS(0, nums, sum/4, bucket);
	}

private:
	/* 遍历4个桶, 将数组放进合适的桶中, 对桶中值进行判断 */
	bool DFS(int index, vector<int>& nums, int target, int bucket[])
	{
		if (index >= nums.size()) {
			return (bucket[0] == bucket[1] && bucket[1] == bucket[2] && bucket[2] == bucket[3]);
		}

		for (int i = 0; i < 4; i++) {
			if (nums[index] + bucket[i] > target) {
				continue;
			}

			bucket[i] += nums[index];
			if (DFS(index + 1, nums, target, bucket)) {
				return true;
			}
			bucket[i] -= nums[index];
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
	square.push_back(2);
	square.push_back(1);
	square.push_back(2);
	square.push_back(3);
	square.push_back(2);

	Solution solve;
	printf("ret=%d\n", solve.makesquare(square));
}
