#include "iostream"
#include "array"
#include "fstream"
using namespace std;
namespace first
{
	int a=10, b=10;
};
template<class T>
struct node
{
	T g;
	node* prev;
	node* next;
};
class double_list
{
	node<int>* head;
	node<int>* tail;	
	void addnode(node<int>* head, node<int>* newnode);
	void deletenode(node<int>* head, node<int>* badnode);
};
/*double_list::addnode(node* head, node* newnode)
{

}*/
class list
{
	int length;
	node<int>* head;	
};
template< class T, class Q>
class rectangle
{
	private:
		T width;
		T height;
	public:
		T peri;
		rectangle(T a, T b)
		{
			width=a;
			height=b;
		};
		rectangle()
		{
			width=0;
			height=0;
		}
		

	Q perimeter()
	{
		return 2*width*height;
	}
	rectangle operator * (T ab)
	{
		rectangle final(0,0);
		final.width=ab+width;
		final.height=ab+height;
		return final;
	}
n
};
void printarray (int arg[], int length) 
{
  for (int n=0; n<length; ++n)
  cout << arg[n] << ' ';
  cout << '\n';
}
union name
{
	int i;
	char c;
};

int main()
{ 
	int** c,**d;
	int n=5,m=4;
	c=new int* [n];
	d=c;
	for(int i =0; i<n;i++)
	{
		c[i]=new int [m];
		for(int j=0;j<m;j++)
		{
			c[i][j]=(i+1)*(j+1);
		}
		printarray(c[i],m);
	}
	node<int>* alpha;
	alpha=new node<int>;
	alpha->g=5;
	rectangle<int,float> rect(6,7);
	rectangle<int,float> rect1(2,3);
	rectangle<int,float> z;
	rectangle<int,float>
	z=rect*2;
	cout<< z.perimeter()<<endl<<endl;
	fstream file ("new_file");
	streampos st,end;
	st=file.tellg();
}

