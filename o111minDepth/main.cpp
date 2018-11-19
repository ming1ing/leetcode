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
    int minDepth(TreeNode* root) {
            if(root==NULL)
                return 0;
            else if(root->left==NULL&&root->right==NULL)
                return 1;
            else if(root->left!=NULL&&root->right==NULL)
                return minDepth(root->left)+1;
            else if(root->left==NULL&&root->right!=NULL)
                return minDepth(root->right)+1;
            return min(minDepth(root->left),minDepth(root->right))+1;
    }
};
int main()
{
    TreeNode *root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    Solution *s=new Solution();
    cout<<s->minDepth(root)<<"\n";
    return 0;
}
