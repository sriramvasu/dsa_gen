#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
vector<int> insert(vector<int> a, int n)
    {
    int i,temp,temp1;
    for(i=0;i<n;i++)
        {
        if(a[i]>a[n+1])break;
    }
    temp=a[i];
    a[i]=a[n+1];
    for(int j=i+1;j<=n;j++)
        {
        temp1=a[j];
        a[j]=temp;
        temp=temp1;
    }
    return a;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int a_i = 0;a_i < n;a_i++){
        cin >> a[a_i];
        if(a_i!=0)a=insert(a,a_i-1);
    if(a_i%2==0)cout<<a[a_i/2]<<endl;
    else cout<<float(a[a_i/2]+a[a_i/2+1])/2<<endl;
    
    }
    return 0;
}
