#include <iostream>

using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
  class Solution {
public:
    void deleteNode(ListNode* node) {
        while(node->next)
        {
            node->val=node->next->val;
            if(node->next->next==NULL)
            {node->next=NULL;break;}
            node=node->next;
        }
    }
};
void printlist(ListNode *s)
{
    while(s!=NULL)
    {
        cout<<s->val<<" ";
        s=s->next;
    }
    cout<<"\n";
}
int main()
{
    Solution *solution=new Solution();
    ListNode *start=new ListNode(0);
    ListNode *t=start;
    int n;
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
            t->next=new ListNode(i);
            t=t->next;
        }
        printlist(start);
        ListNode *tt=start->next->next;
        solution->deleteNode(tt);
        printlist(start);
    }
    return 0;
}
