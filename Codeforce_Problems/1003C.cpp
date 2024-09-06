#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define forn(i,n) for(int i=0;i<n;i++)

signed main(){
    int n,k;
    cin>>n>>k;
	//cout.precision(15);
	cerr << fixed;
	cout << fixed;
    long double Max=0;
    int a[n];
    int pf[n+1]={0};
    for(int i=0;i<n;i++)cin>>a[i];
    forn(i,n) pf[i+1]=pf[i]+a[i];
    for(int x=0;x<=n-k;x++){
        for(int y=x+k-1;y<n;y++){
            Max=max(Max,(long double)(pf[y+1]-pf[x])/(y-x+1));
        }
    }
    cout<<setprecision(15)<<Max<<'\n';

}



