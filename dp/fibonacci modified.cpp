#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void fib(long double* v,int ti)
    {
    v[ti]=v[ti-2]+(v[ti-1])*(v[ti-1]);
}
void iter_bottomup(int n,long double* v)
    {
        
    
}
void iter_topdown(int n,long double* v)
    {
        cout<<n-1<<endl;
    if(v[n-1]!=-1) return;
    else
        {
            iter_topdown(n-1,v);
            iter_topdown(n-2,v);
        }
    fib(v,n-1);
}

int main() {
    int t1,t2;
    int n;
    cin>>t1;
    cin>>t2;
    cin>>n;
    long double* v= new long double[n];
    for(int i=0;i<n;i++)
        v[i]=-1;
    v[0]=t1;v[1]=t2;
    iter_topdown(n,v);
    cout<<v[n-1];
    return 0;

}
