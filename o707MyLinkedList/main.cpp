#include <iostream>

using namespace std;
struct ListNode{
        int val;
        ListNode *next;
        ListNode(int x):val(x),next(NULL){}
    };
class MyLinkedList {
private:
    ListNode *head;
    int len;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head=NULL;
        len=0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(len==0)
            return -1;
        if(index>=len)
            return -1;
        ListNode *phead=head;
        for(int i=0;i<index;i++)
        {
            phead=phead->next;
        }
        return phead->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        len++;
        ListNode *phead=new ListNode(val);
        phead->next=head;
        head=phead;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        len++;
        ListNode *phead=head;
        if(!phead) phead=new ListNode(val);
        while(phead->next)
        {
            phead=phead->next;
        }
        phead->next=new ListNode(val);
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index>len||index<0) return ;
        len++;
        if(index==0)
        {
            ListNode *pnewhead=new ListNode(val);
            pnewhead->next=head;
            head=pnewhead;
            return ;
        }
        ListNode *phead=head;
        int temp=index;
        for(int i=0;i<index-1;i++)
        {
            phead=phead->next;
        }
        ListNode *pnext=phead->next;
        phead->next=new ListNode(val);
        phead->next->next=pnext;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index>=len||index<0) return ;
        len--;
        if(index==0)
        {
            ListNode *phead=head;
            head=head->next;
            delete phead;
            return ;
        }
        ListNode *phead=head;
        ListNode *thead=NULL;
        for(int i=0;i<index;i++)
        {
            thead=phead;
            phead=phead->next;
        }
        thead->next=phead->next;
        delete phead;
    }
};
int main()
{
    MyLinkedList *obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1,2);
    cout<<obj->get(1)<<"\n";
    obj->deleteAtIndex(1);
    cout<<obj->get(1)<<"\n";
    /*cout<<obj->get(0)<<"\n";
    obj->addAtIndex(1,2);
    cout<<obj->get(0)<<"\n";
    cout<<obj->get(1)<<"\n";
    obj->addAtIndex(0,1);
    cout<<obj->get(0)<<"\n";
    cout<<obj->get(1)<<"\n";*/
    return 0;
}
