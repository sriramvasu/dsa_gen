#include <iostream>
#include <vector>
#include <list>
#include <set>
using namespace std;
int main()
{
	set<int,greater<int>> a;
	a.insert(23);
	a.insert(45);
	a.insert(-29);
	for(set<int>::iterator i=a.begin();i!=a.end();i++)
	{
		cout<<*i<<endl;
	}
}