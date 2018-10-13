#include <iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> id;
       while(!id.empty())
       {
           id.pop();
       }
        int res=0;
        int n=heights.size();
        for(int i=0;i<n;i++)
        {

            if(id.empty()||heights[id.top()]<heights[i])
            {
                id.push(i);
                //cout<<"id.push"<<i<<"\n";
            }
            else
            {
                while(!id.empty()&&heights[id.top()]>=heights[i]){
                int len=0;
                int tmp=id.top();
                id.pop();
                if(id.empty())
                {
                    len=i;
                }
                else
                {
                    len=i-id.top()-1;
                }
                //cout<<i<<" "<<id.top()<<" "<<len<<" "<<tmp<<" "<<heights[tmp]<<"\n";
                res=max(res,len*heights[tmp]);
                }
                id.push(i);
            }
        }
        return res;
    }
};
int main()
{
    Solution *solution=new Solution();
    vector<int> test;
    test.clear();

    //test.push_back(2);
    //test.push_back(1);
     test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);
    test.push_back(5);
    test.push_back(3);
    //test.push_back(5);
    //test.push_back(6);
    //test.push_back(2);
    //test.push_back(3);
    solution->largestRectangleArea(test);
    return 0;
}
