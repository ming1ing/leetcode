#include <iostream>

using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
  class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
			return NULL;
		ListNode *pnext=head->next;
		//if (pnext == NULL)
		//	return head;
		ListNode *phead = head;
		while (pnext!=NULL)
		{
			if (phead->val == pnext->val)
			{
				phead->next = pnext->next;
			}
			else
			{
				phead = pnext;

			}
				pnext = pnext->next;
		}
		return head;
    }
};
void printlist(ListNode *start)
{
    while(start!=NULL)
    {
        cout<<start->val<<" ";
        start=start->next;
    }
    cout<<"\n";
}
int main()
{
    int n;
    while(cin>>n)
    {
        ListNode *start=new ListNode(0);
        ListNode *ts=start;
        for(int i=1;i<n;i++)
        {
            start->next=new ListNode((i+1)/2);
            start=start->next;
        }
        printlist(ts);
        Solution *solution=new Solution();
        printlist(solution->deleteDuplicates(ts));
    }
    return 0;
}
