#include <iostream>
#include<vector>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {

            vector<int> ans;
            ans.clear();
            treetovet(ans,root);
            TreeNode *res=makeTree(ans);
            return res;
    }
    void treetovet(vector<int> &ans,TreeNode *root)
    {
        if(root->left)
            treetovet(ans,root->left);
        if(root)
        {
            ans.push_back(root->val);
        }
        if(root->right)
            treetovet(ans,root->right);
    }
    TreeNode * makeTree(vector<int>& ans)
    {
        if(ans.size()==0) return NULL;
        int n=ans.size();
        TreeNode *root=new TreeNode(ans[0]);
        TreeNode *res=root;
        for(int i=1;i<n;i++)
        {
            root->right=new TreeNode(ans[i]);
            root=root->right;
        }
        return res;
    }
};
void printTree(TreeNode *root,int id)
{
    if(root->left)
        printTree(root->left,id+1);
    if(root)
    {
        for(int i=0;i<id;i++)
            cout<<"\t";
        cout<<root->val<<"\n";
    }
    if(root->right)
        printTree(root->right,id+1);
}
int main()
{
    TreeNode *root=new TreeNode(5);
    root->left=new TreeNode(3);
    root->right=new TreeNode(6);
    Solution *s=new Solution();
    TreeNode *res=s->increasingBST(root);
    printTree(res,0);
    return 0;
}
