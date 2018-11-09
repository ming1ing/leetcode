#include <iostream>
#include<cmath>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        double l=1,r=x;
        if(x==0) return 0;
        while(fabs(l-r)>1e-6)
        {
            double mid=(l+r)/2;
            if((mid==x/mid)&&(mid*mid==x))
                return mid;
            if(mid<x/mid)
            {
                l=mid;
            }
            else
            {
                r=mid;
            }
        }
            return r;
    }
    int mySqrt2(int x) {
        if(x==0) return 0;
        double a=x;
        double lastans=-1;
        double result=x;
        do
        {
            lastans=result;
            result=0.5*(lastans+a/lastans);
        }while(fabs(result-lastans)>1e-6);

        return lastans;
    }
};
int main()
{
    Solution *solution=new Solution();
    int n;
    while(cin>>n)
    {
        cout<<solution->mySqrt(n)<<"\n";
        cout<<solution->mySqrt2(n)<<"\n";
    }
    return 0;
}
