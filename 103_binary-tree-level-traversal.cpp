#include <algorithm>
#include <vector>
#include <queue>
#include <stdio.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    vector<vector<int> > res;
    if (!root) return res;

    bfs(res,root);
    return res;
  }

  void bfs(vector<vector<int> >& res, TreeNode* root) {
    queue<TreeNode*> Q;
    Q.push(root);
    int level = 0;
    while (!Q.empty()) {
      int size = Q.size();
      TreeNode *node;
      vector<int> row;
      ++level;
      for (int i = 0; i < size; i++) {
        node = Q.front(); Q.pop();
        row.push_back(node->val);
        if (node->left) Q.push(node->left);
        if (node->right) Q.push(node->right);
      }

      if (level%2 == 0)
        std::reverse(row.begin(), row.end());

      res.push_back(row);
    }
  }
};

int main()
{
  TreeNode root(0);
  TreeNode node1(1);
  TreeNode node2(2);
  TreeNode node3(3);
  TreeNode node4(4);
  TreeNode node5(5);
  TreeNode node6(6);
  TreeNode node7(7);
  TreeNode node8(8);
  TreeNode node9(9);
  root.left = &node1;
  root.right = &node2;
  node1.left = &node3;
  node1.right = &node4;
  node2.left = &node5;
  node2.right = &node6;
  node4.left = &node7;
  node4.right = &node8;
  node8.left = &node9;
  Solution solv;
  vector<vector<int> > res = solv.zigzagLevelOrder(&root);

  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      printf("%d ",res[i][j]);
    }
    printf("\n");
  }

}
