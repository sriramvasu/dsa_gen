/*
 * Complete the function below.
 */
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
int max(int a, int b, int c)
{
    if(a>b & a>c)return a;
    else if(a<b & b>c)return b;
    else if(c>a & c>b)return c;

}
int find_pairs(vector<int> a, int p, int q, int k)
    {
        if(q-p<=0) return 0;
        else
            {
                if(a[p]+a[q]>k)return find_pairs(a,p,q-1,k);
            else if(a[p]+a[q]<k)return find_pairs(a,p+1,q,k);
            else return 1+max(find_pairs(a,p+1,q-1,k),find_pairs(a,p,q-1,k),find_pairs(a,p+1,q,k));
    }
    
}

int countPairs(int k, vector < int > a) {
    int number;
    sort(a.begin(),a.end());
    number=find_pairs(a,0,a.size()-1,k);
    return number;

}
int countPairs1(int k, vector < int > a) {
    int number=0;
    for(int i=0;i<a.size();i++)
    {
        for(int j=i+1;j<a.size();j++)
        {
            if(a[i]+a[j]==k)
                number+=1;
        }
    }
    return number;
}

int main() {
    int res;
    int _k;
    cin >> _k;
    
    
    int _a_size = 0;
    cin >> _a_size;
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }
    
    res = countPairs(_k, _a);
    cout<<res;
    return 0;
}
