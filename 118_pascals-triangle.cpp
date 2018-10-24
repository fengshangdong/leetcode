#include<vector>
#include<cstdio>

using namespace std;

class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		vector<vector<int> > res(numRows);
		for (int i = 0; i < numRows; i++) {
			res[i].resize(i+1);
			res[i][0] = res[i][i] = 1;
			for(int j = 1; j < i; j++){
				/* 第i行需要计算的j下标为 1..i-1 */
				res[i][j] = res[i-1][j-1]+res[i-1][j];
			}
		}

		return res;
	}
};

int main()
{
	int n = 5;
	Solution solve;
	vector<vector<int> > res = solve.generate(n);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			printf("%d ",res[i][j]);
		}
		printf("\n");
	}
}
