#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
  bool isValidSudoku(vector<vector<char> >& board) {
    int row[9][9] = {0}; //行记录
    int col[9][9] = {0}; //列记录
    int squ[3][3][9] = {0}; //九宫格记录

    int index;
    for (int i=0; i<9; i++)
      for (int j=0;j<9; j++) {
        if (board[i][j] != '.') {
          index = int(board[i][j] - '1');
          if (++row[i][index] > 1) return false;
          if (++col[index][j] > 1) return false;
          if (++squ[i/3][j/3][index] > 1) return false;
        }
      }
    return true;
  }
};

int main()
{
  vector<vector<char> > vec;
  Solution solv;
  int ret = solv.isValidSudoku(vec);
  cout << "ret=" << ret << endl;
}
