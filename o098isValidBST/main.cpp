#include <iostream>
#include<queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    void put(TreeNode* root,queue<TreeNode *> &node)
    {
        if(root==NULL) return ;
        //if(root->left!=NULL)
        put(root->left,node);
        node.push(root);
         put(root->right,node);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        queue<TreeNode *> node;
        put(root,node);
        int k=node.front()->val;
        //cout<<k<<" ";
        node.pop();
        while(!node.empty())
        {
            if(node.front()->val<=k)
                return false;
            else
            {
                k=node.front()->val;
                node.pop();
                //cout<<k<<" ";
            }
        }
        return true;
    }
};
int main()
{
    Solution *solution=new Solution();
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(1);
    cout<<solution->isValidBST(root)<<"\n";
    return 0;
}
