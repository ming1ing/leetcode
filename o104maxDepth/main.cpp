#include <cstddef>
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
    int maxDepth(TreeNode* root) {
            if(root==NULL)
                return 0;
            if(root->left==NULL&&root->right==NULL)
                return 1;
            return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};
int main()
{
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    Solution *s=new Solution();
    cout<<s->maxDepth(root)<<"\n";
    return 0;
}
