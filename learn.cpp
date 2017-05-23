#include <iostream>
#include <vector>
#include <list>
using namespace std;
int main()
{
	int i;
	vector<int> vec;
	vector<int> vec1(vec);
	list<int> lst;
    for(i=1; i<=10; ++i)vec.push_back(i);
	for(i=0; i<vec.size();++i)cout<<(int)vec[i]<<' ';
	cout<<vec.max_size()<<endl;
	lst.push_back(5);
	lst.push_back(45);
	list<int>::iterator alpha;
    return 0;

}
