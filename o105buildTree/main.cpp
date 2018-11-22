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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
                if(preorder.size()==0) return NULL;
        TreeNode *root=new TreeNode(preorder[0]);
        if(preorder.size()==1)
            return root;
        int mid=0;
        int num=preorder.size();
        for(size_t i=0;i<num;i++)
        {

            if(inorder[i]==preorder[0])
            {
                mid=i;
                break;
            }
        }
        vector<int> leftpre;
        vector<int> leftinorder;
        for(int i=1;i<=mid;i++)
        {
            leftpre.push_back(preorder[i]);
        }
        for(int i=0;i<mid;i++)
        {
            leftinorder.push_back(inorder[i]);
        }
        root->left=buildTree(leftpre,leftinorder);
        vector<int> rightpre;
        vector<int> rightinorder;
        for(size_t i=mid+1;i<preorder.size();i++)
        {
            rightpre.push_back(preorder[i]);
        }
        for(size_t i=mid+1;i<inorder.size();i++)
        {
            rightinorder.push_back(inorder[i]);
        }
        root->right=buildTree(rightpre,rightinorder);
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
    //int a[]={3,9,20,15,7};
    int a[]={1,2,3};
    //int b[]={9,3,15,20,7};
    int b[]={2,3,1};
    vector<int> pre;
    vector<int> ino;
    for(size_t i=0;i<sizeof(a)/sizeof(int);i++)
        pre.push_back(a[i]);
    for(size_t i=0;i<sizeof(b)/sizeof(int);i++)
        ino.push_back(b[i]);
    Solution *s=new Solution();
    TreeNode *root=s->buildTree(pre,ino);
    printTree(root,0);
    return 0;
}
