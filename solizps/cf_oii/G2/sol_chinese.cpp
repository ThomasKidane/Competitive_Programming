#include <bits/stdc++.h>
#define N 600011
#define ll long long
#define TIME chrono::steady_clock::now().time_since_epoch().count()
using namespace std;
int t,n,a[N],l[N],r[N],fa[N],dif[N],CNT;
int get(int a){return fa[a]==a?a:fa[a]=get(fa[a]);}
void merge(int a,int b)
{
a=get(a);b=get(b);
if(a==b)return;
fa[b]=a;
dif[a]=dif[b];
}
vector<int> vr[N];
vector<int> vv;
int m,cur,ans;
bool has[N];
int solve(int k)
{
// ++CNT;
int cc=0,lstr=0,pt=1;
int ex=0;
for(int i=1;i<=m;++i)fa[i]=i,dif[i]=0;
while(pt<=m)
{
if(pt-1>lstr&&!has[pt-1])merge(pt-1,pt);
has[pt]=0;
for(int l:vr[pt])if(l>lstr)
{
int lp=get(l);
has[pt]=1;++dif[get(pt)];
if(lp-1==lstr)++ex;
else
{
if(!--dif[get(lp-1)])merge(lp-1,l);
}
}
if(ex>=k)
{
++cc;ex=0;
lstr=pt;
}
++pt;
}
ans=max(ans,cc*k);
return cc;
}
void solve(int L,int R,int lcc,int rcc)
{
if(lcc==rcc||R<=L+1)return;
int M=L+R>>1;
int mcc=solve(M);
solve(L,M,lcc,mcc);solve(M,R,mcc,rcc);
}
int main()
{
scanf("%d",&t);while(t--)
{
scanf("%d",&n);vv.clear();
for(int i=1;i<=n;++i)scanf("%d",l+i),vv.push_back(l[i]);
for(int i=1;i<=n;++i)scanf("%d",r+i),vv.push_back(r[i]);
sort(vv.begin(),vv.end());vv.resize(unique(vv.begin(),vv.end())-vv.begin());
for(int i=1;i<=n;++i)l[i]=lower_bound(vv.begin(),vv.end(),l[i])-vv.begin()+1;
for(int i=1;i<=n;++i)r[i]=lower_bound(vv.begin(),vv.end(),r[i])-vv.begin()+1;
m=vv.size();
for(int i=1;i<=m;++i)vr[i].clear();
for(int i=1;i<=n;++i)vr[r[i]].push_back(l[i]);
ans=0;
solve(0,n+1,-1e9,1e9);
printf("%d\n",ans);
}
// printf("CNT:%d\n",CNT);
}
