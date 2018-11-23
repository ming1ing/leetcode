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
    TreeNode* invertTree(TreeNode* root) {
            if(root==NULL) return NULL;
            TreeNode *temp=root->left;
            root->left=root->right;
            root->right=temp;
            if(root->left) invertTree(root->left);
            if(root->right) invertTree(root->right);
            return root;
    }
};
void PrintTree(TreeNode * root,int id)
{
    if(root->left)
        PrintTree(root->left,id+1);
    if(root)
    {
        for(int i=0;i<id;i++)
            cout<<"\t";
        cout<<root->val<<"\n";
    }
    if(root->right)
        PrintTree(root->right,id+1);
}
int main()
{
    TreeNode *root=new TreeNode(4);
    root->left=new TreeNode(2);
    root->right=new TreeNode(7);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(3);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(9);
    Solution *s=new Solution();
    TreeNode *res=s->invertTree(root);
    PrintTree(res,0);
    return 0;
}
