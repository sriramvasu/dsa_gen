#include "iostream"
int main()
{
	

}

int array_split(int a[],int l, int r)
{
	int sum=0;
	for(int i=l;i<=r;i++)
	{
		sum+=a[i];
		if(sum!=0)
		{
			int rt=array_split(a,i+1,r);
		}
		if(rt==0)continue;
		else 
		{
			return 
		}
	}
}