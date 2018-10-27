#include<vector>
#include<cstdio>

using namespace std;

class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int max = 0;
		int count = 0;
		for(int i = 0; i < nums.size(); i++) {
			if (nums[i] == 1) {
				max = std::max(++count, max);
			}
			else {
				count = 0;
			}
		}

		return max;
	}
};

int main()
{
	int arr[] = {1,1,1,0,1,1,0,1,1,1,1};
	vector<int> vec;
	for (int i = 0; i < sizeof(arr)/sizeof(arr[i]); i++) {
		vec.push_back(arr[i]);
	}

	for (int i = 0; i < vec.size(); i++) {
		printf("%d ", vec[i]);
	}
	printf("\n");

	Solution solve;
	printf("%d\n", solve.findMaxConsecutiveOnes(vec));
}
