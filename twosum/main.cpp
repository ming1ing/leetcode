#include <iostream>
#include<vector>
#include<map>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) :val(x),next(NULL) {}
};
class Solution
{
public:
    vector<int> twoSum(vector<int>& nums,int target)
    {
        vector<int> ans;
        map<int,int> map1;
        ans.clear();
        map1.clear();
        int len=nums.size();
        for(int i=0; i<len; i++)
        {
            map1.insert(map<int,int>::value_type(nums[i],i));
        }
        for(int i=0; i<len; i++)
        {
            map<int,int>::iterator it=map1.find(target-nums[i]);
            if(it==map1.end())
            {
                continue;
            }
            else
            {
                if(it->second==i)
                {
                    continue;
                }
                else
                {
                    ans.push_back(i);
                    ans.push_back(it->second);
                    break;
                }
            }

        }
        return ans;
    }
    ListNode* addTwoNumbers(ListNode* l1,ListNode* l2)
    {
        ListNode *res=new ListNode(0);
        ListNode *ans=res;
        int mark=0;
        while(l1!=NULL && l2!=NULL)
        {
            res->val=l1->val+l2->val+mark;
            if((l1->val+l2->val+mark)>=10)
            {
                mark=1;
                res->val%=10;
            }
            else
                mark=0;

            if((l1->next!=NULL)||(l2->next!=NULL))
            {
                res->next=new ListNode(0);
                res=res->next;
            }
            l1=l1->next;
            l2=l2->next;

        }
        while(l1!=NULL)
        {
            res->val=l1->val+mark;
            if((l1->val+mark)>=10)
            {
                mark=1;
                res->val%=10;
            }
            else
                mark=0;
            if(l1->next!=NULL){
            res->next=new ListNode(0);
            res=res->next;
            }
            l1=l1->next;

        }
        while(l2!=NULL)
        {
            res->val=l2->val+mark;
            if((l2->val+mark)>=10)
            {
                mark=1;
                res->val%=10;
            }
            else
                mark=0;
                if(l2->next!=NULL){
                res->next=new ListNode(0);
            res=res->next;}
            l2=l2->next;

        }
        if(mark==1)
        {
            res->next=new ListNode(1);
            res=res->next;
        }
        return ans;
    }
};
void print(ListNode *l)
{
    while(l!=NULL)
    {
        cout<<l->val<<" ";
        l=l->next;
    }
}
int main()
{
    Solution* ts=new Solution();
    /*vector<int> testa;
    vector<int> display;
    testa.push_back(2);
    testa.push_back(7);
    testa.push_back(11);
    testa.push_back(15);
    Solution* ts=new Solution();
    display.clear();
    display=ts->twoSum(testa,9);

    for(int i=0;i<(int)display.size();i++)
    {
        cout<<display[i]<<" ";
    }*/
    ListNode* start=new ListNode(3);
    ListNode*t1=start;
    start->next=new ListNode(7);
    start=start->next;
//    start->next=new ListNode(9);

    ListNode* start2=new ListNode(9);
    ListNode*t2 =start2;
   start2->next=new ListNode(2);
    start2=start2->next;
//    start2->next=new ListNode(4);
//    while(t1!=NULL)
//    {
//        cout<<t1->val<<" ";
//        t1=t1->next;
//    }
//    cout<<"\n";
//    while(t2!=NULL)
//    {
//        cout<<t2->val<<" ";
//        t2=t2->next;
//    }
    print(t1);
    cout<<" \n";
    print(t2);
    cout<<" \n";
    ListNode* res=  ts->addTwoNumbers(t1,t2);
    print(res);
    return 0;
}
