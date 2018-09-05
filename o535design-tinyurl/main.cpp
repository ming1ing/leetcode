#include <iostream>
#include<string>
#include<map>
using namespace std;
class Solution {
public:
    map<string,string> change;
    map<string,string> rechange;
    long long id=0;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string s="http://tinyurl.com/"+id;
        change[longUrl]=s;
        rechange[s]=longUrl;
        id++;
        return change[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return rechange[shortUrl];
    }
};

int main()
{

    return 0;
}
