#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	 vector<int> v;

    int n,gh;
    cin>>n;
    for(int i=0;i<n;i++)
        {
         cin>>gh;
        v.push_back(gh);
        
    }
    
    sort(v.begin(),v.end());
    v.erase()
    for(int i=0;i<n;i++)
        {cout<<v[i]<<" ";}
       
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

