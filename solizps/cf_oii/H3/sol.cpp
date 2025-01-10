#include <bits/stdc++.h>
using namespace std;
int t,n,p,dp[6011][6011][2],lim[6011],w[6011][6011],ans[3011];
void solve(int x)
{//printf("==========================solve(%d)\n",x);
	for(int i=1;i<=x;++i)lim[i]=x-i+1;
	for(int i=x+1;i<=n;++i)lim[i]=i-x+1;
	// printf("lim:");for(int i=1;i<=n;++i)printf("%d ",lim[i]);putchar(10);
	// printf("res[%d]:",x);for(int i=1;i<=n;++i)printf("%d ",res[x][i]);putchar(10);
}
int main()
{
	scanf("%d",&t);while(t--)
	{
		scanf("%d%d",&n,&p);//printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>. n:%d p:%d\n",n,p);
		for(int i=1;i<=n;++i)lim[i]=n-i+1;
		for(int i=n+1;i<2*n;++i)lim[i]=i-n+1;
		for(int i=1;i<=n;++i)ans[i]=0;
		for(int i=1;i<=2*n;++i)for(int j=i;j<=2*n;++j)dp[i][j][0]=dp[i][j][1]=0;
		for(int r=1;r<2*n;++r)
		{
			int cur=1;
			for(int i=r;i>=1;--i)
			{
				if(r-i+1<lim[i])w[i][r]=0;
				else w[i][r]=cur;
				cur=1ll*cur*(n-max(lim[i],r-i+1)+1)%p;
			}
		}
		for(int i=1;i<=n;++i)dp[i][i+n-1][1]=1;
		for(int i=n;i;--i)
		{
			for(int l=1;l+i-1<2*n;++l)
			{
				int r=l+i-1;
				if(r>=n)
				{
					ans[r-n+1]=(ans[r-n+1]+1ll*w[l][r]*dp[l][r][1])%p;
					ans[r-n]=(ans[r-n]-1ll*w[l][r]*dp[l][r][1])%p;
				}
				if(l<r)
				{
					dp[l+1][r][0]=(dp[l+1][r][0]+1ll*dp[l][r][0]*(n-max(lim[l],r-l+1)+1))%p;
					dp[l][r-1][1]=(dp[l][r-1][1]+1ll*dp[l][r][0]*(n-max(lim[r],r-l+1)+1))%p;
					if(lim[l]<=r-l+1)dp[l+1][r][0]=(dp[l+1][r][0]+dp[l][r][1])%p;
					dp[l][r-1][1]=(dp[l][r-1][1]+1ll*dp[l][r][1]*(n-max(lim[r],r-l+1)+1))%p;
				}
			}
		}
		ans[0]=1;for(int i=1;i<=n;++i)ans[0]=1ll*ans[0]*n%p;
		for(int i=1;i<=n;++i)ans[0]=(ans[0]-ans[i])%p;
		for(int i=0;i<=n;++i)printf("%d ",(ans[i]%p+p)%p);putchar(10);
	}
}
