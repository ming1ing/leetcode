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
    vector<TreeNode*> generateTrees(    int n) {
        vector<TreeNode*> res;
        res.clear();
        if(n==0)
            return res;
        return    makeTree(1,n);
    }
    vector<TreeNode*> makeTree(int l,int r){
            vector<TreeNode*> res;
            if(l>r)
            {
                res.push_back(NULL);
                return res;
            }
            for(int mid=l;mid<=r;mid++)
            {
                vector<TreeNode*> left=makeTree(l,mid-1);
                for(size_t i=0;i<left.size();i++)
                {
                    vector<TreeNode*> right=makeTree(mid+1,r);
                    for(size_t j=0;j<right.size();j++)
                    {
                        TreeNode *root=new TreeNode(mid);
                        root->left=left[i];
                        root->right=right[j];
                        res.push_back(root);
                    }
                }
            }
            return res;
    }
};
void printTree(TreeNode* root,int id)
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
    Solution *s=new Solution();
    vector<TreeNode*> ans=s->generateTrees(3);
    cout<<ans.size()<<"\n";
    for(vector<TreeNode*>::iterator it=ans.begin();it!=ans.end();it++)
    {
        printTree(*it,0);
    }
    return 0;
}
