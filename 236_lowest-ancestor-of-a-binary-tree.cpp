#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <string>
/**
 * Definition for a binary tree node.*/
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || p == root || q == root)
      return root;

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right= lowestCommonAncestor(root->right, p, q);

    if (left && right)
      return root;
    else if (left != NULL)
      return left;
    else if (right != NULL)
      return right;
    else
      return NULL;
  }

  int maxDepth2(TreeNode* root) {
    if (root == NULL)
      return 0;

      return std::max(maxDepth(root->left),maxDepth(root->right)) + 1;
  }

  int maxDepth(TreeNode* root) {
    if (root == NULL)
      return 0;

    int deep = 0;
    std::queue<TreeNode*> Q;
    Q.push(root);

    while (!Q.empty()) {
      int len = Q.size();
      TreeNode* node;

      ++deep;
      for (int i = 0; i < len; i++) {
        node = Q.front();
        Q.pop();
        if (node->left)  Q.push(node->left);
        if (node->right) Q.push(node->right);
      }
    }

    return deep;
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
  TreeNode* res = solv.lowestCommonAncestor(&root, &node9, &node7);
  printf("ret=%d\n",res->val);

}
