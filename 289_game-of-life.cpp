#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
  void gameOfLife(vector<vector<int> >& board) {
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
        cell(board, i, j);
      }
    }

    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
        if (board[i][j] == -1)
          board[i][j] = 0;

        if (board[i][j] == 2)
          board[i][j] = 1;
      }
    }
  }

  void cell(vector<vector<int> >& board, int x, int y) {
    int live = 0;
    for (int dx = -1; dx <= 1; dx++) {
      for (int dy = -1; dy <= 1; dy++) {
        if (dx == 0 && dy == 0)
          continue;

        if (0 <= x+dx && x+dx < board.size() && 0 <= y+dy && y+dy < board[0].size())
          if (board[x+dx][y+dy] == -1 || board[x+dx][y+dy] == 1)
            live++;
      }
    }

    if (board[x][y] == 1) {
      if (live < 2 || 3 < live)
        board[x][y] = -1;
    }
    else {
      if (live == 3)
        board[x][y] = 2;
    }
  }
};

int main() {
  return 0;
}
