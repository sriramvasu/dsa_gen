#include "iostream"
#include "string"
#include "vector"

using namespace std;
int main()
{
	string a, b;
	cin>>a;cin>>b;
	vector<vector<int>> c(a.length()+1);
	for(int i=0;i<=a.length();i++)
	{
		c[i].resize(b.length()+1);
		fill(c[i].begin(),c[i].end(),0);
	}
	vector<vector<int>> d(a.length()+1);
	for(int i=0;i<=a.length();i++)
	{
		d[i].resize(b.length()+1);
		fill(d[i].begin(),d[i].end(),0);
	}
	for(int i=1;i<=a.length();i++)
	{
		for(int j=1;j<=b.length();j++)
		{
			if(a[i-1]==b[j-1])
			{
				c[i][j]=1+c[i-1][j-1];
				d[i][j]=1;
			}
			else
			{
				if(c[i-1][j]>=c[i][j-1])
				{
					c[i][j]=c[i-1][j];
					d[i][j]=2;
				}
				else if(c[i-1][j]<c[i][j-1])
				{
					c[i][j]=c[i][j-1];
					d[i][j]=3;
				}
			}
		}	
	}
	vector<char> lcs;
	int i=1,j=1;
	while(i<=a.length() && i<=b.length())
	{
		if(d[i][j]==1){lcs.push_back(a[i-1]);cout<<a[i-1];i++;j++;}
		else if(d[i][j]==2)i++;
		else if(d[i][j]==3)j++;
	}
	cout<<endl;
	
}