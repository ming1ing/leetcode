#include <iostream>
#include<cmath>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
            bool res=true;
            maxDepth(root,res);
            return res;
    }
    int maxDepth(TreeNode *root,bool & res){
            if(root==NULL)
                return 0;
            if(root->left==NULL&&root->right==NULL)
                return 1;
            int l=maxDepth(root->left,res);
            int r=maxDepth(root->right,res);
            if(abs(l-r)>1)
                res=false;
            return max(l,r)+1;
    }
};

int main()
{
    Solution *s=new Solution();
    TreeNode *root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->left->left=new TreeNode(8);
    root->left->left->left=new TreeNode(7);
    root->right=new TreeNode(20);
    //root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    root->right->right->right=new TreeNode(11);
    cout<<s->isBalanced(root)<<"\n";
    return 0;
}
