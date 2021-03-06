#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int n,m;
int a[1000001];
int d[1002020][40];
void first()
{
	for(int i=1;i<=n;i++)
	{
		d[i][0]=a[i];
	}
}
void dp()
{
	int l=log2(n);
	for(int j=1;j<=l;j++)
	{
		for(int i=n;i>=1;i--)
		{
			d[i][j]=max(d[i][j-1],d[i+(1<<(j-1))][j-1]);
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	first();
	dp();
	int l,r;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&l,&r);
		int k=log2(r-l+1);
		printf("%d\n",max(d[l][k],d[r-(1<<k)+1][k]));
	}
	return 0;
}
