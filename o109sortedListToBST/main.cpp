#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void printList(ListNode *head)
{
    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<"\n";
}
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
            if(head==NULL) return NULL;
            if(head->next==NULL)
            {
                TreeNode *root=new TreeNode(head->val);
                head=NULL;
                return root;
            }
            ListNode *sp=head;
            ListNode *fp=head->next;
            ListNode *sr=sp;
            while(fp->next!=NULL)
            {
                sr=sp;
                sp=sp->next;
                fp=fp->next;
                if(fp==NULL) break;
                fp=fp->next;
                if(fp==NULL) break;
            }


            TreeNode *root=new TreeNode(sp->val);
            if(head==sp)
            {
                head=NULL;
            }
            fp=sp->next;
            sr->next=NULL;
            sp->next=NULL;

           // printList(head);
           // printList(fp);

            sp=NULL;
            if(head)
            root->left=sortedListToBST(head);
            if(fp)
            root->right=sortedListToBST(fp);
            return root;
       }
};
ListNode *makeList(int *a,int m_size)
{
    if(m_size==0) return NULL;
    ListNode *head=new ListNode(a[0]);
    ListNode *s=head;
    for(int i=1;i<m_size;i++)
    {

        head->next=new ListNode(a[i]);
        head=head->next;
    }
    return s;
}

void printTree(TreeNode* root ,int id)
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
   // ListNode *head=new ListNode(-10);
    int a[]={-10,-3,0,5,9};
    ListNode *head=makeList(a,sizeof(a)/sizeof(int));
    //printList(head);
    Solution *s=new Solution();
    TreeNode *root=s->sortedListToBST(head);
    printTree(root,0);
    return 0;
}
