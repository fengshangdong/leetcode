#include<vector>
#include<cstdio>

using namespace std;

class Solution {
public:
	int numIslands(vector<vector<char> >& grid) {
		int res = 0;
		/* 构造二维数组mark */
		vector<vector<int> > mark;
		for (int i = 0; i < grid.size(); i++) {
			mark.push_back(vector<int>());
			for (int j = 0; j < grid[i].size(); j++) {
				mark[i].push_back(0);
			}
		}

		/* 遍历grid数组 , 对各个岛进行深度优先搜索 */
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				if(grid[i][j] == '1' && mark[i][j] == 0) {
					DFS(grid, mark, i, j);
					res++;
				}
			}
		}

		return res;
	}

private:
	/** 对单个岛屿进行深度优先搜索 **/
	void DFS(vector<vector<char> >& grid, vector<vector<int> >&mark, int x, int y) {
		mark[x][y] = 1;
		/* 方向数组 , 配合for循环对该位置的上下左右四个方向进行深度优先搜索 */
		static const int dx[] = {1,-1, 0, 0};
		static const int dy[] = {0, 0, 1,-1};
		for (int i = 0; i < 4; i++)
		{
			int newx = dx[i] + x;
			int newy = dy[i] + y;
			/* 如果位置超出了mark数组范围 , 进行下一次循环 */
			if (newx < 0 || newx >= mark.size() || newy < 0 || newy >= mark[newx].size())
				continue;

			/* 对新的位置进行深度优先搜索 */
			if (grid[newx][newy] == '1' && mark[newx][newy] == 0)
				DFS(grid, mark, newx, newy);
		}
	}
};

int main()
{
	vector<vector<char> > grid;
	char str[10][10] = {"11100", "11000", "00100", "00011"};
	for (int i = 0; i < 4; i++) {
		grid.push_back(vector<char>());
		for (int j = 0; j < 5; j++)
			grid[i].push_back(str[i][j]);
	}

	Solution solve;
	printf("%d\n", solve.numIslands(grid));
	return 0;
}
