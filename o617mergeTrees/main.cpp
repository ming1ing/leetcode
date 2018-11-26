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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1&&!t2) return NULL;
        if(t1==NULL&&t2) return t2;
        if(t2==NULL&&t1) return t1;
        if(t1&&t2)
        {
            TreeNode *root=new TreeNode(t1->val+t2->val);
            root->left=mergeTrees(t1->left,t2->left);
            root->right=mergeTrees(t1->right,t2->right);
            return root;
        }
       // return NULL;
    }
};
void printTree(TreeNode* root,int id)
{
    if(root->left)
        printTree(root->left,id+1);
    if(root)
    {
        for(int i=0;i<id;i++)
        {
            cout<<"\t";
        }
        cout<<root->val<<"\n";
    }
    if(root->right)
        printTree(root->right,id+1);

}
int main()
{
    TreeNode *t1=new TreeNode(1);
    t1->left=new TreeNode(3);
    t1->right=new TreeNode(2);
    t1->left->left=new TreeNode(5);
    TreeNode *t2=new TreeNode(2);
    t2->left=new TreeNode(1);
    t2->right=new TreeNode(3);
    t2->left->right=new TreeNode(4);
    t2->right->right=new TreeNode(7);
    Solution *s=new Solution();
    TreeNode*root=s->mergeTrees(t1,t2);
    printTree(root,0);
    return 0;
}
