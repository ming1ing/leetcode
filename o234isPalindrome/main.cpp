#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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
    bool isPalindrome(ListNode* head) {
        ListNode *fp=head;
       if(fp==NULL) return true;
        ListNode *sp=head->next;
       if(sp==NULL) return true;
        ListNode *mp=NULL;


        while(sp!=NULL)
        {
            mp=fp;
            fp=fp->next;
            sp=sp->next;
            if(sp==NULL)
                break;
            sp=sp->next;
        }
       // cout<<mp->val<<"\n";
        mp->next=NULL;
       // cout<<fp->val<<"\n";
        //printList(fp);
        ListNode *re=reve(fp);
        //printList(re);
        bool ans=true;
        while(head)
        {
            if(head==NULL||re==NULL) break;
            if(head->val==re->val)
            {
                head=head->next;
                re=re->next;
            }
            else
            {
                ans=false;
                break;
            }

        }
        return ans;
    }
    ListNode* reve(ListNode *head)
    {
        ListNode *pre=NULL;
        ListNode *pnow=head;
        if(head==NULL||head->next==NULL) return head;
        while(pnow!=NULL)
        {

            ListNode *pnext=pnow->next;
            pnow->next=pre;
            if(pnext==NULL) return pnow;

            pre=pnow;
            pnow=pnext;
        }
    }
};

int main()
{
    ListNode *head=new ListNode(1);
    ListNode *st=head;
    int a[]={2
 //   ,1,2
    };
    for(int i=0;i<sizeof(a)/sizeof(int);i++)
    {
        head->next=new ListNode(a[i]);
        head=head->next;
    }
    printList(st);
    Solution *s=new Solution();
    cout<<s->isPalindrome(st);

    return 0;
}
