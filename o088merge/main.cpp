#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m+n);
        int i=m-1,j=n-1,pos=m+n-1;
        while(i>=0&&j>=0)
        {
            if(nums1[i]>nums2[j])
            {
                nums1[pos--]=nums1[i--];
            }
            else
            {
                nums1[pos--]=nums2[j--];
            }
        }
        while(j>=0)
        {
           nums1[pos--]=nums2[j--];
        }
    }
};
int main()
{
    Solution *s=new Solution();
    vector<int> nums1{1,2,3};
    vector<int> nums2{2,5,6};
    s->merge(nums1,nums1.size(),nums2,nums2.size());
    for(int i=0;i<nums1.size();i++)
    {
        cout<<nums1[i]<<" ";
    }
    return 0;
}
