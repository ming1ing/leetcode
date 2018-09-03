#include <iostream>
#include<string>
using namespace std;
struct TireNode
{
    int val;
    TireNode *next[26];
    TireNode(int _v=0)
    {
        val=_v;
        for(int i=0; i<26; i++)
            next[i]=NULL;
    }
};
class Trie
{
public:
    TireNode *root;
    Trie()
    {
        root=new TireNode();
    }
    void insert(string word)
    {
        int len=word.length();
        TireNode *troot=root;
        for(int i=0; i<len; i++)
        {
            if(troot->next[word[i]-'a']==NULL)
            {
                troot->next[word[i]-'a']=new TireNode();

                troot=troot->next[word[i]-'a'];

            }
            else
            {
                troot=troot->next[word[i]-'a'];

            }
        }
        troot->val=1;
    }

    bool search(string word)
    {
        TireNode *troot=root;
        int len=word.length();
        for(int i=0; i<len; i++)
        {
            if(troot->next[word[i]-'a']==NULL)
            {
                return false;
            }
            else
            {
                troot=troot->next[word[i]-'a'];
            }
        }
        return troot->val;
    }

    bool startsWith(string prefix)
    {
       TireNode *troot=root;
        int len=prefix.length();
        for(int i=0; i<len; i++)
        {
            if(troot->next[prefix[i]-'a']==NULL)
            {
                return false;
            }
            else
            {
                troot=troot->next[prefix[i]-'a'];
                //troot->val++;
            }

        }
        return true;
    }
    void printfTire(TireNode *troot){
    if(troot!=NULL)
    {
        cout<<troot->val<<" ";
        for(int i=0;i<26;i++)
        {
            printfTire(troot->next[i]);
        }
    }
}
};

int main()
{
    string word="abc";
    string word2="ab";
    Trie *obj = new Trie();
    obj->insert(word);
    cout<<"\n";
    obj->printfTire(obj->root);
    cout<<"\n";
    cout<<obj->search(word)<<"\n";
    cout<<obj->search(word2)<<"\n";
    obj->insert(word2);
    cout<<"word2\n";
    obj->printfTire(obj->root);
    cout<<"\n";
    cout<<obj->search(word2)<<"\n";
    obj->insert(word2);
    cout<<"word2\n";
    obj->printfTire(obj->root);
    cout<<"\n";
    cout<<obj->search(word2)<<"\n";
    //cout<<obj->startsWith(word2)<<"\n";
    return 0;
}
