#include <iostream>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        if(!head||!head->next) return head;
        //ListNode *ppre=new ListNode(head->val-1);
        ListNode *ppre=NULL;
        ListNode *pres=ppre;
        //ppre->next=head;
        ListNode *phead=head;
        ListNode *pnext=phead->next;
        while(pnext)
        {
            while(phead->val==pnext->val)
            {
                pnext=pnext->next;
                if(!pnext) break;
            }
            if(phead->next==pnext)
            {
                if(!ppre)
                {
                    ppre=phead;
                    pres=ppre;
                }
                else
                {
                    ppre->next=phead;
                    ppre=ppre->next;
                }
                phead=pnext;
                pnext=phead->next;
            }
            else
            {
                phead=pnext;
                if(!phead||!pnext->next)
                {
                    if(!ppre)
                    {
                        ppre=phead;
                        pres=ppre;
                    }
                    else
                    {
                        ppre->next=phead;
                        ppre=ppre->next;
                    }
                    break;
                }
                pnext=pnext->next;
            }
        }

        return pres;
    }
};
ListNode * makelist(int a[],int len)
{
    if(len==0) return NULL;
    ListNode *head=new ListNode(a[0]);
    ListNode *th=head;
    for(int i=1; i<len; i++)
    {
        head->next=new ListNode(a[i]);
        head=head->next;
    }
    return th;
}
void printlist(ListNode *head)
{
    if(!head) return ;
    while(head)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<"\n";
}
int main()
{
    Solution *s=new Solution();
    //int a[]={1,2,3,3,4,4,5};
    int a[]= {1,1,1,3,3};
    ListNode *head=makelist(a,sizeof(a)/sizeof(int));
    printlist(head);
    ListNode *res=s->deleteDuplicates(head);
    printlist(res);
    return 0;
}
