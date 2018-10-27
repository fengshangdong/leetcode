#include<vector>
#include<queue>
#include<utility>
#include<cstdio>

using namespace std;

class Solution {
public:
	int maxAreaOfIsland(vector<vector<int> >& grid) {
		int max = 0;
		/* 构造一个空的二维数组Mark,进行广度优先搜索做校对 */
		vector<vector<int> >mark(grid.size());
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				mark[i].push_back(0);
			}
		}

		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				if (grid[i][j] == 1 && mark[i][j] == 0) {
					max = std::max(BFS(grid, mark, i, j), max);
				}
			}
		}
		return max;
	}
private:
	/* 广度优先搜索 */
	/* 取队列头结点,对其上下左右四个方向进行搜索,加入队列尾 */
	int BFS(vector<vector<int> >& grid, vector<vector<int> >& mark, int x, int y) {
		mark[x][y] = 1;
		int count = 1;
		const int dx[] = {-1, 1, 0, 0};
		const int dy[] = { 0, 0,-1, 1};
		
		queue<pair<int,int> > Q;
		Q.push(make_pair(x,y));
		while (!Q.empty()) {
			x = Q.front().first;
			y = Q.front().second;
			Q.pop();
			for (int i = 0; i < 4; i++) {
				int newx = dx[i] + x;
				int newy = dy[i] + y;

				if (newx < 0 || newx >= mark.size() || newy < 0 || newy >= mark[newx].size())
					continue;

				if (grid[newx][newy] == 1 && mark[newx][newy] == 0) {
					Q.push(make_pair(newx, newy));
					mark[newx][newy] = 1;
					count++;
				}
			}
		}

		return count;
	}
};

int main() {
	int arr[4][5] = {{0,1,0,1,0}, {0,1,1,1,0},{0,0,0,1,0},{1,1,1,0,0}}; 
	vector<vector<int> >grid(4,vector<int>(5));
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			grid[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}

	Solution solve;
	printf("%d\n", solve.maxAreaOfIsland(grid));
}
