#include<vector>
#include<cstdio>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
		int num = 0;
		vector<int> res(nums.size()+1, -1);
		for (int i = 0; i < nums.size(); i++) {
			res[nums[i]] = nums[i];
		}
	        
		for (int i = 0; i < res.size(); i++) {
			if (res[i] == -1) {
				return i;
			}
		}
	}
};

int main() {
	int arr[] = {9,6,4,2,3,5,7,0,1};
	vector<int> vec;
	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
		vec.push_back(arr[i]);
	}

	Solution solve;
	printf("%d\n", solve.missingNumber(vec));
}
