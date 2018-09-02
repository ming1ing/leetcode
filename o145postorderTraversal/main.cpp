#include <iostream>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
class Solution {
public:
    TreeNode* pushleft(TreeNode* root,stack<TreeNode *> &s1)
    {
        while(root!=NULL)
        {
            s1.push(root);
            if(root->left==NULL)
                return root;
            root=root->left;
        }
        return root;
    }
    vector<int> postorderTraversal(TreeNode* root) {
            vector<int> ans;
            ans.clear();
            stack<TreeNode *> s1;
            int times=0;
            while(!s1.empty())
            {
                s1.pop();
            }
            TreeNode *t=NULL;
            t=pushleft(root,s1);

            while(!s1.empty())
            {
                t=s1.top();
                if(t->right!=NULL)
                {
                    if(times==0){
                        t=pushleft(t->right,s1);
                        continue;
                    }
                    else{
                        ans.push_back(t->val);
                        cout<<t->val<<" ";
                        s1.pop();
                        if(!s1.empty()&&t==s1.top()->right)
                        times=1;
                        else if(!s1.empty()&&NULL==s1.top()->right)
                        times=1;
                        else
                        {
                            times=0;
                        }
                    }

                }
                else
                {
                    ans.push_back(t->val);
                    cout<<t->val<<" ";
                    s1.pop();
                    if(!s1.empty()&&t==s1.top()->right)
                    times=1;
                    else if(!s1.empty()&&NULL==s1.top()->right)
                    times=1;
                    else
                        times=0;

                }
            }
            return ans;
    }
};
void printftree(TreeNode* head)
{
    if(head!=NULL)
    {
        cout<<head->val<<" ";
    }
    else
    {
        return ;
    }
    printftree(head->left);
    printftree(head->right);
}
int main()
{

    TreeNode *head=new TreeNode(1);
    head->right=new TreeNode(2);
    //head->right->left=new TreeNode(3);
    head->right->right=new TreeNode(4);
    //head->right->right->right=new TreeNode(4);
    printftree(head);
    cout<<"\n";
    Solution *solution=new Solution();
    vector<int> ans=solution->postorderTraversal(head);
    for(int i=0;i<(int)ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
