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
    vector<vector<int> > pathSum(TreeNode* root, int sum) {

         vector<vector<int> > ans;
         ans.clear();
         if(root==NULL)
            return ans;
        vector<int> temp;
            temp.clear();
         findpath(root,sum,ans,temp);
         return ans;
    }
    void findpath(TreeNode* root, int sum,vector<vector<int> > & ans,vector<int> &temp){
        if(root==NULL) return ;
        //if(root->val>sum) return ;
        if(root->val==sum&&root->left==NULL&&root->right==NULL)
        {
            temp.push_back(root->val);
            ans.push_back(temp);
            temp.pop_back();

        }
        if(root->left&&!root->right)
        {
            temp.push_back(root->val);
            findpath(root->left,sum-root->val,ans,temp);
            temp.pop_back();
        }
        else if(!root->left&&root->right)
        {
            temp.push_back(root->val);
            findpath(root->right,sum-root->val,ans,temp);
            temp.pop_back();
        }
        else
        {
            temp.push_back(root->val);
            findpath(root->left,sum-root->val,ans,temp);
            findpath(root->right,sum-root->val,ans,temp);
            temp.pop_back();
        }
    }
};
int main()
{
    Solution *s=new Solution();
    TreeNode *root=new TreeNode(5);
    root->left=new TreeNode(4);
    root->right=new TreeNode(8);
    root->left->left=new TreeNode(11);
    root->left->left->left=new TreeNode(7);
    root->left->left->right=new TreeNode(2);
    root->right->left=new TreeNode(13);
    root->right->right=new TreeNode(4);
    root->right->right->left=new TreeNode(5);
    root->right->right->right=new TreeNode(1);
    int n;
    while(cin>>n)
    {
         vector<vector<int> > res=s->pathSum(root,n);
         for(size_t i=0;i<res.size();i++)
         {
             for(size_t j=0;j<res[i].size();j++)
             {
                 cout<<res[i][j]<<" ";
             }
                cout<<"\n";
         }
    }

    return 0;
}
