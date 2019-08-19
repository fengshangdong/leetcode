#include <vector>
#include <stdlib.h>
#include <queue>
#include <stdio.h>
using namespace std;

/* Definition for a binary tree node. */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* insertNode(vector<int>& nums, int left, int right){
    if(left > right) return NULL;
    int mid = left + ((right - left) >> 1);
    TreeNode* root = new TreeNode(nums[mid]);

    root->left = insertNode(nums, left, mid - 1);
    root->right = insertNode(nums, mid + 1, right);

    return root;
  }

  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return insertNode(nums, 0, nums.size() - 1);
  } 
};

static void print_preorder(const TreeNode *node) {
  if (node == NULL) return;
  fprintf(stdout, "Node=%03d\n", (node->val));
  print_preorder(node->left);
  print_preorder(node->right);
}

static void print_midorder(const TreeNode *node) {
  if (node == NULL) return;
  print_midorder(node->left);
  fprintf(stdout, "Node=%03d\n", (node->val));
  print_midorder(node->right);
}

static void print_level(TreeNode *root) {
  TreeNode sb(-1);
  if (root == NULL) return;

  queue<TreeNode*> Q;
  Q.push(root);
  TreeNode* node;
  // while(!Q.empty()) {
  while(Q.size() < 32) {
    int size = Q.size();
    for (int i = 0; i < size; i++) {
      node = Q.front();
      Q.pop();
      fprintf(stdout, "Node=%d ", (node->val));
      if (node->left != NULL) Q.push(node->left);
      else Q.push(&sb);

      if (node->right != NULL) Q.push(node->right);
      else Q.push(&sb);
    }
    printf("\n");
  }
}

int main()
{
  vector<int> vec;
  vec.push_back(0);
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);
  vec.push_back(5);
  vec.push_back(6);
  vec.push_back(7);
  vec.push_back(8);
  vec.push_back(9);
  vec.push_back(10);
  Solution solv;
  TreeNode* node = solv.sortedArrayToBST(vec);
  print_preorder(node);
  printf("*********\n");
  print_midorder(node);
  printf("*********\n");
  print_level(node);
}
