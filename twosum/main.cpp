#include <iostream>
#include<vector>
#include<map>
#include<cstring>
#include<string>
#include<climits>
#include<stack>
#include<algorithm>
#include<set>
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
    double myPow(double x, int n) {
        int mark=0;
        if(n<0)
        {
            mark=1;
            n=-n;
        }
        double ans=1.0,a=x;
        while(n)
        {
            if(n&1)
            {
                ans*=a;
            }
            a*=a;
            n/=2;
        }
        if(mark==1)
            ans=1.0/ans;
        return ans;
    }
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        map<string,int> p;
        vector<vector<string> > ans;
        p.clear();
        ans.clear();
        int len=strs.size();
        for(int i=0;i<len;i++)
        {
            string t=strs[i];
            sort(t.begin(), t.end());
            if(p.find(t)==p.end())
            {
                int l=ans.size();
                ans.resize(l+1);
                ans[l].push_back(strs[i]);

                p.insert(map<string,int>::value_type(t,ans.size()-1));
            }
            else
            {
                int num=p[t];
                ans[num].push_back(strs[i]);

            }
        }

        return ans;
    }
    void rotate(vector<vector<int> >& matrix) {
        int n=matrix.size();
        for(int i=0;i<n/2;i++)
        {
            for(int j=0;j<(n+1)/2;j++)
            {
                swap(matrix[i][j],matrix[j][n-1-i]);
                swap(matrix[i][j],matrix[n-1-i][n-1-j]);
                swap(matrix[i][j],matrix[n-1-j][i]);
            }
        }
    }
    int trap(vector<int>& height) {
        vector<int> left;
        left.clear();
        vector<int> right;
        right.clear();
        int len=height.size();
        if(len==0)
            return 0;
        left.push_back(height[0]);
        int lmaxn=height[0];
        for(int i=1;i<len;i++)
        {
            if(height[i]>lmaxn)
                lmaxn=height[i];
            left.push_back(lmaxn);
        }
        right.push_back(height[len-1]);
        int rmaxn=height[len-1];
        for(int i=len-2;i>=0;i--)
        {
            if(height[i]>rmaxn)
                rmaxn=height[i];
            right.push_back(rmaxn);
        }

        int nans=0;
        for(int i=0;i<len;i++)
        {
            nans+=min(left[i],right[len-1-i])-height[i];
        }
        return nans;
    }
     ListNode* swapPairs(ListNode* head) {
         if(head==NULL)
            return head;
        ListNode *l1=head;
        ListNode *ans=NULL;
        if(l1->next==NULL)
            ans=head;
        else
            ans=head->next;
        while(l1!=NULL)
        {
            ListNode *l2=l1->next;
            if(l2==NULL)
                break;
            ListNode *l3=l2->next;
            l2->next=l1;
            if(l3==NULL||l3->next==NULL)
            {
                l1->next=l3;
                break;
            }
            /*if(l3->next==NULL)
            {
                l1->next=l3;
                break;
            }*/
            if(l3->next!=NULL)
            {
                l1->next=l3->next;
                l1=l3;
            }

        }
        return ans;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1)
            return head;
        ListNode *l1=head;
        if(l1==NULL)
            return NULL;
        ListNode *l2=l1->next;
        if(l2==NULL)
            return head;

        while(l2!=NULL)
        {
            //ListNode *l3=l2->next;
            l1->next=l2->next;
            l2->next=head;
            head=l2;
            l2=l1->next;
        }
        return head;
    }


    void dfs(vector<int>& nums,int id,vector<vector<int> >& ans,vector<int>& a,vector<int>& mark)
    {
        int len=nums.size();
        if(id>=len)
        {
            vector<int> temp;
            temp.clear();
            for(int i=0;i<nums.size();i++)
            {
                temp.push_back(a[i]);
            }
            ans.push_back(temp);
            temp.clear();
            return ;
        }
        for(int i=0;i<len;i++)
        {
            if(mark[i]>0)
                continue;
            a[id]=nums[i];
            mark[i]++;
            dfs(nums,id+1,ans,a,mark);
            mark[i]=0;
        }
    }

    vector<vector<int> > permute(vector<int>& nums) {
        vector<int> a;
        a.resize(20);
        vector<int> mark;
        mark.resize(20);
        int len=nums.size();
        vector<vector <int> > ans;
        ans.clear();

       for(int i=0;i<20;i++)
        mark[i]=0;
        dfs(nums,0,ans,a,mark);

        return ans;
    }
    void dfs2(vector<int>& nums,int id,set<vector<int> >& ans,vector<int>& a,vector<int>& mark)
    {
        int len=nums.size();
        if(id>=len)
        {
            vector<int> temp;
            temp.clear();
            for(int i=0;i<nums.size();i++)
            {
                temp.push_back(a[i]);
            }
            ans.insert(temp);
            temp.clear();
            return ;
        }
        for(int i=0;i<len;i++)
        {
            if(mark[i]>0)
                continue;
            a[id]=nums[i];
            mark[i]++;
            dfs2(nums,id+1,ans,a,mark);
            mark[i]=0;
        }
    }
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<int> a;
        a.resize(20);
        vector<int> mark;
        mark.resize(20);
        int len=nums.size();
        set<vector <int> > ans;
        vector<vector <int> >res;
        res.clear();
        ans.clear();

       for(int i=0;i<20;i++)
        mark[i]=0;
        dfs2(nums,0,ans,a,mark);
        //cout<<ans.size()<<"\n";
        for(set<vector<int> >::iterator it=ans.begin();it!=ans.end();it++)
        {
            for(int j=0;j<(*it).size();j++)
            {
               // cout<<(*it)[j]<<" ";
            }
            res.push_back((*it));
            //cout<<"\n";
        }
        return res;
    }
    void dfs3(vector<string>& ans,string s,int left,int right){
            if(left==0&&right==0)
            {
                //cout<<"s4"<<s<<"\n";
                ans.push_back(s);
                return ;
            }
            else
            {
                if(left==right)
                {
                    s+='(';
                    //cout<<"s1:"<<s<<"\n";
                    dfs3(ans,s,left-1,right);
                }
                if(left<right)
                {
                    s+=')';
                    //cout<<"s2:"<<s<<"\n";
                    dfs3(ans,s,left,right-1);
                    s=s.substr(0,s.length()-1);

                }
                if(left<right)
                {
                     if(left>0){
                    s+='(';
                    //cout<<"s3:"<<s<<"\n";
                    dfs3(ans,s,left-1,right);
                    s=s.substr(0,s.length()-1);
                    }
                }

            }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        ans.clear();
        string s="";
        dfs3(ans,s,n,n);
        return ans;
    }
     int divide(int dividend, int divisor) {
         int mark=1;
         long long Ldividend=dividend;
         long long Ldivisor=divisor;
            if(dividend<0)
            {
                mark*=-1;
                Ldividend=-Ldividend;
            }
            if(divisor<0)
            {
                mark*=-1;
                Ldivisor=-Ldivisor;
            }
            if(Ldividend<Ldivisor)
            {
                return 0;
            }
            long long ans=0;
            while(Ldividend>=Ldivisor)
            {
                long long  temp=1;
                long long a=Ldivisor;
                while(Ldividend>=a)
                {
                    temp<<=1;
                    a<<=1;
                }
                Ldividend-=a>>1;
                ans+=temp>>1;
            }
            ans*=mark;
            if(ans>=2147483648)
                ans=2147483647;
            return ans;
    }
    void dfs4(vector<string>& ans,const vector<string>& numstochar,string temp,const string &digits,int id){

        int len=digits.length();
        if(id>=len)
        {
            ans.push_back(temp);
            return ;
        }
        int t=digits[id]-'0';
        for(int i=0;i<numstochar[t].size();i++)
        {
            temp+=numstochar[t][i];
            dfs4(ans,numstochar,temp,digits,id+1);
            temp.erase(temp.end()-1);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        ans.clear();
        if(digits.size()==0)
            return ans;
        vector<string> numstochar(10);
        numstochar[0]="";
        numstochar[1]="";
        numstochar[2]="abc";
        numstochar[3]="def";
        numstochar[4]="ghi";
        numstochar[5]="jkl";
        numstochar[6]="mno";
        numstochar[7]="pqrs";
        numstochar[8]="tuv";
        numstochar[9]="wxyz";

        string temp="";

        dfs4(ans,numstochar,temp,digits,0);
        return ans;
    }
    int longestValidParentheses(string s) {
        int len=s.length();
        stack<int> stack1;
        stack<int> id;
        vector<int> mark(len+2);
        for(int i=0;i<len;i++)
        {
            if(s[i]=='(')
            {
                stack1.push(s[i]);
                id.push(i);
            }
            else if(s[i]==')')
            {
                if(stack1.empty()||stack1.top()==')')
                {
                    stack1.push(s[i]);
                    id.push(i);
                }
                else
                {
                    if(stack1.top()=='(')
                    {
                        stack1.pop();
                        id.pop();
                    }
                }
            }
        }
        vector<int> res;
        int ans=0;
        res.push_back(len);
        while(!id.empty())
        {
            //cout<<"id"<<id.top()<<"\n";
            res.push_back(id.top());
            id.pop();
        }
        res.push_back(-1);
        for(int i=0;i<res.size()-1;i++)
            {
                int t=res[i]-res[i+1]-1;
                if(t>ans)
                    ans=t;
                cout<<res[i]<<" ";
            }
            cout<<"\n";
            return ans;

    }
    int jump(vector<int>& nums) {
        int len=nums.size();

        vector<int> mark(len+2);
        mark[0]=0;
        for(int i=1;i<len;i++)
        {
            mark[i]=len+2;
        }
        //mark[len-1]=0;
        int mark1=0;
        int ans=0;
        for(int i=0;i<len;i++)
        {
            if(nums[i]<nums[i-1]&&i>0)
                continue;
            for(int j=1;j<=nums[i];j++)
            {

                if((i+j)>(len-1))
                    break;

               if(mark[i]+1<mark[i+j])
                mark[i+j]=mark[i]+1;

                if((i+j)==len-1)
                {
                    mark1=1;
                    ans=mark[len-1];
                    break;
                }

            }
            if(mark1==1)
                break;
        }
        return ans;
    }

    int search1(vector<int>& nums, int target) {
        int len=nums.size();
        if(len==0)
            return -1;
        if(target<nums[0]&&target>nums[len-1])
        {
            return -1;
        }
        int l=0,r=len-1;
        if(target==nums[l])
            return l;
        if(target==nums[r])
            return r;
        while(l<r)
        {
            int mid=(l+r)/2;
            if(nums[mid]>nums[l])
            {
                l=mid;
            }
            else
            {
                r=mid;
            }
        }
        int ans=-1;
        int split=l;
        cout<<"split"<<split<<"\n";
        if(target>nums[0])
        {
            l=0,r=split;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(target==nums[mid])
                {
                    return mid;
                }
                if(target>nums[mid])
                {
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
        }
        else
        {
            l=split+1,r=len-1;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(target==nums[mid])
                {
                    return mid;
                }
                if(target>nums[mid])
                {
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
        }
        return ans;
    }
    int strStr(string haystack, string needle) {
        int len=haystack.length();
        int len2=needle.length();
        if(len2==0)
            return 0;
        if(len<len2)
            return -1;
        int ans=-1;
        vector<int> next;
        next.clear();
        next.resize(len2+2);
        int k=0;
        for(int q=1;q<=len2;q++)
        {
            while(k>0&&needle[k]!=needle[q])
                 k=next[k-1];
            if(needle[k]==needle[q])
                k=k+1;
            next[q]=k;
        }
         int n,m;
    n=len;
    m=len2;
   // makenext();
    for(int i=0,q=0;i<n;i++)
    {
        while(q>0&&needle[q]!=haystack[i])
            q=next[q-1];
        if(needle[q]==haystack[i])
            q=q+1;
        if(q==m)
            return i-m+1;
        //q=next[q-1];
    }
    return -1;
        /*for(int i=0;i<len-len2;i++)
        {
            int mark=0;
            int t=i;
            for(int j=0;j<len2;j++)
            {
                if(haystack[t]==needle[j])
                    {t++;mark++;}
                else
                    break;
            }
            if(mark==len2)
            {
                ans=i;
             break;
             }
        }
        return ans;*/
    }
    void dfs5(vector<int>& candidates,vector<int>& mark,set<vector<int> > &ans,int target)
    {
        if(target==0)
        {
           // sort(mark.begin(),mark.end());
           vector<int> temp;
           temp.clear();

            for(int i=0;i<mark.size();i++)
            {
               // cout<<mark[i]<<" ";
                temp.push_back(mark[i]);
            }
            //cout<<"\n";
            sort(temp.begin(),temp.end());
            ans.insert(temp);
            temp.clear();
            return ;
        }
        else if(target<0)
        {
            return ;
        }
        else
        {
            for(int i=0;i<candidates.size();i++)
            {
                if((target-candidates[i])>=0)
                {
                    mark.push_back(candidates[i]);
                    dfs5(candidates,mark,ans,target-candidates[i]);
                    mark.pop_back();
                }
                else
                    continue;
            }
        }
    }
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
            set<vector<int> > ans;
            ans.clear();
            vector<int> mark;
            mark.clear();
            vector<vector<int> > res;
            res.clear();
            dfs5(candidates,mark,ans,target);
            for(set<vector<int> >::iterator it=ans.begin();it!=ans.end();it++)
            {
                res.push_back(*it);
            }
            return res;
    }
    void nextPermutation(vector<int>& nums) {
        int len=nums.size();
        int id=0;
        for(int i=0;i<nums.size();i++)
        {
            cout<<nums[i]<<" ";
        }
        cout<<"\n";
        for(int i=len-1;i>0;i--)
        {
            if(nums[i]>nums[i-1])
            {
                id=i;
                break;
            }
        }
        cout<<id<<"\n";
        if(id==0)
        {
            std::reverse(nums.begin(),nums.end());

           // return ;
        }
        else
        {
            for(int i=len-1;i>=id;i--)
            {
                if(nums[i]>nums[id-1])
                {
                    swap(nums[i],nums[id-1]);
                    break;
                }
            }
            sort(nums.begin()+id,nums.end());
        }
         for(int i=0;i<nums.size();i++)
        {
            cout<<nums[i]<<" ";
        }
        cout<<"\n";
    }
    void dfs6(vector<int>& candidates,int target,vector<int>& mark,set<vector<int> > & ans)
    {
        if(target==0)
        {
            vector<int> t;
            t.clear();
            for(int i=0;i<candidates.size();i++)
            {
                if(mark[i]==1)
                t.push_back(candidates[i]);
            }
            sort(t.begin(),t.end());
            ans.insert(t);
            t.clear();
            return ;
        }
        else if(target<0)
        {
            return ;
        }
        for(int i=0;i<candidates.size();i++)
        {
            if(mark[i]==0)
            {
                if(target-candidates[i]>=0)
                {
                    mark[i]=1;
                    dfs6(candidates,target-candidates[i],mark,ans);
                    mark[i]=0;
                }
            }
        }
    }
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        int len=candidates.size();
        vector<int> mark(len+1,0);
        vector<vector<int> > res;
        res.clear();
        set<vector<int> > ans;
        ans.clear();
        dfs6(candidates,target,mark,ans);
        for(set<vector<int> >::iterator it=ans.begin();it!=ans.end();it++)
        {
            res.push_back(*it);
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int len=nums.size();
        int l=0,r=len-1;
        int lans=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(nums[mid]==target)
            {
                if(mid==0)
                {
                    lans=0;
                    break;
                }
                if(nums[mid-1]==target)
                {
                    r=mid-1;
                    continue;
                }
                else
                {
                    lans=mid;
                    break;
                }
            }
            if(nums[mid]<target)
            {
                l=mid+1;
            }
            else if(nums[mid]>target)
            {
                r=mid-1;
            }
        }

        l=0,r=len-1;
        int rans=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(nums[mid]==target)
            {
                if(mid==(len-1))
                {
                    rans=len-1;
                    break;
                }
                if(nums[mid+1]==target)
                {
                    l=mid+1;
                    continue;
                }
                else
                {
                    rans=mid;
                    break;
                }
            }
            if(nums[mid]<target)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        vector<int> res;
        res.clear();
        res.push_back(lans);
        res.push_back(rans);
        cout<<lans<<" "<<rans<<" \n";
        return res;
    }
    int firstMissingPositive(vector<int>& nums) {
  int len=nums.size();
       for(int i=0;i<len;)
       {

           if(nums[i]==(i+1))
            i++;
           else
           {
               int t=nums[i];
               if(nums[i]>=1&&nums[i]<=len&&nums[t-1]!=nums[i])
               {
                   swap(nums[i],nums[t-1]);
               }
               else
                i++;
           }
       }
        for(int i=0;i<len;i++)
       {
           cout<<nums[i]<<" ";
       }
       for(int i=0;i<len;i++)
       {
           if(nums[i]!=i+1)
            return i+1;
       }
        return len+1;
    }
    string multiply(string num1, string num2) {
        int len=num1.size();
        int len2=num2.size();
        int a[210];
        memset(a,0,sizeof(a));
        std::reverse(num1.begin(),num1.end());
        std::reverse(num2.begin(),num2.end());
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<len2;j++)
            {
                a[i+j]=a[i+j]+(num1[i]-'0')*(num2[j]-'0');
            }
        }
        for(int i=0;i<len+len2;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<"\n";
        int mark=0;
        for(int i=0;i<len+len2;i++)
        {
            a[i]=a[i]+mark;
            mark=a[i]/10;
            a[i]%=10;
        }
        for(int i=0;i<len+len2;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<"\n";
        string ans="";
        int i=len+len2;
        while(a[i]==0&&i!=0)
        {
            i--;
        }
        for(;i>=0;i--)
        {

            ans+=(a[i]+'0');
        }
        cout<<ans;
        return ans;
    }
     bool isValidSudoku(vector<vector<char>>& board) {
        int hor[10][10];
        int vet[10][10];
        int sq[10][10];
        memset(hor,0,sizeof(hor));
        memset(vet,0,sizeof(vet));
        memset(sq,0,sizeof(sq));
        bool mark=true;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                int t=0;
                if(board[i][j]>='0'&&board[i][j]<='9')
                {
                    t=board[i][j]-'0';
                    hor[i][t]++;
                    if(hor[i][t]>1)
                        mark=false;
                    vet[j][t]++;
                    if(vet[j][t]>1)
                        mark=false;
                    sq[i/3*3+j/3][t]++;
                    if(sq[i/3*3+j/3][t]>1)
                        mark=false;
                        if(mark==false)
                            return false;
                }

            }
        }
        return mark;
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
    {


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
//vector<int> test;
//test.clear();
//test.push_back(1);
//test.push_back(3);
//test.push_back(5);
//test.push_back(6);
//vector<string > strs;
//strs.clear();
//strs.push_back("eat");
//strs.push_back("tea");
//strs.push_back("tan");
//strs.push_back("ate");
//strs.push_back("nat");
//strs.push_back("bat");
//ts->groupAnagrams(strs);
//  vector< vector<int > > test;
//vector<int> test;
//test.clear();
//test.push_back(0);
//test.push_back(1);
//test.push_back(0);
//test.push_back(2);
//test.push_back(1);
//test.push_back(0);
//test.push_back(1);
//test.push_back(3);
//test.push_back(2);
//test.push_back(1);
//test.push_back(2);
//test.push_back(1);
//cout<<ts->trap(test)<<"\n";
    }
//ListNode *head=new ListNode(1);
 vector<int> test;
 test.clear();

   /* test.push_back(4);
    test.push_back(5);
    test.push_back(6);
     test.push_back(7);
     test.push_back(0);
      test.push_back(1);
     test.push_back(2);*/
//      test.push_back(5);
//       test.push_back(7);
//    test.push_back(7);
//    test.push_back(8);
//       test.push_back(8);
//    test.push_back(10);
    //test.push_back(5);
// test.push_back(2);

    // test.push_back(6);
     // test.push_back(7);
     //test.push_back(4);
    string s,p;
    int n;
    while(cin>>s>>p)
    {
        ts->multiply(s,p);
        //ts->searchRange(test,n);
//        vector<vector<int> > ans=ts->combinationSum2(test,n);
//        for(int i=0;i<ans.size();i++)
//        {
//            for(int j=0;j<ans[i].size();j++)
//                cout<<ans[i][j]<<" ";
//            cout<<"\n";
//        }
     //ts->nextPermutation(test);
//        vector<vector<int> > ans=ts->combinationSum(test,n);
//        cout<<"-----"<<ans.size()<<"\n";
//        for(int i=0;i<ans.size();i++)
//        {
//            for(int j=0;j<ans[i].size();j++)
//                cout<<ans[i][j]<<" ";
//            cout<<"\n";
//        }
       // cout<<ts->strStr(s,p)<<"\n";
        //cout<<s<<"\n";
//        cout<<ts->search1(test,n)<<"\n";
       // cout<<ts->longestValidParentheses(s)<<"\n";
//      vector<string> ans=  ts->letterCombinations(s);
//      for(int i=0;i<ans.size();i++)
//      {
//          cout<<ans[i]<<"\n";
//      }
//        vector<string> ans=ts->generateParenthesis(n);
//        for(int i=0;i<ans.size();i++)
//        {
//            cout<<ans[i]<<"\n";
//        }
//cout<<ts->divide(10,3)<<"\n";
//cout<<ts->divide(7,-3)<<"\n";
//cout<<ts->divide(-2147483648,-1)<<"\n";
//cout<<ts->divide(-1010369383,-2147483648)<<"\n";

       /* ListNode *t=head;
        for(int i=2;i<=n;i++)
        {
            t->next=new ListNode(i);
            t=t->next;
        }
        print(head);
        cout<<"\n";
//        print(ts->swapPairs(head));
        print(ts->reverseKGroup(head,n));
        cout<<"\n";*/
//        vector<int> test;
//        test.clear();
//        test.push_back(1);
//        for(int i=0;i<n;i++)
//        {
//            test.push_back(i+1);
//        }
//        test.push_back(1);
//        test.push_back(2);
//        test.push_back(3);
        //vector<vector<int> >ans=ts->permute(test);
//        vector<vector<int> >ans=ts->permuteUnique(test);
//        for(int i=0;i<ans.size();i++)
//        {
//            for(int j=0;j<ans[i].size();j++)
//            {
//                cout<<ans[i][j]<<" ";
//            }
//            cout<<"\n";
//        }
//        test.resize(n);
//        for(int i=0;i<n*n;i++)
//        {
//            test[i/n].push_back(i+1);
//        }
//        ts->rotate(test);
//        cout<<ts->lengthOfLongestSubstring(s)<<"\n";
//        cout<<"\n"<<ts->convert(s,n)<<"\n";
//    cout<<ts->reverse(n)<<"\n";
//        cout<<(bool)ts->isMatch(s,p)<<"\n";
//cout<<ts->intToRoman(n)<<"\n";
// cout<<ts->romanToInt(s)<<"\n";
//cout<<ts->isValid(s)<<"\n";
//cout<<ts->countAndSay(n)<<"\n";
//cout<<ts->searchInsert(test,n)<<"\n";
//cout<<ts->myPow(2.00,10)<<"\n";
//cout<<ts->myPow(2.10,3)<<"\n";
//cout<<ts->myPow(2.00,-2)<<"\n";
    }
    return 0;
}
//9223372036854775808
