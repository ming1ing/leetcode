#include <iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        ans.clear();
        vector<int> ip;
        findans(ans,ip,0,0,s);
        return ans;
    }
    void findans(vector<string> &ans,vector<int> &ip,int now,int sum,string &s)
    {
        int n_ip=ip.size();
        if(n_ip>4)
            return;
        if(n_ip==4)
        {
            //cout<<"\n"<<now <<" "<< s.length() <<"\n";
            if(now!=s.length()) return ;
            for(int i=0;i<n_ip;i++)
            {
                if(ip[i]>255)
                    return ;
            }
            string s1="";
            for(int i=0;i<n_ip;i++)
            {
                //cout<<ip[i]<<".";
                s1+=to_string(ip[i]);
                if(i!=n_ip-1)
                s1+=".";
            }
        if(s1.length()!=s.length()+3) return ;
        if(!s1.empty())
        ans.push_back(s1);
            return ;
        }
        int temp=sum*10+(s[now]-'0');
        if(temp<256)
        {
            if(temp>0||(temp==0&&s[now]=='0'))
            {
                ip.push_back(temp);
                findans(ans,ip,now+1,0,s);
                ip.pop_back();
            }
            findans(ans,ip,now+1,temp,s);

        }
        else
        {
            return ;
        }
    }
};
int main()
{
    Solution *s=new Solution();
    string ts;
    //cout<<to_string(100)<<"\n";
   // cout<<to_string(10)<<"\n";
    while(cin>>ts)
    {
        vector<string> ans=s->restoreIpAddresses(ts);
        cout<<ans.size()<<"\n";
        for(size_t i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<"\n";
        }
    }
    return 0;
}
