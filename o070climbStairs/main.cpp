#include <iostream>

using namespace std;
class Solution {
public:
    int climbStairs(int n) {
            int a[46]={0};
            a[0]=1;a[1]=1;
            for(int i=2;i<=n;i++)
            {
                a[i]=a[i-2]+a[i-1];
                if(a[i]<a[i-1])
                    break;
            }
            return a[n];
    }
};
int main()
{
    Solution *solution=new Solution();
    int n;
    while(cin>>n)
    {
        cout<<solution->climbStairs(n)<<"\n";
    }
    return 0;
}
