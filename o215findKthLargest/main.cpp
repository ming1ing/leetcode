#include <iostream>
#include<vector>
#include<cstdio>
#include<string>
using namespace std;
class Solution {
public:
    int findk(vector<int>& nums,int l,int r){

        int t;
        t=nums[l];
        while(l<r)
        {

            while(l<r&&t>=nums[r])
            {
                r--;
            }
            if(l<r)
            nums[l++]=nums[r];
            while(l<r&&nums[l]>t)
            {
                l++;
            }
            if(l<r)
            nums[r--]=nums[l];

        }
        nums[l]=t;
        return l;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int len=nums.size();
        int l=0,r=len-1;
        while(l<r)
        {
            int t=findk(nums,l,r);
            if(t==k-1)
                {return nums[t];}
            else if(t<k-1)
            {
                l=t+1;
            }
            else
            {
                r=t-1;
            }

        }
        return nums[k-1];
    }
};
int main()
{
    Solution *solution=new Solution();
    vector<int> test;
    int k;
    int len=test.size();
   test.push_back(3);
test.push_back(1);
test.push_back(2);
test.push_back(4);
    while(cin>>k)
    {
     cout<<"\npos:"<<k-1<<"\n";

        //cout<<solution->findk(test,0,len-1);
        cout<<solution->findKthLargest(test,k)<<"\n";
    }
    cout<<test.size();
    return 0;
}
