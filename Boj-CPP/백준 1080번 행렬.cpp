#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int a[50][50],b[50][50];
int n,m,cnt;
string s;
void bandae(int x, int y)
{
	for(int i=x-1; i<=x+1; i++)
	{
		for(int j=y-1; j<=y+1; j++)
		a[i][j]=1-a[i][j];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=0; i<n; i++)
	{
		cin>>s;
		for(int j=0; j<m; j++)
		a[i][j]=s[j]-'0';		
	}
	for(int i=0; i<n; i++)
	{
		cin>>s;
		for(int j=0; j<m; j++)
		b[i][j]=s[j]-'0';		
	}
	for(int i=0; i<n-2; i++)
	{
		for(int j=0; j<m-2; j++)
		{
			if(a[i][j]!=b[i][j])
			{
				cnt++;
				bandae(i+1,j+1);
			}
		}
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(a[i][j]!=b[i][j])
			{
				cout<<-1;
				return 0;
			}
		}
	}
	cout<<cnt;
			
} 
