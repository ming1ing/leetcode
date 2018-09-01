#include <iostream>

using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode *slowp=head;
        ListNode *fastp=head->next;
        while(fastp!=NULL)
        {
            slowp=slowp->next;
            fastp=fastp->next;
            if(fastp==NULL)
                break;
            fastp=fastp->next;
        }
        return slowp;
    }
};
void printList(ListNode *l)
{
    while(l!=NULL)
    {
        cout<<l->val<<" ";
        l=l->next;
    }
    cout<<"\n";
}
int main()
{
    int n;

    while(cin>>n)
    {
        ListNode *start=new ListNode(1);
        ListNode *t=start;
        for(int i=2;i<=n;i++)
        {
            t->next=new ListNode(i);
            t=t->next;
        }
        Solution *solution=new Solution();
        printList(start);
        ListNode *ans=solution->middleNode(start);
        cout<<ans->val<<"\n";
    }
    return 0;
}
