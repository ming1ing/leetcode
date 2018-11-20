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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL) return false;
        if(root->val==sum&&root->left==NULL&&root->right==NULL) return true;
        if(root->left&&!root->right)
            return hasPathSum(root->left,sum-root->val);
        else if(!root->left&&root->right)
            return hasPathSum(root->right,sum-root->val);
        else
        return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);
    }
};
int main()
{
    TreeNode *root=new TreeNode(5);
    root->left=new TreeNode(4);
    root->right=new TreeNode(8);
    root->left->left=new TreeNode(11);
    Solution *s=new Solution();
    cout<<s->hasPathSum(root,19+1);
    return 0;
}
