#include <stack>
#include <vector>
#include <stdio.h>
using namespace std;

/*
 * Definition for a binary tree node. */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  int res;
public:
  int kthSmallest(TreeNode* root, int k) {
    dfs(root,k);
    return res;
  }

  void dfs(TreeNode* node, int &k){
    if(!node) return;

    dfs(node->left, k);
    if(--k == 0){
      res = node->val;
      return;
    }

    dfs(node->right,k);
  }

};

int main() {
  TreeNode root(4);
  TreeNode node1(2);
  TreeNode node2(6);
  TreeNode node3(1);
  TreeNode node4(3);
  TreeNode node5(5);
  TreeNode node6(7);

  root.left = &node1;
  root.right= &node2;
  node1.left = &node3;
  node1.right= &node4;
  node2.left = &node5;
  node2.right= &node6;

  Solution solv;
  int res = solv.kthSmallest(&root,3);
  printf("%d\n", res);
}
