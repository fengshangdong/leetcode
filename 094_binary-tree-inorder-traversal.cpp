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
public:
  vector<int> vec;
  vector<int> inorderTraversal(TreeNode* root) {
    if (root) {
      if (root->left)
        inorderTraversal(root->left);
      vec.push_back(root->val);
      if (root->right)
        inorderTraversal(root->right);
    }
    return vec;
  }

  vector<int> inorderTraversal_2(TreeNode* root) {
    stack<TreeNode*> stk;
    vector<int> res;
    while (root!=NULL || !stk.empty()) {
      if (root) {
        stk.push(root);
        root=root->left;
      }
      else {
        root=stk.top();stk.pop();
        res.push_back(root->val);
        root=root->right;
      }
    }
    return res;
  }
};

int main() {
  TreeNode root(0);
  TreeNode node1(1);
  TreeNode node2(2);
  TreeNode node3(3);
  TreeNode node4(4);
  TreeNode node5(5);
  TreeNode node6(6);

  root.left = &node1;
  root.right= &node2;
  node1.left = &node3;
  node1.right= &node4;
  node2.left = &node5;
  node2.right= &node6;

  Solution solv;
  vector<int> res = solv.inorderTraversal(&root);
  printf("res.size=%d\n",res.size());
  for (int i = 0; i < res.size(); i++)
    printf("%d ", res[i]);
  printf("\n");
}
