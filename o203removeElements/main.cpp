#include <iostream>

using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return NULL;
        while(head->val==val)
        {
            head=head->next;
            if(head==NULL)
                break;
        }
        ListNode* t=head;
        while(t!=NULL)
        {
            while(t->next&&t->next->val==val)
            {
                t->next=t->next->next;
            }
            if(t->next)
            t=t->next;
            else
                break;
        }
        return head;
    }
};
int main()
{
    Solution *s=new Solution();
    ListNode *head=new ListNode(1);
    ListNode *ts=head;
    int a[]={2,2,1};
    for(int i=0;i<sizeof(a)/sizeof(int);i++)
    {
        ts->next=new ListNode(a[i]);
        ts=ts->next;
    }

    ListNode*res=s->removeElements(head,2);
    while(res)
    {
        cout<<res->val<<" ";
        res=res->next;
    }
    return 0;
}
