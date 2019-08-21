#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
  void gameOfLife(vector<vector<int> >& board) {
    for(int i=0;i<board.size();i++)
      for(int j=0;j<board[0].size();j++){
        _game(board,i,j);
      }

    for(int i=0;i<board.size();i++)
      for(int j=0;j<board[0].size();j++){
        if(board[i][j]==-1) board[i][j]=0;
        if(board[i][j]==2)  board[i][j]=1;
      }
  }

  void _game(vector<vector<int> >& board,int i,int j){
    int live=0;
    for (int x=-1;x<=1;x++)
      for (int y=-1;y<=1;y++) {
        if(x==0 && y==0) continue;
        if(i+x>=0 && i+x<board.size() && y+j>=0 && j+y<board[0].size())
          if(board[i+x][j+y]==1 || board[i+x][j+y]==-1) live++;
      }

    if (board[i][j]==1) {
      if(live<2 || live>3) board[i][j]=-1;
    }
    else {
      if(live==3) board[i][j]=2;
    }
  }
};

int main() {
  return 0;
}
