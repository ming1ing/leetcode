#include <iostream>
#include <cmath>
#include<vector>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        vector<int > ans(n+2,0);
        ans[0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                ans[i]+=ans[j]*ans[i-1-j];
            }

        }
        return ans[n];
    }
};
int main()
{
    Solution *solution=new Solution();
    int n;
    while(cin>>n)
    {
         cout<<solution->numTrees(n)<<"\n";
    }

    return 0;
}
