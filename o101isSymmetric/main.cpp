#include <iostream>
#include<queue>
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
    bool check(TreeNode* Treeleft,TreeNode* Treeright)
    {
        if(Treeleft==NULL&&Treeright==NULL)
            return true;
        if(Treeleft==NULL&&Treeright!=NULL)
            return false;
        if(Treeleft!=NULL&&Treeright==NULL)
            return false;
        if(Treeleft->val!=Treeright->val)
            return false;
        if(Treeleft->val==Treeright->val)
            return check(Treeleft->right,Treeright->left)&&check(Treeleft->left,Treeright->right);
        return true;
    }
    bool isSymmetric(TreeNode* root)
    {
        if(root==NULL) return true;
        bool ans=true;
        ans=check(root->left,root->right);
        return ans;
    }
    bool isSymmetric2(TreeNode* root)
    {
        if(root==NULL) return true;
        queue<TreeNode *> left;
        queue<TreeNode *> right;
        left.push(root->left);
        right.push(root->right);
        while(!left.empty()&&!right.empty())
        {
            if(left.front()!=NULL&&right.front()==NULL)
                return false;
            if(left.front()==NULL&&right.front()!=NULL)
                return false;
            if(left.front()==NULL&&right.front()==NULL)
            {
                left.pop();
                right.pop();
                continue;
            }
            if(left.front()->val!=right.front()->val)
                return false;
            if(left.front()->val==right.front()->val)
            {
                left.push(left.front()->right);
                left.push(left.front()->left);
                right.push(right.front()->left);
                right.push(right.front()->right);
                left.pop();
                right.pop();
            }
        }
        if(left.empty()!=right.empty())
            return false;
        return true;
    }
};
void printTree(TreeNode *root)
{
    if(root==NULL) return ;
    cout<<root->val<<" ";
    printTree(root->left);
    printTree(root->right);

}
int main()
{
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    printTree(root);
    Solution *solution=new Solution();
    cout<<solution->isSymmetric2(root)<<"\n";
    return 0;
}
