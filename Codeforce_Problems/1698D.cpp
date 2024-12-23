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

int count(int l,int r,vector<int> vals){
    int c=0;
    for(int i=0;i<vals.size();i++){
        if(vals[i]>=l && vals[i]<=r){
            c++;
        }
    }

    return c;
}

void solve(){
    int n;
    cin>>n;
    int l=1,r=n;
    while(r>l){
        cout<<"? "<<l<<' '<<(r+l)/2<<endl;
        vector<int> vals;
        for(int i=l;i<=(r+l)/2;i++){
            int d;
            cin>>d;
            vals.push_back(d);
        }
        if(count(l,(l+r)/2,vals)%2==1){
            r=(r+l)/2;
        } else {
            l=(r+l)/2+1;
        }
    }

    cout<<"! "<<l<<endl;
}

int main() {
    // ios_base::sync/_with_stdio(false);
    // cin.tie(0);

    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
