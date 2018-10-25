#include<vector>
#include<cstdio>

using namespace std;

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int count = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i]) {
				nums[count++] = nums[i];
			}
		}

		while (count < nums.size()) {
			nums[count++] = 0;
		}

		return;
	}
};

int main()
{
	int arr[] = {0,1,0,3,12};
	vector<int> vec;
	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
		vec.push_back(arr[i]);
	}

	for (int i = 0; i < vec.size(); i++) {
		printf("%d ", vec[i]);
	}
	printf("\n");

	Solution solve;
	solve.moveZeroes(vec);

	for (int i = 0; i < vec.size(); i++) {
		printf("%d ", vec[i]);
	}
	printf("\n");
}
