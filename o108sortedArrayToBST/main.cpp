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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
            if(nums.size()==0)
                return NULL;
            int len=nums.size();
            int mid=len/2;
            TreeNode *root=new TreeNode(nums[mid]);
            vector<int> left;
            vector<int> right;
            for(int i=0;i<mid;i++)
            {
                left.push_back(nums[i]);
            }
            for(int i=mid+1;i<len;i++)
            {
                right.push_back(nums[i]);
            }
            if(!left.empty())
            root->left=sortedArrayToBST(left);
            if(!right.empty())
            root->right=sortedArrayToBST(right);
            return root;
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
    vector<int> ans;
    ans.push_back(-10);
    ans.push_back(-3);
    ans.push_back(0);
    ans.push_back(5);
    ans.push_back(9);
    Solution *s=new Solution();
    TreeNode *root=s->sortedArrayToBST(ans);
    printTree(root,0);
    return 0;
}
