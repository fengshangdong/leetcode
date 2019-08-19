#include <stdlib.h>
#include <stdio.h>
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return _m(root->left, root->right);
  }

private:
  bool _m(TreeNode* left, TreeNode* right){
    if (!left) 
      return !right;
    else if (!right)
      return !left;
    else
      return (left->val == right->val) && _m(left->left, right->right) && _m(left->right, right->left);
  }
};

int main() {
  TreeNode root(0);
  TreeNode node1(1);
  TreeNode node2(1);
  TreeNode node3(3);
  TreeNode node4(4);
  TreeNode node5(4);
  TreeNode node6(3);

  root.left = &node1;
  root.right= &node2;
  node1.left = &node3;
  node1.right= &node4;
  node2.left = &node5;
  node2.right= &node6;

  Solution solv;
  bool ret = solv.isSymmetric(&root);
  printf("%d\n", ret);
}
