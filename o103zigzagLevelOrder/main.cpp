#include <iostream>
#include<stack>
#include<vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root)
    {
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        vector<vector<int> > ans;
        ans.clear();
        if(root==NULL)
            return ans;
        s1.push(root);
        int id=1;

        while(!s1.empty()||!s2.empty())
        {
            if(id==1)
            {
                level(s1,s2,ans,id);
                id=0;
                continue;
            }
            else
            {
                level(s2,s1,ans,id);
                id=1;
            }
        }
        return ans;
    }
    void level(stack<TreeNode*>& s,stack<TreeNode*>& ts,vector<vector <int> > &ans,int id)
    {
        vector<int> temp;
        temp.clear();
        while(!s.empty())
        {
            TreeNode *t=s.top();
            s.pop();
            temp.push_back(t->val);
            if(id==0)
            {
                if(t->right)
                    ts.push(t->right);
                if(t->left)
                    ts.push(t->left);
            }
            else
            {
                if(t->left)
                    ts.push(t->left);
                if(t->right)
                    ts.push(t->right);
            }
        }
        ans.push_back(temp);
        temp.clear();
    }
};
int main()
{
    Solution *s=new Solution();
    TreeNode *root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    vector<vector<int> >res=s->zigzagLevelOrder(root);
    for(size_t i=0; i<res.size(); i++)
    {
        for(size_t j=0; j<res[i].size(); j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
