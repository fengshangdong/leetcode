#include<vector>
#include<cstdio>

using namespace std;

class Solution {
public:
	vector<vector<int> > transpose(vector<vector<int> >& A) {
		/* row-行 col-列 */
		int row = A.size();
		int col = A[0].size();
		vector<vector<int> > res(col, vector<int>(row));
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				res[i][j] = A[j][i];
			}
		}

		return res;
	}
};

int main()
{
	int arr[3][3] = {{1,2,3}, {4,5,6,}, {7,8,9}};
	vector<vector<int> > v;
	for (int i = 0;i < 3; i++) {
		v.push_back(vector<int>());
		for (int j = 0; j < 3; j++) {
			v[i].push_back(arr[i][j]);
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	Solution solve;
	vector<vector<int> > res = solve.transpose(v);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
}
