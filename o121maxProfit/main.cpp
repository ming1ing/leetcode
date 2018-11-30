#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> l(n,0);
        vector<int> r(n,0);
        l[0]=prices[0];
        for(int i=1;i<n;i++)
        {
            l[i]=min(l[i-1],prices[i]);
        }
        r[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--)
        {
            r[i]=max(r[i+1],prices[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            //cout<<l[i]<<" "<<r[i]<<"\n";
            ans=max(ans,r[i]-l[i]);
        }
        return ans;
    }
};
int main()
{
    vector<int> test{7,1,5,3,6,4};
    Solution *s=new Solution();
    cout<<s->maxProfit(test)<<"\n";
    return 0;
}
