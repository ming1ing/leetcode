#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    int getlistlen(ListNode *head){
        int len=0;
        while(head)
        {
            head=head->next;
            len++;
        }
        return len;
    }
    ListNode *check(ListNode *headA, ListNode *headB)
    {
        while(headA)
        {
            if(headA==headB)
                return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=getlistlen(headA);
        int lenB=getlistlen(headB);
        if(lenA==lenB)
        {
            return check(headA,headB);
        }
        else if(lenA<lenB)
        {
            while(lenA<lenB)
            {
                headB=headB->next;
                lenB--;
            }
            return check(headA,headB);
        }
        else
        {
            while(lenA>lenB)
            {
                headA=headA->next;
                lenA--;
            }
            return check(headA,headB);
        }
        return NULL;
    }
};
ListNode* makeList(int *p,int len){
    if(len==0) return NULL;
    ListNode *head=new ListNode(p[0]);
    ListNode *th=head;
    for(int i=1;i<len;i++)
    {
        head->next=new ListNode(p[i]);
        head=head->next;
    }
    return th;
}
void printList(ListNode *head)
{
    while(head)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<"\n";
}
int main()
{
    int a[]={1,2,3};
    int b[]={2,3,4};
    int c[]={5,6,7};
    int d[]={3};
    ListNode *pa=makeList(a,sizeof(a)/sizeof(int));
    ListNode *pb=makeList(b,sizeof(b)/sizeof(int));
    Solution *s=new Solution();
    printList(s->getIntersectionNode(pa,pb));
    ListNode *pc=makeList(c,sizeof(c)/sizeof(int));
    ListNode *pd=makeList(d,sizeof(d)/sizeof(int));
    pd->next=pc;
    printList(s->getIntersectionNode(pc,pd));
    return 0;
}
