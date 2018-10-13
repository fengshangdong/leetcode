#include<vector>
#include<queue>
#include<utility>
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

		/* 遍历grid数组 , 对各个岛进行广度优先搜索 */
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				if(grid[i][j] == '1' && mark[i][j] == 0) {
					BFS(grid, mark, i, j);
					res++;
				}
			}
		}

		return res;
	}

private:
	/** 对单个岛屿进行广度优先搜索 **/
	void BFS(vector<vector<char> >&grid, vector<vector<int> >&mark, int x, int y) {
		/* 队列Q保存待搜索的位置 */
		queue<pair<int, int> > Q;
		Q.push(make_pair(x,y));
		static const int dx[] = {1,-1, 0, 0};
		static const int dy[] = {0, 0, 1,-1};

		mark[x][y] = 1;
		/* 队列不为空时,循环 */
		while(!Q.empty()) {
			/* 取队列头结点 */
			x = Q.front().first;
			y = Q.front().second;
			Q.pop();

			/* 搜索上下左右四个位置 */
			for (int i = 0; i < 4; i++) {
				int newx = dx[i] + x;
				int newy = dy[i] + y;

				/* 超出mark范围 , 进行下一个for循环 */
				if (newx < 0 || newx >= mark.size() || newy < 0 || newy >= mark[newx].size())
					continue;

				/* Q队列保存搜索到的位置 */
				if (grid[newx][newy] == '1' && mark[newx][newy] == 0) {
					Q.push(make_pair(newx, newy));
					mark[newx][newy] = 1;
				}
			}
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
