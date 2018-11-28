#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int l=0,r=n,top=0,bot=n;
        int m_count=1;
        while(l<=r&&top<=bot)
        {
            for(int i=l;i<r;i++)
            {
                ans[top][i]=m_count++;
            }
            top++;
            if(top>bot) break;
            for(int i=top;i<bot;i++)
            {
                ans[i][r-1]=m_count++;
            }
            r--;
            if(l>r) break;
            for(int i=r-1;i>=l;i--)
            {
                ans[bot-1][i]=m_count++;
            }
            bot--;
            if(top>bot) break;
            for(int i=bot-1;i>=top;i--)
            {
                ans[i][l]=m_count++;
            }
            l++;
            if(l>r) break;
        }
        return ans;
    }
};
int main()
{
    Solution *s=new Solution();
    int n;
    while(cin>>n)
    {
        auto ans=s->generateMatrix(n);
        for(auto i :ans)
        {
            for(auto j:i)
            {
                cout<<j<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
