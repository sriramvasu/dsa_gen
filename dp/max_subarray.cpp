#include "iostream"
#include "vector"
using namespace std;
int max_sum_noncont(int* v, int n)
{
	if(n==1)return v[n-1];
	int a=max_sum_noncont(v,n-1);
	if(v[n-1]>0)return a+v[n-1];
	else return a;
}
int bestn(int* v, int n)
{
	if(n==1)return v[n-1];
	return v[n-1]+bestn(v,n-1);
}
int max_sum_cont(int* v, int n)
{
	if(n==1)return v[n-1];
	int a=max_sum_cont(v,n-1);
	if(v[n-1]>0)
	{
		int b=bestn(v,n-1);
		if(b>a)return b+v[n-1];
		else return a+v[n-1];
	}
	else return max_sum_cont(v,n-1);
}

int main()
{
	int t,n;
	cin>>t;
	int* ans=new int[2*t];
	for(int i=0;i<t;i++)
	{
		cin>>n;
		int* v=new int[n];
		for(int j=0;j<n;j++)
			cin>>v[j];
		int al=max_sum_noncont(v,n);
		int bet=max_sum_cont(v,n);
		ans[2*i]=bet;
		ans[2*i+1]=al;

	}
	for(int i=0;i<t;i++)
	{
		cout<<ans[2*i]<<" "<<ans[2*i+1]<<endl;
	}
	return 0;
}
