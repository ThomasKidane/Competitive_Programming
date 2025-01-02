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

#define MOD 998244353;


const int mod = 998244353;

int bin_exp(int a, int b) {
    if (b == 0) {
        return 1;
    }
    if (b % 2) {
        return bin_exp(a, b - 1) * 1LL * a % mod;
    }
    int res = bin_exp(a, b / 2);
    return res * 1LL * res % mod;
}

int inv(int a) {
    return bin_exp(a, mod - 2);
}

void solve(){
    int n,q;
    cin>>n>>q;
    pair<ll,int> a[n];
    pair<ll,int> b[n];
    forn(i,n){
        cin>>a[i].ff;
        a[i].ss=i;
    }
    forn(i,n){
        cin>>b[i].ff;
        b[i].ss=i;
    }

    sort(a,a+n);
    sort(b,b+n);
    
    // forn(i,n){
    //     cout<<b[i].ff<<' ';
    // }
    // cout<<endl;
    map<int,int> toa;
    map<int,int> tob;
    map<int,int> reva;
    map<int,int> revb;
    forn(i,n){
        toa[a[i].ss]=i;
        reva[i]=a[i].ss;
    }
    forn(i,n){
        tob[b[i].ss]=i;
        revb[i]=b[i].ss;
    }
    ll res=1;
    forn(i,n){
        res*=min(a[i].ff,b[i].ff);
        res%=MOD;
    }
    
    
    cout<<res<<' ';
    // dbgv(res);
    forn(i,q){
        int o,x;
        cin>>o>>x;
        x--;
        
        if(o==1){
            // adjust ax+=1
            if(toa[x]==n-1){
                // cout<<"Here"<<endl;
                // res+=b[n-1].ff;
                res*=inv(min(a[n-1].ff,b[n-1].ff));
                res%=MOD;
                if(res<0)res+=MOD;
                
                // dbgv(res);
                // if(res<0)res+=MOD;
                a[n-1].ff++;
                res*=min(a[n-1].ff,b[n-1].ff);
                res%=MOD;
                if(res<0)res+=MOD;
            } else {
                if(a[toa[x]].ff==a[toa[x]+1].ff){
                    int i=0;
                    for(int step=max(1,n/2);step>0;step/=2){
                        
                        if(i+step>=n){
                            continue;
                        }
                        while(a[i+step].ff<=a[toa[x]].ff){
                            i+=step;
                            if(i+step>=n){
                               break;
                        }
                        }
                    }
                    toa[reva[i]]=toa[x];
                    int l=reva[i];
                    reva[i]=x;
                    int xx=toa[x];
                    toa[x]=i;
                    reva[xx]=l;
                    // a[toa[x]].ff++;

                }
                if(toa[x]==n-1){
                    // cout<<"Here"<<endl;
                    // res+=b[n-1].ff;
                    res*=inv(min(a[n-1].ff,b[n-1].ff));
                    res%=MOD;
                    if(res<0)res+=MOD;
                    
                    // dbgv(res);
                    // if(res<0)res+=MOD;
                    a[n-1].ff++;
                    res*=min(a[n-1].ff,b[n-1].ff);
                    res%=MOD;
                    if(res<0)res+=MOD;
                
                } else {
                    res*=inv(min(a[toa[x]].ff,b[toa[x]].ff));
                    // res+=b[toa[x]].ff;
                    a[toa[x]].ff++;
                    res%=MOD;
                    if(res<0)res+=MOD;
                    res*=(min(a[toa[x]].ff,b[toa[x]].ff));
                    // if(res<0)res+=MOD;
                    res%=MOD;
                    if(res<0)res+=MOD;
                    
                }
            }
            cout<<res<<' ';
            // dbgv(res);
        } else {
            // cout<<"here"<<endl;
            if(tob[x]==n-1){
                res*=inv(min(b[tob[x]].ff,a[n-1].ff));
                b[tob[x]].ff++;
                res%=MOD;
                if(res<0)res+=MOD;
                res*=min(b[tob[x]].ff,a[n-1].ff);
                res%=MOD;
                if(res<0)res+=MOD;
            } else {
                if(b[tob[x]].ff==b[tob[x]+1].ff){
                    int i=0;
                    for(int step=max(1,n/2);step>0;step/=2){
                        
                        if(i+step>=n){
                            continue;
                        }
                        while(b[i+step].ff<=b[tob[x]].ff){
                            i+=step;
                            if(i+step>=n){
                               break;
                        }
                        }
                    }
                    tob[revb[i]]=tob[x];
                    int l=revb[i];
                    revb[i]=x;
                    int xx=tob[x];
                    tob[x]=i;
                    revb[xx]=l;
                    // a[toa[x]].ff++;

                }
                if(tob[x]==n-1){
                res*=inv(min(b[tob[x]].ff,a[n-1].ff));
                b[tob[x]].ff++;
                res%=MOD;
                if(res<0)res+=MOD;
                res*=min(b[tob[x]].ff,a[n-1].ff);
                res%=MOD;
                if(res<0)res+=MOD;
            }else {
                    // cout<<"her"<<endl;/
                    res*=inv(min(b[tob[x]].ff,a[tob[x]].ff));
                    // res+=b[toa[x]].ff;
                    b[tob[x]].ff++;
                    res%=MOD;
                    if(res<0)res+=MOD;
                    res*=(min(b[tob[x]].ff,a[tob[x]].ff));
                    res%=MOD;
                    if(res<0)res+=MOD;
                    
                }
            }
            cout<<res<<' ';
            // dbgv(res);
        }
    }

    cout<<endl;


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
