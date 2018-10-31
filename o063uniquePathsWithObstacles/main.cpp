#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        for(size_t i=0;i<obstacleGrid.size();i++)
        {
            for(size_t j=0;j<obstacleGrid[i].size();j++)
            {
                cout<<obstacleGrid[i][j];
            }
            cout<<"\n";
        }
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int> >ans(n,vector<int>(m,0));
        ans[0][0]=1^obstacleGrid[0][0];
        for(int i=1;i<n;i++)
        {
            if(obstacleGrid[i][0]==0)
                ans[i][0]=ans[i-1][0];
            else
                ans[i][0]=0;
        }
        for(int j=1;j<m;j++)
        {
            if(obstacleGrid[0][j]==0)
                ans[0][j]=ans[0][j-1];
            else
                ans[0][j]=0;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {

                if(obstacleGrid[i][j]==0)
                    {
                        ans[i][j]=ans[i-1][j]+ans[i][j-1];
                    }
                else
                    ans[i][j]=0;
            }
        }
        return ans[n-1][m-1];
    }
};
int main()
{
    vector<vector<int> > test(3,vector<int>(3,0));
    test[1][1]=1;
    Solution *s=new Solution();
    cout<<s->uniquePathsWithObstacles(test)<<"\n";
    return 0;
}
