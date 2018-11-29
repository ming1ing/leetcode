#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int> > ans(rowIndex+1,vector<int>(rowIndex+1,1));
        for(int i=2;i<=rowIndex;i++)
        {
            for(int j=1;j<i;j++)
            {
                ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
            }

        }
        return ans[rowIndex];
    }
};
int main()
{
    int n;
    Solution *s=new Solution();
    while(cin>>n)
    {
        vector<int> ans=s->getRow(n);
        for(auto i: ans)
        {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
