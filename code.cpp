#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
	node* prev;
	node* next;
	int value;
};
class list()
{

	node* head;
	node* tail;
	void addnodepos(int position, node* newnode)
	{
		node* a=this->head;
		for(int i=0;i<position;i++)a=a->next;
		

	}
	void addnode(node* atnode, node* newnode)
	{

	}
	void removenode(node* toremove)
	{

	}

}
int main()
{
	list()
}
