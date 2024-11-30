#include<bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<endl
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<'\n';
void solve(){
    int m;
    ll x;
    cin>>m>>x;
    ll cost[m];
    ll happy[m];
    int h=0;
    // forn(i,m){
        
    // }
    forn(i,m){
        cin>>cost[i]>>happy[i];
        h+=happy[i];
    }
    vector<ll> costhappiness(h+1,INFINITY);
    costhappiness[0]=0;
    forn(i,m){
        for(int j=h;j>=happy[i];j--){
            if(costhappiness[j-happy[i]]<=(i)*x && costhappiness[j-happy[i]]+cost[i]<=(i)*x){
                // cout<<"Never"<<endl;
                // dbgv(min(costhappiness[j-happy[i]]+cost[i],costhappiness[j]));
                costhappiness[j]=min(costhappiness[j-happy[i]]+cost[i],costhappiness[j]);
            }            
        }
    }
    int ma=0;
    forn(i,h+1){
        if(costhappiness[i]<=(m*x)){
            ma=i;
        }
    }
    // dbgv(h);

    cout<<ma<<endl;
    

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
