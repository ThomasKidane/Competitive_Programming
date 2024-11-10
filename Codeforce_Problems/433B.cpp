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
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> s(n);
    forn(i,n){
        cin>>a[i];
        s[i]=a[i];
    }

    sort(s.begin(),s.end());
    int q;
    cin>>q;
    
    

    // preprocessing
    int len = (int) sqrt (n + .0) + 1; // size of the block and the number of blocks
    vector<ll> b (len);
    vector<ll> b1(len);
    for (int i=0; i<n; ++i){
        b[i / len] += a[i];
        b1[i / len] += s[i];
    }
    // dbga(b,b.size());
    forn(u,q){
        int v;
        cin>>v;
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        if(v==1){
            ll sum = 0;
            int c_l = l / len,   c_r = r / len;
            if (c_l == c_r)
                for (int i=l; i<=r; ++i)
                    sum += a[i];
            else {
                for (int i=l, end=(c_l+1)*len-1; i<=end; ++i)
                    sum += a[i];
                for (int i=c_l+1; i<=c_r-1; ++i)
                    sum += b[i];
                for (int i=c_r*len; i<=r; ++i)
                    sum += a[i];
            }
            cout<<sum<<endl;
        } else {
            ll sum = 0;
            int c_l = l / len,   c_r = r / len;
            if (c_l == c_r)
                for (int i=l; i<=r; ++i)
                    sum += s[i];
            else {
                for (int i=l, end=(c_l+1)*len-1; i<=end; ++i)
                    sum += s[i];
                for (int i=c_l+1; i<=c_r-1; ++i)
                    sum += b1[i];
                for (int i=c_r*len; i<=r; ++i)
                    sum += s[i];
            }
            cout<<sum<<endl;
        }
        
    }


    
}

int main() {
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
