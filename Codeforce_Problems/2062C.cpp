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

vector<ll> dif(vector<ll>&a){
    vector<ll> res;
    forn(i,a.size()-1){
        res.push_back(a[i+1]-a[i]);
    }
    return res;
}

ll sum(vector<ll>&a){
    ll s=0;
    forn(i,a.size()){
        s+=a[i];
    }
    return s;
}
vector<ll> rev(vector<ll>&a){
    vector<ll> res=a;
    reverse(res.begin(),res.end());
    return res;
}
void solve(){
    int n;
    cin>>n;
    vector<ll> a;
    forn(i,n){
        ll d;
        cin>>d;
        a.push_back(d);         
    }
    ll S=sum(a);
    a=rev(a);
    while(a.size()>1){
        a=dif(a);
        S=max(abs(sum(a)),S);
    }
    if(n>1){
        S=max(abs(sum(a)),S);
    }

    cout<<S<<endl;
    

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
