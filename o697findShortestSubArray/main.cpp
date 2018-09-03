#include <iostream>
#include<vector>
#include<map>
using namespace std;
struct node{
   int l;
   int r;
   int num;
   node():l(1000000),r(0),num(0){}
};
class Solution
{
public:
    int findShortestSubArray(vector<int>& nums)
    {
        int len=nums.size();
        map<int,node> mp;
        mp.clear();
        int longestlen=0;
        int ans=10000000;
        for(int i=0;i<len;i++)
        {
            int t=nums[i];
            if(mp.find(t)==mp.end())
            {
                mp[t].l=i;
                mp[t].r=i;
                mp[t].num=1;
                if(mp[t].num>longestlen)
                {
                    longestlen=mp[t].num;
                    ans=(mp[t].r-mp[t].l+1);
                    continue;
                }
                if(mp[t].num==longestlen)
                {
                    if((mp[t].r-mp[t].l+1)<ans)
                    {
                        ans=(mp[t].r-mp[t].l+1);
                    }
                }
            }
            else
            {
                mp[t].r=i;
                mp[t].num++;
                if(mp[t].num>longestlen)
                {
                    longestlen=mp[t].num;
                    ans=(mp[t].r-mp[t].l+1);
                    continue;
                }
                 if(mp[t].num==longestlen)
                {
                    if((mp[t].r-mp[t].l+1)<ans)
                    {
                        ans=(mp[t].r-mp[t].l+1);
                    }
                }
            }

        }
        return ans;
    }
};
int main()
{
    Solution *solution=new Solution();
    vector<int> test;
    test.clear();
//    test.push_back(1);
//    test.push_back(2);
//    test.push_back(2);
//    test.push_back(3);
//    test.push_back(1);
//    test.push_back(4);
//    test.push_back(2);
        test.push_back(49999);
         test.push_back(1);
          test.push_back(1);
           test.push_back(1);
           test.push_back(2);
           test.push_back(1);
    cout<<solution->findShortestSubArray(test);
    return 0;
}
