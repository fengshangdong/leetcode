#include<vector>
#include<map>
#include<cstdio>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		map<int, int> hash;
		vector<int> res;
		for (int i = 0; i < numbers.size(); i++) {
			int another = target - numbers[i];
			if (hash.find(another) != hash.end()) {
				res.push_back(hash[another]+1);
				res.push_back(i+1);
				return res;
			}
			hash[numbers[i]] = i;
		}

		return res;
	}
};

void print(vector<int>& vec)
{
	for (int i = 0; i < vec.size(); i++) {
		printf("%d ", vec[i]);
	}
	printf("\n");
}

int main()
{
	int target = 9;
	int arr[] = {2,7,11,15};
	vector<int> vec;
	for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
		vec.push_back(arr[i]);
	}

	print(vec);
	Solution solve;
	vector<int> res = solve.twoSum(vec, target);

	printf("%d\n", target);
	print(res);
}
