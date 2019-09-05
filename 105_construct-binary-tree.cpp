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

    int mid = 0; // mid是中序的根结点位置
    for (mid = ileft; mid<= iright; ++mid) {
      if (inorder[mid] == preorder[pleft]) break;
    }

    TreeNode *p = new TreeNode(preorder[pleft]);
    p->left = build(preorder, pleft+1, pleft+(mid-ileft), inorder, ileft, mid-1);
    p->right = build(preorder, pleft+(mid-ileft)+1, pright, inorder, mid+1, iright);    

    return p;
  }
};

int main() {
  Solution solv;
  return 0;
}
