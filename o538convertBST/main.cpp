#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    /*TreeNode* convertBST(TreeNode* root) {
        vector<int> mv;
        mv.clear();
        mv.push_back(0);
        makevector(mv,root);

        for(int i=1;i<mv.size();i++)
        {
            mv[i]=mv[i]+mv[i-1];
        }
        reverse(mv.begin(),mv.end());
        mv.pop_back();
        for(int i=0;i<mv.size();i++)
        {
            cout<<mv[i]<<" ";
        }
        cout<<"\n";
        int n=mv.size();
        findans(mv,root);
        return root;
    }
    void findans(vector<int>& mv,TreeNode* root)
    {
        if(root->right)
            findans(mv,root->right);
        if(root)
        {
            int n=mv.size();
            root->val=mv[n-1];
            mv.pop_back();
        }
        if(root->left)
            findans(mv,root->left);
    }
    void makevector(vector<int> &mv,TreeNode* root)
    {
        if(root->right)
            makevector(mv,root->right);
        if(root)
        {
            mv.push_back(root->val);
        }
        if(root->left)
            makevector(mv,root->left);
    }*/
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return NULL;
        int sum=0;
        findans(root,sum);
        return root;
    }
    void findans(TreeNode* root,int &sum)
    {
        if(root->right)
            findans(root->right,sum);
        if(root)
        {
            sum+=root->val;
            root->val=sum;
        }
        if(root->left)
            findans(root->left,sum);
    }
};
void PrintTree(TreeNode *root,int id)
{
    if(root->left)
        PrintTree(root->left,id+1);
    if(root)
    {
        for(int i=0;i<id;i++)
        {
            cout<<"\t";
        }
        cout<<root->val<<"\n";
    }
    if(root->right)
        PrintTree(root->right,id+1);
}
int main()
{
    TreeNode *root=new TreeNode(2);
    root->left=new TreeNode(0);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(-4);
    root->left->right=new TreeNode(1);
    Solution *s=new Solution();
    TreeNode*res=s->convertBST(root);
    PrintTree(res,0);
    return 0;
}
