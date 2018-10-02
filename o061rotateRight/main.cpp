#include <iostream>
struct ListNode {
      int val;
     ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
using namespace std;
class Solution {
public:
    int countlist(ListNode *head)
	{
		int len = 0;
		while (head != NULL)
		{
			len++;
			head = head->next;
		}
		return len;
	}
	ListNode *rotateRight(ListNode *head, int k) {

		int len = countlist(head);
		if(len==0)
            return NULL;

        k %= len;
        if(k==0)
            return head;
		//cout << len << " " << k << "\n";
		ListNode *pfront = head;
		ListNode *ptail = head;
		ListNode *ppre = head;
		for (int i = 1; i < k; i++)
		{
			pfront = pfront->next;
		}
		while (pfront->next != NULL)
		{
			pfront = pfront->next;
			if (pfront->next == NULL)
				ppre = ptail;
			ptail = ptail->next;
		}
		//cout << pfront->val << " " << ptail->val<<" "<<ppre->val<<" \n";
		pfront->next = head;
		ppre->next = NULL;
		return ptail;
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
    int n,k;
    while(cin>>n>>k)
    {
        ListNode *start=new ListNode(0);
        ListNode *ts=start;
        for(int i=1;i<n;i++)
        {
            start->next=new ListNode(i);
            start=start->next;
        }
        printlist(ts);
        Solution *solution=new Solution();
        printlist(solution->rotateRight(ts,k));

    }
    return 0;
}
