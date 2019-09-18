#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  bool exist(vector<vector<char> >& board, string word) {
    int m = board.size(), n = board[0].size();
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (findpath(board, word, i, j, 0)) {
          return true;
        }
      }
    }
    return false;
  }

  bool findpath(vector<vector<char> >& board, string& word, int i, int j, int pos) {
    int rows = board.size(), cols = board[0].size();
    if (i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] != word[pos]) {
      return false;
    }

    if (pos == word.size() - 1) {
      return true;
    }

    board[i][j] = '#';
    bool res = findpath(board, word, i + 1, j, pos+1) || 
      findpath(board, word, i - 1, j, pos+1) ||
      findpath(board, word, i, j + 1, pos+1) ||
      findpath(board, word, i, j - 1, pos+1);
    board[i][j] = word[pos];
    return res;
  }
};

int main() {
  return 0;
}
