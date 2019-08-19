#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
  }

  TreeNode* build(vector<int>& preorder, int pleft, int pright, vector<int>& inorder, int ileft, int iright) {
    if (pleft>pright||ileft>iright) return NULL;

    int i = 0;
    for (i = ileft; i<= iright; ++i) {
      if (inorder[i] == preorder[pleft]) break;
    }

    TreeNode *p = new TreeNode(preorder[pleft]);
    p->left = build(preorder, pleft+1, pleft+i-ileft, inorder, ileft, i-1);
    p->right = build(preorder, pleft+i-ileft+1, pright, inorder, i+1, iright);    

    return p;
  }
};

int main() {
  Solution solv;
  return 0;
}
