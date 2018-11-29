#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> ans(n+1,vector<int>(n+1,1));
        int now=0,pre=0;
        ans[now][0]=triangle[0][0];
        now=1;
        for(int i=1;i<n;i++)
        {
           // cout<<"??"<<pre<<" "<<now<<"\n";
            for(int j=0;j<triangle[i].size();j++)
            {
                if(j==0)
                    ans[now][j]=ans[pre][j]+triangle[i][j];
                else if(j==i)
                    ans[now][j]=ans[pre][j-1]+triangle[i][j];
                else
                    ans[now][j]=min(ans[pre][j-1],ans[pre][j])+triangle[i][j];

                    //cout<<ans[now][j]<<" ";

            }
            pre^=1;now^=1;
           // cout<<"\n";
        }
        int res=10000000;
        for(int i=0;i<n;i++)
        {
            res=min(ans[pre][i],res);
        }
        return res;
    }
};
int main()
{
    Solution *s=new Solution();
    vector<vector<int> > test;
    int n=4;
    test.resize(n);
    int num=1;
    for(int i=0;i<n;i++)
    {
        test[i].resize(i+1);
        for(int j=0;j<test[i].size();j++)
        {
            test[i][j]=++num;
            cout<<test[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<s->minimumTotal(test)<<"\n";
    return 0;
}
