#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n=prices.size();
        prices.push_back(-1);
        if(n==0||n==1) return 0;
        int ans=0;
        int l=0,r=1;
        while(l<r&&r<n)
        {
            if(prices[l]>prices[r])
            {
                l++;r++;
                continue;
            }
            while(prices[r]>=prices[r-1])
            {
                r++;
                if(r>=n)
                {break;}
            }
            r--;
            ans+=prices[r]-prices[l];
            l=r+1;
            r=l+1;
        }
        return ans;
    }
};
int main()
{
    vector<int> test{7,1,5,3,6,4};
    Solution *s=new Solution();
    cout<<s->maxProfit(test);
    return 0;
}
