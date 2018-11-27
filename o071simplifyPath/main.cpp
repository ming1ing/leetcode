#include <iostream>
#include<cstring>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        char s[1000];
        int len=0;
        int m_pathlen=path.length();
        path+="//";
        for(int i=0;i<m_pathlen;i++)
        {
            if(path[i]=='/')
            {
                if(path[i+1]=='/')
                {
                    continue;
                }
                else if(path[i+1]=='.'&&path[i+2]=='/')
                {
                    i++;
                    continue;
                }
                else if(path[i+1]=='.'&&path[i+2]=='.'&&path[i+3]=='/')
                {
                    while(len>1)
                    {
                        len--;
                        if(s[len]=='/')
                        {
                            break;
                        }
                    }
                }
                else
                {
                    if(len>=1&&s[len-1]=='/'&&path[i]=='/')
                    {
                        i++;
                    }
                    s[len++]=path[i++];
                    while(path[i]!='/'&&i<m_pathlen)
                    {
                        s[len++]=path[i++];
                    }
                    i--;
                }
            }
        }
        if(len==0)
        {
            s[len++]='/';
        }
        s[len]='\0';
        return s;
    }
};
int main()
{
    Solution *s=new Solution();
    string st;
    while(cin>>st)
    {
        cout<<s->simplifyPath(st)<<"\n";
    }
    return 0;
}
