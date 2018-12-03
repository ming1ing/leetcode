#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fp=head;
        if(fp==NULL) return false;
        ListNode *sp=head->next;
        while(sp&&fp)
        {
            fp=fp->next;
            sp=sp->next;
            if(sp==fp)
                return true;
            if(sp==NULL)
                return false;
            sp=sp->next;
            if(sp==fp)
                return true;
            if(sp==NULL)
                return false;
        }
        return false;
    }
};
int main()
{
    Solution *s=new Solution();
    ListNode *head =new ListNode(1);
    cout<<s->hasCycle(head)<<"\n";
    head->next=head;
    cout<<s->hasCycle(head)<<"\n";
    return 0;
}
