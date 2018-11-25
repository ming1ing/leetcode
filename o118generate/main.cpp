#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ans;
        ans.resize(numRows);
        for(int i=0;i<numRows;i++)
        {
            ans[i].resize(i+1);
            ans[i][0]=1;
            ans[i][i]=1;
        }

        for(int i=2;i<numRows;i++)
        {
            for(int j=1;j<ans[i].size()-1;j++)
            {
                ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
            }
        }
        return ans;
    }
};
int main()
{
    int n;
    Solution *s=new Solution();
    while(cin>>n)
    {
        vector<vector<int> > res=s->generate(n);
        for(int i=0;i<res.size();i++)
        {
            for(int j=0;j<res[i].size();j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
