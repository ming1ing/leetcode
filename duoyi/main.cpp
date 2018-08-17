#include <iostream>
#include<cstdio>
using namespace std;
int a[100000];
void rever(int a[],int l,int r){
    for(int i=l;i<l+(r-l)/2;i++){
        int t=a[i];
        a[i]=a[r+l-i-1];
        a[r+l-i-1]=t;
    }
}
int main()
{
    int n,k;
    while(cin>>n>>k)
    {
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        rever(a,0,n);
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<"\n";
        rever(a,0,k);
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<"\n";
        rever(a,k,n);
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
