#include <iostream>
#include<map>
using namespace std;
class LRUCache {
private:
    map<int,int> LRU;//key,valuee
    map<int,int> rLRU;//id,key
    map<int,int> RLRU;//key,id
    int Maxsize;
    int nowsize;
    int id;
public:
    LRUCache(int capacity) {
        LRU.clear();
        rLRU.clear();
        RLRU.clear();
        Maxsize=capacity;
        nowsize=0;
        id=0;
    }
  void printres()
  {
       cout<<"LRU\n";
        for(map<int,int>::iterator it=LRU.begin();it!=LRU.end();it++)
        {
            cout<<it->first<<" "<<it->second<<"\n";
        }
        cout<<"rLRU\n";
        for(map<int,int>::iterator it=rLRU.begin();it!=rLRU.end();it++)
        {
            cout<<it->first<<" "<<it->second<<"\n";
        }
        cout<<"RLRU\n";
        for(map<int,int>::iterator it=RLRU.begin();it!=RLRU.end();it++)
        {
            cout<<it->first<<" "<<it->second<<"\n";
        }
  }
    int get(int key) {
        if(LRU.find(key)==LRU.end())
        {

            id++;
            printres();
            return -1;
        }
        else
        {
            rLRU.erase(RLRU[key]);
            rLRU[id]=key;
            RLRU[key]=id;
            id++;
            printres();
            return LRU[key];
        }
    }

    void put(int key, int value) {
        if(LRU.find(key)!=LRU.end())
        {
            int t=RLRU[key];
            LRU[key]=value;

            RLRU[key]=id;
            rLRU.erase(t);
             rLRU[id]=key;
            id++;
            return ;
        }
        if((int)LRU.size()>=Maxsize)
        {
            map<int,int>::iterator it=rLRU.begin();//最小的id ->key
            int t=it->second;
          //  cout<<"key"<<t<<"\n";
            RLRU.erase(t);
            LRU.erase(t);
            rLRU.erase(it);
            LRU[key]=value;
            rLRU[id]=key;
            RLRU[key]=id;
            printres();
        }
        else
        {
            LRU[key]=value;
            rLRU[id]=key;
            RLRU[key]=id;
            printres();
        }
            id++;

    }
};
int main()
{
    LRUCache *obj = new LRUCache(2);
//    obj->put(1,1);
//    obj->put(2,2);
//    cout<<"ans:"<<obj->get(1)<<"\n";
//    obj->put(3,3);
//    cout<<"ans:"<<obj->get(2)<<"\n";
//    obj->put(4,4);
//    cout<<"ans:"<<obj->get(1)<<"\n";
//    cout<<"ans:"<<obj->get(3)<<"\n";
//    cout<<"ans:"<<obj->get(4)<<"\n";
        cout<<"get"<<obj->get(2)<<"\n";

    return 0;
}
