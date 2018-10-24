#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

class Solution {
public:
	int arrayPairSum(vector<int>& nums) {
		int sum = 0;
		/* 贪心算法 因为不能取最大值,则每次取第二大的值 */
		std::sort(nums.begin(), nums.end());
		for(int i = 0; i < nums.size(); i+=2) {
			sum += nums[i];
		}

		return sum;
	}
};

int main()
{
	int arr[] = {1,4,3,2};
	vector<int> v;
	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
		v.push_back(arr[i]);
	}
	Solution solve;
	printf("%d\n", solve.arrayPairSum(v));
}
