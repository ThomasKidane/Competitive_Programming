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
#define mk make_pair
// const ll MOD=998244353;

bool decompose(ll n,map<ll,int>&vala){
    if(vala[n]>0){
        vala[n]-=1;
        return true;
    } else {
        if(n==1){
            return false;
        } else {
            bool val=true;
            vector<ll> v={(n+1)/2,n/2};
            forn(i,2){
                val=val&&decompose(v[i],vala);
            }
            return val;
        }
    }
}

void solve(){
    int m,n;
    cin>>n>>m;
    ll a[n];
    ll b[m];
    ll s1=0;
    ll s2=0;
    map<ll,int> vala;
    map<ll,int> valb;
    forn(i,n){
        cin>>a[i];
        vala[a[i]]++;
        s1+=a[i];
    }
    forn(i,m){
        cin>>b[i];
        valb[b[i]]++;
        s2+=b[i];
    }
    vector<ll> nonsim;
    for(auto it=valb.begin();it!=valb.end();it++){
        int c=min(it->ss,vala[it->ff]);
        vala[it->ff]-=c;
        it->ss-=c;
        forn(i,it->ss){
            nonsim.push_back(it->ff);
        }
    }
    // sort(nonsim);
    forn(i,nonsim.size()){
        if(!decompose(nonsim[i],vala)){
            cout<<"No"<<endl;
            return;
        }
    }
    if(s1==s2){
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
    }
    

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
