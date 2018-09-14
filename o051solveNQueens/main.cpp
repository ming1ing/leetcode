#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Solution{
public:
void dfs(vector<string> &mp,vector<int> &mark, vector<vector<string> > &res,int id, int len) {

    if(id>=len)
    {
        res.push_back(mp);
        for(int i=0;i<(int)mp.size();i++)
        {
            for(int j=0;j<(int)mp[i].size();j++)
            {
                cout<<mp[i][j];
            }
            cout<<"\n";
        }
        return ;
    } else
    {
        for(int i=0;i<len;i++)
        {
            if(mark[i]==0&&mp[id][i]=='.')
            {
                int x=id,y=i;
                int flag=0;
                while(x>=0&&y>=0)
                {
                    if(mp[x][y]!='.')
                    {flag=1; break ;}
                    x--;y--;
                }
                if(flag==1)
                    continue;
                x=id,y=i;
                while(x>=0&&y<len)
                {
                    if(mp[x][y]!='.')
                    {flag=1;break ;}
                    x--;y++;
                }
                if(flag==1)
                    continue;
                x=id,y=i;
                mp[x][y]='Q';
                mark[i]=1;
                dfs(mp,mark,res,id+1,len);
                mp[x][y]='.';
                mark[i]=0;
            }

        }
    }
}
vector<vector<string> > solveNQueens(int n) {
    string s="";
    for(int i=0;i<n;i++)
        s+='.';
    vector<string> mp;
    mp.clear();
    for(int i=0;i<n;i++)
    mp.push_back(s);

    vector<int> mark(n,0);
    vector<vector<string> > res;
    res.clear();
    for(int i=0;i<n;i++)
    {
        if(mark[i]==0)
        {
            mp[0][i]='Q';
            mark[i]=1;
            dfs(mp,mark,res,1,n);
            mark[i]=0;
            mp[0][i]='.';
        }

    }
    return res;
}
};
int main()
{
    Solution *solution=new Solution();
   int n;
   while (cin>>n)
   {
       solution->solveNQueens(n);
   }
    return 0;
}
