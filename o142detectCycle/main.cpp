#include <iostream>
#include<unordered_map>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head||!head->next) return NULL;
        ListNode *phead=head;
        ListNode *pnext=phead->next;
        unordered_map<ListNode*,int> mp;
        while(head)
        {
            if(mp.find(head)!=mp.end())
            {
                return head;
            }
            else
            {
                mp.insert(make_pair(head,1));
            }
            head=head->next;
        }
        return NULL;
    }
};
int main()
{
    int a[]={1};
    ListNode *head=new ListNode(1);
    ListNode *ph=new ListNode(2);
    head->next=ph;
    //ph->next=head;
    //head->next=head;
    Solution *s=new Solution();
    ListNode *res=s->detectCycle(head);
    if(res)
    cout<<res->val<<"\n";
    else
        cout<<"NULL\n";
    return 0;
}
