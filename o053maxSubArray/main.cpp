#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0];
        int len=nums.size();
        int t=0;
        for(int i=0;i<len;i++)
        {
            t+=nums[i];
            if(t>ans)
            {
                ans=t;
            }
            if(t<0)
            {
                t=0;
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> test;
    test.clear();
    int a[]={-2,1,-3,4,-1,2,1,-5,4};
    int len=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<len;i++)
    {
        test.push_back(a[i]);
    }
    Solution *solution=new Solution();
    cout<<solution->maxSubArray(test)<<"\n";
    return 0;
}
