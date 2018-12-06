#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head&&!head->next) return head;
        ListNode *podd=head;
        ListNode *peven=head->next;
        ListNode *pnext=peven->next;
        ListNode *psecond=peven;
        while(pnext)
        {
            peven->next=pnext->next;
            pnext->next=podd->next;
            podd->next=pnext;

            podd=podd->next;
            peven=peven->next;
            if(!peven) break;
            pnext=peven->next;
           // cout<<"pnext="<<pnext->val<<"\n";
            /*peven->next=pnext->next;
            podd->next=pnext;
            //pnext->next=peven;
            pnext->next=psecond;
            pnext=peven->next;
            if(!pnext) break;
            pnext=pnext->next;
            peven=peven->next;
            podd=podd->next;*/
        }
        return head;
    }
};
ListNode *makelist(int n){
    if(n==0)
        return NULL;
    ListNode *head=new ListNode(1);
    ListNode *th=head;
    for(int i=2;i<=n;i++)
    {
        head->next=new ListNode(i);
        head=head->next;
    }
    return th;
}
void printlist(ListNode *head){
    if(!head) return ;
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<"\n";
}
int main()
{
    int n;
    Solution *s=new Solution();
    while(cin>>n)
    {
        ListNode *head=makelist(n);
        printlist(head);
        ListNode* res=s->oddEvenList(head);
        printlist(res);
    }

    return 0;
}
