#include "iostream"
#include "vector"
using namespace std;
template<class T>
class node
{
	public:
		node<T>* parent;
		node<T>* left;
		node<T>* right;
		T value;
		node()
		{
			this->left=NULL;
			this->right=NULL;
			this->parent=NULL;
		}
};
template<class T>
class binary_tree
{
public:
	node<T>* root;
	binary_tree()
	{
		root=NULL;
	}
	~binary_tree()
	{
		del_tree(root);
	}
	void del_tree(node<T>* root)
	{
		while(root!=NULL)
		{
			del_tree(root->left);
			del_tree(root->right);
			delete root;
		}
			
	}
	void addnode(node<T>* newnode)
	{
		node<T>* gen=this->root;
		node<T>* par=NULL;
		while(gen!=NULL)
		{
			if(newnode->value>=gen->value)
				{
					par=gen;
					gen=gen->right;
					if(gen==NULL)par->right=newnode;
				}
			else if(newnode->value<gen->value)
			{
				par=gen;
				gen=gen->left;
				if(gen==NULL)par->left=newnode;
			}
		}
		if(gen==NULL)root=newnode;
		newnode->parent=par;
		newnode->left=NULL;
		newnode->right=NULL;
	}
	void delete__node(node<T>* del)
	{

	}
	node<T>* search_tree(T value)
	{

	}
	node<T>* successor(node<T>* x)
	{

	}
	node<T>* predecessor(node<T>* x)
	{

	}
	void print_inorder(node<T>* root)
	{
		node<T>* gen=root;
		while(gen!=NULL)
		{
			print_inorder(gen->left);
			cout<<gen->value;
			print_inorder(gen->right);
		}
	}
	node<T>* minimum()
	{
		node<T>* gen=this->root;
		while(gen->left!=NULL)gen=gen->left;
		return gen;
	}
	node<T>* maximum()
	{
		node<T>* gen=this->root;
		while(gen->right!=NULL)gen=gen->right;
		return gen;
	}
	
};
int main()
{
	node<int>* mem = new node<int>[12];
	for(int i=0;i<12;i++)mem[i].value=i+1;
	binary_tree<int> bt;
	for(int i=0;i<12;i++)bt.addnode(&mem[i]);
	
}