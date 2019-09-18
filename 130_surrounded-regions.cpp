#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
  void solve(vector<vector<char> >& board) {

    int row = board.size();
    if(row==0)
      return ;

    int col = board[0].size();
    if(row<=2 || col<=2)
      return ;

    queue<pair<int,int>> q;

    for(int i = 0;i<col;i++){
      if(board[0][i]=='O'){
        q.push(make_pair(0,i));
        board[0][i]='*';
      }
      if(board[row-1][i]=='O'){
        q.push(make_pair(row-1,i));
        board[row-1][i]='*';
      }
    }
    for(int i = 1;i<row-1;i++){
      if(board[i][0]=='O'){
        q.push(make_pair(i,0));
        board[i][0]='*';
      }
      if(board[i][col-1]=='O'){
        q.push(make_pair(i,col-1));
        board[i][col-1]='*';
      }
    }

    while(!q.empty()){
      pair<int,int> p=q.front();
      q.pop();
      int x=p.first;
      int y=p.second;
      if(x-1>=0 && board[x-1][y]=='O'){
        q.push(make_pair(x-1,y));
        board[x-1][y]='*';
      }
      if(x+1<row && board[x+1][y]=='O'){
        q.push(make_pair(x+1,y));
        board[x+1][y]='*';
      }
      if(y-1>=0 && board[x][y-1]=='O'){
        q.push(make_pair(x,y-1));
        board[x][y-1]='*';
      }
      if(y+1<col && board[x][y+1]=='O'){
        q.push(make_pair(x,y+1));
        board[x][y+1]='*';
      }
    }

    for(int i =0;i<row;i++){
      for(int j=0;j<col;j++){
        if(board[i][j]=='O')
          board[i][j]='X';
        else if(board[i][j]=='*')
          board[i][j]='O';
      }
    }
  }
};

int main() {
  return 0;
}
