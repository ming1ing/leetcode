#include <iostream>
#include<string>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0;
        int len=s.length();
        while(1)
        {
            if(s[len-1]==' ')
                len--;
            else
                break;
        }
        for(int i=len-1;i>=0;i--)
        {
            if(s[i]==' ')
                break;
            ans++;
        }
        return ans;
    }
};
int main()
{
    Solution *solution=new Solution();
    string test;
    while(getline(cin,test))
    {
        cout<<solution->lengthOfLastWord(test)<<"\n";
    }

    return 0;
}
