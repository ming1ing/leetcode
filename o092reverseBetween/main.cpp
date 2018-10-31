#include <iostream>

using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *st=head;
        ListNode *se=head;

        for(int i=0;i<m-1;i++)
        {
            st=st->next;
        }
        for(int i=0;i<n-1;i++)
        {
            se=se->next;
        }

        ListNode *tail=NULL;
        if(se->next!=NULL)
            tail=se->next;
        if(m==1)
        {
            head=listrever(st,se);
            st->next=tail;
            return head;
        }
        else
        {
            ListNode *ss=head;
            for(int i=0;i<m-2;i++)
            {
                ss=ss->next;
            }
            ListNode *ts=listrever(st,se);
            ss->next=ts;
            st->next=tail;
            return head;
        }
    }
    ListNode * listrever(ListNode *start,ListNode *pend)
    {
        ListNode * ppre=NULL;
        ListNode *pnow=start;
        ListNode *pnext=pnow->next;
        while(1)
        {
            pnow->next=ppre;
            if(pnow==pend)
            {
                return pnow;
            }
            ppre=pnow;
            pnow=pnext;
            pnext=pnow->next;
        }
        return pnow;
    }
};

ListNode * makeList(int n)
{
    ListNode *s=NULL;
    ListNode *t=s;
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            s=new ListNode(i);
            t=s;
        }
        else{
            s->next=new ListNode(i);
              s=s->next;
        }

    }
    return t;
}
int main()
{   int n,m,x;
    while(cin>>m>>n>>x)
    {
        ListNode *start=makeList(x);
        printlist(start);
        Solution *solution=new Solution();

        ListNode *ss=solution->reverseBetween(start,m,n);
        printlist(ss);
    }

    //ListNode *ss=solution->listrever(start,NULL);
    //printlist(ss);
    return 0;
}

