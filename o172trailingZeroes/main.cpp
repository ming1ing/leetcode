#include <iostream>

using namespace std;
class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0;
        ans=0;
        long long  t=5;
        while(t<=n)
        {
            ans+=n/t;
            t*=5;
        }

        return ans;
    }
};
int main()
{
    Solution *mysolution=new Solution();
    int n;
    while(cin>>n)
    {
            cout<<mysolution->trailingZeroes(n)<<"\n";

    }

    return 0;
}
