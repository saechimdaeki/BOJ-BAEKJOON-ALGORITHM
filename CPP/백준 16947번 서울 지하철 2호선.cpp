#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> arr[3001];
int check[3001]; //0:�湮x, 1: �湮, 2:����Ŭ.  
int distan[3001];
int n;
int dfs(int x, int v) //-2�� ����Ŭã�Ұ� ���Խ�Ű������, -1�̸� ����Ŭ ��ã�� 0~n-1�̸� ����Ŭã�Ұ� �����ε����� 
{	
	if(check[x]==1)
	return x;
	check[x]=1;
	for(auto i: arr[x])
	{
		if (i==v)
		continue;
		int bts(dfs(i,x));
		if(bts==-2) return -2;
		if (bts>=0)
		{
			check[x]=2;
			if(x==bts) return -2;
			else return bts;
		}
	}
	return -1;	
} 
queue<int >q;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=0; i<n; i++)
	{
		int a,b;
		cin>>a>>b;
		a--; b--;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	dfs(0,-1);
	for(int i=0; i<n; i++)
	{
		if(check[i]==2)
		{
			distan[i]=0;
			q.push(i);
		}else {
			distan[i]=-1;
		}
	}
	while(!q.empty())
	{
		int x(q.front());
		q.pop();
		for(int i:arr[x])
		{
			if(distan[i]==-1)
			{
				q.push(i);
				distan[i]=distan[x]+1;
			}
		}
	}
	for(int i=0; i<n; i++)
	cout<<distan[i]<<' ';
}
