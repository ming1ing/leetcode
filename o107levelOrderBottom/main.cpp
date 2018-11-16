#include <iostream>
#include<queue>
#include<deque>
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
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        /* typedef pair<TreeNode*,int> P;
        vector<vector<int> > ans;
        deque<vector<int> > res;
        ans.clear();
        res.clear();
            if(root==NULL) return ans;
            queue<P> que;
            while(!que.empty())
                que.pop();
            que.push(make_pair(root,1));
            vector<int > temp;
            temp.clear();
            int id=1;
            while(!que.empty())
            {
                P a=que.front();
                que.pop();
                if(a.second==id)
                {
                    temp.push_back(a.first->val);
                }
                else
                {
                    //ans.push_back(temp);
                    res.push_front(temp);
                    temp.clear();
                    temp.push_back(a.first->val);
                    id++;
                }
                if(a.first->left!=NULL)
                {
                    que.push(make_pair(a.first->left,id+1));
                }
                if(a.first->right!=NULL)
                {
                    que.push(make_pair(a.first->right,id+1));
                }
            }
            if(temp.size())
            {
                //ans.push_back(temp);
                res.push_front(temp);
            }
            cout<<res.size()<<"\n";
            for(size_t i=0;i<res.size();i++)
            {
                ans.push_back(res[i]);
            }
            return ans;*/
        typedef pair<TreeNode*,int> P;
        vector<vector<int> > ans;
        ans.clear();
            if(root==NULL) return ans;
            queue<P> que;
            while(!que.empty())
                que.pop();
            que.push(make_pair(root,1));
            vector<int > temp;
            temp.clear();
            int id=1;
            while(!que.empty())
            {
                P a=que.front();
                que.pop();
                if(a.second==id)
                {
                    temp.push_back(a.first->val);
                }
                else
                {
                    ans.push_back(temp);
                    temp.clear();
                    temp.push_back(a.first->val);
                    id++;
                }
                if(a.first->left!=NULL)
                {
                    que.push(make_pair(a.first->left,id+1));
                }
                if(a.first->right!=NULL)
                {
                    que.push(make_pair(a.first->right,id+1));
                }
            }
            if(temp.size())
            {
                ans.push_back(temp);
            }
            reverse(ans.begin(),ans.end());
            return ans;
    }
};
int main()
{
    TreeNode *root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    Solution *ss=new Solution();
    vector<vector<int> > ans;
    ans=ss->levelOrderBottom(root);
    for(size_t i=0;i<ans.size();i++)
    {
        for(size_t j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

