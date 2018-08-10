#include <iostream>
#include<vector>
#include<map>
#include<cstring>
#include<string>
#include<climits>
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
            if(l1->next!=NULL)
            {
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
            if(l2->next!=NULL)
            {
                res->next=new ListNode(0);
                res=res->next;
            }
            l2=l2->next;

        }
        if(mark==1)
        {
            res->next=new ListNode(1);
            res=res->next;
        }
        return ans;
    }
    int lengthOfLongestSubstring(string s)
    {

        int mark[256];
        memset(mark,0,sizeof(mark));
        int len=s.length();
        int ans=0;
        int maxn=0;
        for(int l=0,r=0; (l<=r)&&(r<len);)
        {
            int index=s[r];
            while(mark[index]==0)
            {
                ans++;
                mark[index]++;
                r++;
                if(ans>maxn)
                    maxn=ans;
                if(r>=len)
                    break;
                index=s[r];
            }
            index=s[l];
            mark[index]--;
            l++;
            ans--;

        }
        return maxn;
    }
    string longestPalindrome(string s)
    {
        int len=s.length();
        int maxn=0,l=0,r=0;
        int temp=1;
        for(int i=0; i<len; i++)
        {
            int tl=i-1,tr=i+1;
            temp=0;
            while(tl>=0&&tr<len)
            {
                if(s[tl]==s[tr])
                {

                    temp+=2;
                    if(temp>maxn)
                    {
                        maxn=temp;
                        l=tl;
                        r=tr;
                    }
                    tl--;
                    tr++;
                }
                else
                {
                    break;
                }
            }

        }
        for(int i=0; i<len; i++)
        {
            int tl=i,tr=i+1;
            temp=0;
            while(tl>=0&&tr<len)
            {
                if(s[tl]==s[tr])
                {

                    temp+=2;
                    if(temp>maxn)
                    {
                        maxn=temp;
                        l=tl;
                        r=tr;
                    }
                    tl--;
                    tr++;
                }
                else
                {
                    break;
                }
            }
        }
        // cout<<maxn<<" "<<l<<" "<<r;

        return s.substr(l,r-l+1);
    }
    string convert(string s, int numRows)
    {
        if(numRows==1)
            return s;
        string strres;
        int len=s.length();
        for(int i=1; i<=numRows; i++)
        {
            for(int j=i-1; j<len;)
            {
                //cout<<s[j];
                strres+=s[j];
                if((i!=1)&&(i!=numRows))
                {
                    if(j+(numRows-i)*2<len)
                    {
                        //cout<<s[j+(numRows-i)*2];
                        strres+=s[j+(numRows-i)*2];
                    }
                }

                j+=(numRows-1)*2;
            }
            //cout<<"\n";
        }

        return strres;
    }
    int reverse(int x)
    {
        long  ans=0;
        while(x)
        {
            ans*=10;
            ans+=x%10;
            x/=10;
            cout<<ans<<" "<<x%10<<"\n";
        }
        if(ans>2147483647||ans<-2147483648)
            return 0;
        else
            return ans;
    }
    int myAtoi(string str)
    {
        // cout<<str<<"\n";
        int len=str.length();
        int i=0;
        while(str[i]==' ')
        {
            i++;
            if(i>=len)
                return 0;
        }
        if((str[i]>'9')&&(str[i]<'0')&&(str[i]!='-'))
            return 0;
        int mark=0;
        long long ans=0;
        for(; i<len; i++)
        {
            if(str[i]=='+'&&mark==0)
            {
                mark=2;continue;
            }
            else if(str[i]=='-'&&mark==0)
            {
                mark=1;continue;
            }
            else if(str[i]=='-'&&mark>0)
            {
                  if(mark==1)
                {
                    if(ans>2147483648)
                        ans=-2147483648;
                    else
                        ans=-ans;
                }
                else
                {
                    if(ans>2147483647)
                        ans=2147483647;
                }
                return ans;
            }
            else if(str[i]=='+'&&mark>0)
            {
                  if(mark==1)
                {
                    if(ans>2147483648)
                        ans=-2147483648;
                    else
                        ans=-ans;
                }
                else
                {
                    if(ans>2147483647)
                        ans=2147483647;
                }
                return ans;
            }
            else if(str[i]>='0'&&str[i]<='9')
            {
                ans*=10;
                ans+=str[i]-'0';
                if(mark==0)
                    mark=2;
                if(ans>2147483647&&(mark==2||mark==0))
                    return 2147483647;
                if(ans>2147483648)
                {
                    if(mark==1)
                    {
                        return -2147483648;
                    }
                }
            }
            else
            {
                if(mark==1)
                {
                    if(ans>2147483648)
                        ans=-2147483648;
                    else
                        ans=-ans;
                }
                else
                {
                    if(ans>2147483647)
                        ans=2147483647;
                }

                return ans;
            }
        }
        if(mark==1)
        {

            if(ans>2147483648)
                ans=-2147483648;
            else
                ans=-ans;
        }
        else
        {
            if(ans>2147483647)
                ans=2147483647;
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
//    ListNode* start=new ListNode(3);
//    ListNode*t1=start;
//    start->next=new ListNode(7);
//    start=start->next;
//    start->next=new ListNode(9);

//    ListNode* start2=new ListNode(9);
//    ListNode*t2 =start2;
//   start2->next=new ListNode(2);
//    start2=start2->next;
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
//    print(t1);
//    cout<<" \n";
//    print(t2);
//    cout<<" \n";
//    ListNode* res=  ts->addTwoNumbers(t1,t2);
//    print(res);
    string s;
    int n;
    while(cin>>s)
    {
//        cout<<ts->lengthOfLongestSubstring(s)<<"\n";
//        cout<<"\n"<<ts->convert(s,n)<<"\n";
//    cout<<ts->reverse(n)<<"\n";
        cout<<ts->myAtoi(s)<<"\n";
    }
    return 0;
}
//9223372036854775808
