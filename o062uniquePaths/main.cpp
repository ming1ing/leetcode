#include <iostream>
#include  <vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > ans(m+1,vector<int>(n+1,0));
        ans[1][1]=1;
        for(size_t i=1;i<ans[1].size();i++)
        {
            ans[1][i]=1;
        }
        for(size_t i=1;i<ans.size();i++)
        {
            ans[i][1]=1;
        }
        for(size_t i=2;i<ans.size();i++)
        {
            for(size_t j=2;j<ans[i].size();j++)
            {
                ans[i][j]=ans[i][j-1]+ans[i-1][j];
            }
        }
        return ans[m][n];
    }
};
int main()
{
    Solution *s=new Solution();
    int m,n;
    while(cin>>m>>n)
    {
        cout<<s->uniquePaths(m,n)<<"\n";
    }

    return 0;
}
