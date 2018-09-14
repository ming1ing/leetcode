#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> ans;
        ans.clear();
        if(matrix.size()==0)
            return ans;
        int startx=0,endx=matrix.size()-1;
        int starty=0,endy=matrix[0].size()-1;
        while(startx<=endx&&starty<=endy)
        {
            for(int i=starty;i<=endy;i++)
            {
                ans.push_back(matrix[startx][i]);
            }
            startx++;
            if(startx>endx)
                break;
            for(int i=startx;i<=endx;i++)
            {
                ans.push_back(matrix[i][endy]);
            }
            endy--;
            if(starty>endy)
                break;
            for(int i=endy;i>=starty;i--)
            {
                ans.push_back(matrix[endx][i]);
            }
            endx--;
            if(startx>endx)
                break;
            for(int i=endx;i>=startx;i--)
            {
                ans.push_back(matrix[i][starty]);
            }
            starty++;
            if(starty>endy)
                break;
        }
        return ans;
    }
};
int main()
{
    Solution *solution =new Solution();
    int n;
    while(cin>>n)
    {
        vector<vector<int> > test(n);
        for(int i=0;i<test.size();i++)
        {
            test[i].clear();
            for(int j=0;j<n;j++)
            {
                test[i].push_back(i*n+j);
            }
        }
        vector<int> ans=solution->spiralOrder(test);
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
    }

    return 0;
}
