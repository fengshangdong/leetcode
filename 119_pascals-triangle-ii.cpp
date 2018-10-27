#include<vector>
#include<cstdio>

using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> res;
		for (int i = 0; i <= rowIndex; i++) {
			vector<int> curr(i+1, 1);
			for(int j = 1; j < i; j++) {
				curr[j] = res[j-1]+res[j];
			}
			res = curr;
		}

		return res;
	}
};

int main() {
	int n = 4;
	Solution solve;
	vector<int> res = solve.getRow(n); 
	for (int i = 0; i < res.size(); i++) {
		printf("%d ", res[i]);
	}
	printf("\n");
}
