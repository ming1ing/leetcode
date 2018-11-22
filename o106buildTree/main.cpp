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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size()==0) return NULL;
        int num=postorder.size();
        TreeNode *root=new TreeNode(postorder[num-1]);
        if(postorder.size()==1)
            return root;
        int mid=0;

        for(size_t i=0;i<num;i++)
        {
            if(inorder[i]==postorder[num-1])
            {
                mid=i;
                break;
            }
        }
        vector<int> leftpost;
        vector<int> leftinorder;
        for(int i=0;i<mid;i++)
        {
            leftpost.push_back(postorder[i]);
            leftinorder.push_back(inorder[i]);
        }
        root->left=buildTree(leftinorder,leftpost);
        vector<int> rightpost;
        vector<int> rightinorder;
        for(size_t i=mid+1;i<postorder.size();i++)
        {
            rightpost.push_back(postorder[i-1]);
            rightinorder.push_back(inorder[i]);
        }
        root->right=buildTree(rightinorder,rightpost);
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
    //int a[]={1,2,3};
    int b[]={9,3,15,20,7};
    //int b[]={2,3,1};
    int c[]={9,15,7,20,3};
    vector<int> post;
    vector<int> ino;
    for(size_t i=0;i<sizeof(c)/sizeof(int);i++)
        post.push_back(c[i]);
    for(size_t i=0;i<sizeof(b)/sizeof(int);i++)
        ino.push_back(b[i]);
    Solution *s=new Solution();
    TreeNode *root=s->buildTree(ino,post);
    printTree(root,0);
    return 0;
}
