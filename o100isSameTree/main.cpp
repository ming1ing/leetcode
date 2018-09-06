#include <iostream>

using namespace std;
struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
          if(p==NULL&&q==NULL)
            return true;
          if(p->val==q->val)
          {
              return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
          }
          else {
          return false;
          }
    }
};
int main()
{
   TreeNode *a=new TreeNode(1);
   TreeNode *b=new TreeNode(1);
   a->left=new TreeNode(2);
   a->right=new TreeNode(3);
   b->left=new TreeNode(2);
   b->right=new TreeNode(3);
   Solution *solution=new Solution();
   cout<<solution->isSameTree(a,b)<<"\n";
    return 0;
}
