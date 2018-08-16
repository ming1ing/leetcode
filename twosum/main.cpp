#include <iostream>
#include<vector>
#include<map>
#include<cstring>
#include<string>
#include<climits>
#include<stack>
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
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        else
        {
            int temp=x;
            int numchange=0;
            while(x)
            {
                numchange*=10;
                numchange+=x%10;
                x/=10;
            }
            if(temp==numchange)
                return true;
            else
                return false;
        }
        return true;
    }
    bool isMatch(string s, string p){
        int len=s.length();
        int len2=p.length();
        int i,j;
        for(i=0,j=0;i<len&&j<len2;i++)
        {
            if(p[j]!='.'&&p[j]!='*')
            {
                if(p[j]!=s[i])
                {
                    return false;
                }
            }
            else if(p[j]=='.')
            {
                j++;continue;
            }
            else if(p[j]=='*')
            {
                if(s[i]!=p[j-1])
                {
                    j++;continue;
                }
                else
                {
                    continue;
                }
            }
        }
        if(i==len&&j==len2)
        return true;
        else
        {
            return false;
        }
    }
     int maxArea(vector<int>& height) {
            int len=height.size();
            int l=0,r=len-1;
            int ans=0;
            while(l<r)
            {
                int t=min(height[l],height[r]);
                t*=(r-l);
                if(t>ans)
                    ans=t;
                if(height[l]<height[r])
                {
                    l++;
                }
                else{
                    r--;
                }
            }
            return ans;
    }
    string intToRoman(int num) {
        string s="";
        int t=num/1000;
        for(int i=0;i<t;i++)
        {
            s+="M";
        }
        int h=(num%1000)/100;
        switch (h)
            {
               case 9: s+="CM";break;
               case 8: s+="DCCC";break;
               case 7: s+="DCC";break;
               case 6: s+="DC";break;
               case 5: s+="D";break;
               case 4: s+="CD";break;
               case 3: s+="CCC";break;
               case 2: s+="CC";break;
               case 1: s+="C";break;
               default:break;
            }
            int ten=(num%100)/10;
             switch (ten)
            {
               case 9: s+="XC";break;
               case 8: s+="LXXX";break;
               case 7: s+="LXX";break;
               case 6: s+="LX";break;
               case 5: s+="L";break;
               case 4: s+="XL";break;
               case 3: s+="XXX";break;
               case 2: s+="XX";break;
               case 1: s+="X";break;
               default:break;
            }
            int g=(num%10);
             switch (g)
            {
               case 9: s+="IX";break;
               case 8: s+="VIII";break;
               case 7: s+="VII";break;
               case 6: s+="VI";break;
               case 5: s+="V";break;
               case 4: s+="IV";break;
               case 3: s+="III";break;
               case 2: s+="II";break;
               case 1: s+="I";break;
               default:break;
            }
        return s;
    }
    int romanToInt(string s) {
        int mark[20];
        for(int i=0;i<20;i++)
        {
            mark[i]=0;
        }
        int ans=0;
        int len=s.length();
        for(int i=0;i<len;i++)
        {
            if(s[i]=='I'&&s[i+1]=='V')
            {
                ans+=4;mark[i]=1;mark[i+1]=1;
            }
            else if(s[i]=='I'&&s[i+1]=='X')
            {
                ans+=9;mark[i]=1;mark[i+1]=1;
            }
             else if(s[i]=='X'&&s[i+1]=='L')
            {
                ans+=40;mark[i]=1;mark[i+1]=1;
            }
             else if(s[i]=='X'&&s[i+1]=='C')
            {
                ans+=90;mark[i]=1;mark[i+1]=1;
            }
             else if(s[i]=='C'&&s[i+1]=='D')
            {
                ans+=400;mark[i]=1;mark[i+1]=1;
            }
             else if(s[i]=='C'&&s[i+1]=='M')
            {
                ans+=900;mark[i]=1;mark[i+1]=1;
            }
        }
        for(int i=0;i<len;i++)
        {
            if(mark[i]>0)
            {
                continue;
            }
            switch(s[i])
            {
                case 'I':ans+=1;break;
                case 'V':ans+=5;break;
                case 'X':ans+=10;break;
                case 'L':ans+=50;break;
                case 'C':ans+=100;break;
                case 'D':ans+=500;break;
                case 'M':ans+=1000;break;
            }
        }
        return ans;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==0)
            return "";
        int shortlen=1000000000;
        for(int i=0;i<n;i++)
        {
            if(strs[i].length()<shortlen)
                shortlen=strs[i].length();
        }
        string strans="";
        for(int i=0;i<strs[i].length();i++)
        {
            char s=strs[0][i];
            int mark=0;
            for(int j=1;j<n;j++)
            {
                if(strs[j][i]!=s)
                {
                    mark=1;
                    break;
                }
            }
            if(mark==1)
            {
                break;
            }
            strans+=s;
        }
        return strans;
    }
    vector<vector<int> > threeSum(vector<int>& nums) {
        map<int,int> mark;
        mark.clear();
        for(int i=0;i<nums.size();i++)
        {
            mark[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<0;j++)
            {
                ;
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        string s[10];
        s[0]="";
        s[1]="";
        s[2]="abc";
        s[3]="def";
        s[4]="ghi";
        s[5]="jkl";
        s[6]="mno";
        s[7]="pqrs";
        s[8]="tuv";
        s[9]="wxyz";
        vector<string> ans;
        ans.clear();
        int len=digits.length();
        for(int i=0;i<len;i++)
        {
            string t="";
            for(int j=0;j<s[i].length();j++)
            {
                int num=digits[i]-'0';
                t+=s[num][j];
            }
        }
    }
    bool isValid(string s) {
        if(s.length()%2==1)
            return false;
        stack<char> ans;
        while(!ans.empty())
        {
            ans.pop();
        }
        int len=s.length();
        for(int i=0;i<len;i++)
        {
            if(s[i]=='('||s[i]=='['||s[i]=='{')
                {
                    ans.push(s[i]);
                }
            else
            {
                if(s[i]==')')
                {
                    if(ans.empty())
                    {
                        return false;
                    }
                    if(ans.top()=='(')
                    {
                        ans.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else if(s[i]==']')
                {
                    if(ans.empty())
                    {
                        return false;
                    }
                    if(ans.top()=='[')
                    {
                        ans.pop();
                    }
                    else
                        return false;
                }
                else if(s[i]=='}')
                {
                    if(ans.empty())
                    {
                        return false;
                    }
                    if(ans.top()=='{')
                    {
                        ans.pop();
                    }
                    else
                        return false;
                }
            }
        }
        if(ans.empty())
            return true;
        else
            return false;
    }
     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         if(l1==NULL)
            return l2;
         if(l2==NULL)
            return l1;
            if(l1->val<l2->val)
            {
                l1->next=mergeTwoLists(l1->next,l2);
                return l1;
            }
            else
            {
                l2->next=mergeTwoLists(l1,l2->next);
                return l2;
            }
    }
    int removeDuplicates(vector<int>& nums) {

        int len=nums.size();
        if(len==1)
            return 1;
        int anslen=0;
        for(int i=0;i<len;i++)
        {

            for(int j=i+1;j<len;j++)
            {
                int t=nums[i],t2=nums[j];

                if(nums[i]==nums[j])
                {
                    if(j==len-1){
                        nums[anslen++]=nums[i];
                        i=j;
                        break;
                    }
                    continue;
                }
                else
                {
                    nums[anslen++]=nums[i];
                    i=j-1;
                    if(j==len-1)
                    {
                       nums[anslen++]=nums[j];
                    }
                    break;
                }
            }
        }

        return anslen;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode *start=new ListNode(0);
        start->next=head;
        ListNode *pfront=start;
        ListNode *tfront=start;
        ListNode *p=start;
        for(int i=0;i<n-1;i++)
        {
            pfront=pfront->next;
        }
        while(pfront->next!=NULL)
        {
            pfront=pfront->next;
            tfront=tfront->next;
            if(pfront->next==NULL)
                p->next=tfront->next;
            else
                p=p->next;
        }
        return start->next;
    }
    int removeElement(vector<int>& nums, int val) {
            int len=nums.size();
            int anslen=0;
            for(int i=0;i<len;i++)
            {
                if(nums[i]==val)
                    continue;
                else
                {
                    nums[anslen++]=nums[i];
                }
            }
            return anslen;
    }
    string countAndSay(int n){
        vector<string> ans(n+2);
        string sss="1";
        ans[0]=sss;
        ans[1]=sss;
        for(int i=2;i<=n;i++)
        {
            int len=ans[i-1].size();
            for(int j=0;j<len;j++)
            {
                char t=ans[i-1][j];
                int num=0;
                for(int k=j;k<len;k++)
                {
                    if(ans[i-1][k]==ans[i-1][j])
                    {
                        num++;
                        if(k==(len-1))
                        {
                            ans[i].push_back((num+'0'));
                            ans[i].push_back(ans[i-1][j]);
                           // cout<<ans[i]<<"\n";
                            num=0;
                            j=k;
                            break;
                        }
                    }
                    else
                    {
                        ans[i].push_back((num+'0'));
                        ans[i].push_back(ans[i-1][j]);
                        num=0;
                        j=k-1;
                        break;
                    }
                }
            }
        }
        return ans[n];
    }
    int searchInsert(vector<int>& nums, int target) {
        int l=0,r=nums.size();
        if(target<nums[l])
            return l;
        if(target>nums[r-1])
            return r;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(target==nums[mid])
                return mid;
            else if(target<nums[mid])
            {
                r=mid-1;
            }
            else if(target>nums[mid])
            {
                l=mid+1;
            }
        }
        return l;
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
//    vector<int> h;
//    h.clear();
//    h.push_back(1);
//    h.push_back(8);
//    h.push_back(6);
//    h.push_back(2);
//    h.push_back(5);
//    h.push_back(4);
//    h.push_back(8);
//    h.push_back(3);
//    h.push_back(7);
//    cout<<ts->maxArea(h)<<"\n";
//vector<string > test;
//test.clear();
//test.push_back("flower");
//test.push_back("flow");
//test.push_back("flight");
//cout<<ts->longestCommonPrefix(test)<<"\n";
//test.clear();
//test.push_back("dog");
//test.push_back("racecar");
//test.push_back("car");
//cout<<ts->longestCommonPrefix(test)<<"\n";
//ListNode *start=new ListNode(1);
//ListNode *s1=start;
// for(int i=1;i<10;i++)
// {
//     start->next=new ListNode(i+1);
//     start=start->next;
// }
// print(s1);
// ListNode *start2=new ListNode(2);
//ListNode *s2=start2;
// for(int i=2;i<=5;i++)
// {
//     start2->next=new ListNode(i*2);
//     start2=start2->next;
// }
// print(s2);
// ListNode *ansp=ts->mergeTwoLists(s1,s2);
// print(ansp);
//vector<int> test;
//test.clear();
//for(int i=0;i<4;i++)
//{
//    test.push_back(1);
//}
//for(int i=0;i<4;i++)
//    cout<<test[i]<<" ";
//    int len=ts->removeDuplicates(test);
//cout<<len<<"\n";
//for(int i=0;i<len;i++)
//    cout<<test[i]<<" ";
//ListNode* start=new ListNode(1);
//ListNode *ps=start;
//for(int i=2;i<=3;i++)
//{
//    start->next=new ListNode(i);
//    start=start->next;
//}
//print(ps);
//ListNode *ans=ts->removeNthFromEnd(ps,2);
//print(ans);
//vector<int> test;
//test.clear();
//test.push_back(3);
//test.push_back(2);
//test.push_back(3);
//test.push_back(3);
//cout<<ts->removeElement(test,3)<<"\n";
vector<int> test;
test.clear();
test.push_back(1);
test.push_back(3);
test.push_back(5);
test.push_back(6);

    string s,p;
    int n;
    while(cin>>n)
    {
//        cout<<ts->lengthOfLongestSubstring(s)<<"\n";
//        cout<<"\n"<<ts->convert(s,n)<<"\n";
//    cout<<ts->reverse(n)<<"\n";
//        cout<<(bool)ts->isMatch(s,p)<<"\n";
//cout<<ts->intToRoman(n)<<"\n";
// cout<<ts->romanToInt(s)<<"\n";
//cout<<ts->isValid(s)<<"\n";
//cout<<ts->countAndSay(n)<<"\n";
cout<<ts->searchInsert(test,n)<<"\n";
    }
    return 0;
}
//9223372036854775808
