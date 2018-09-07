#include <iostream>

#include<vector>
using namespace std;
class Solution {
public:
    bool PredictTheWinner(vector<int> & nums) {
      return winner(nums, 0, nums.size()-1) >= 0;
    }
    int winner(vector<int>& nums,int s,int e)
    {
         if (s > e) return -1;
        if (s == e) return nums[s];
        int a = nums[s] -winner(nums, s+1, e);
        int b = nums[e]-winner(nums, s, e-1);
        int t = a >= b ? a : b;
        return t;
    }
};
int main()
{
    vector<int> test;
    test.push_back(1);
    test.push_back(5);
    //test.push_back(2);
    test.push_back(233);
    test.push_back(7);
    Solution *solution=new Solution();
    cout<<solution->PredictTheWinner(test)<<"\n";
    return 0;
}
