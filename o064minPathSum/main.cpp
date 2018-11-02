#include <iostream>
#include  <vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
            for(int i=0;i<grid.size();i++)
            {
                for(int j=0;j<grid[i].size();j++)
                {
                    cout<<grid[i][j];
                }
                cout<<"\n";
            }
            int n=grid.size();
            int m=grid[0].size();
            vector<vector<int> > ans(n,vector<int>(m,0));
            ans[0][0]=grid[0][0];
            for(int i=1;i<n;i++)
            {
                ans[i][0]=grid[i][0]+ans[i-1][0];
            }
            for(int j=1;j<m;j++)
            {
                ans[0][j]=grid[0][j]+ans[0][j-1];
            }
            for(int i=1;i<n;i++)
            {
                for(int j=1;j<m;j++)
                {
                    ans[i][j]=min(ans[i-1][j],ans[i][j-1])+grid[i][j];
                }
            }
            return ans[n-1][m-1];
    }
};
int main()
{
    vector<vector<int> > test(3,vector<int>(3,1));
    test[0][1]=3;
    test[1][1]=5;
    test[2][0]=4;
    test[2][1]=2;
    Solution *solution=new Solution();
    cout<<solution->minPathSum(test)<<"\n";
    return 0;
}
