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
    ll k;
    cin>>n>>k;
    if(n>61){
        string s="";
        s+=to_string(n);
        bool l=true;
        int p=n-1;
        for(int i=(int)log2(k);i>=0;i--){
            if((k)>>i&(1)){
                l=!l;
            }
            if(!l){
                s=to_string(p)+" "+s;
                p--;
            } else {
                s=s+" "+to_string(p);
                p--;
            }
            // l=true;
        }
        if(p>0){
            if(!l){
                while(p>-1){
                    s=to_string(p)+" "+s;
                                    p--;
                }
            } else{
                while(p>=0){
s=s+" "+to_string(p);
                p--;
                }

            }
            l=true;
        }
        cout<<s<<endl;
    } else {
        if(1ll<<(n-1)<k){
            cout<<-1<<endl;
            return;
        } else {
        string s="";
        s+=to_string(n);
        bool l=true;
        int p=n-1;
        for(int i=(int)log2(k);i>=0;i--){
            if((k-1)>>i&(1)){
                l=!l;
            }
            if(!l){
                s=to_string(p)+" "+s;
                p--;
            } else {
                s=s+" "+to_string(p);
                p--;
            }
            t=tru;e
            // l=true;
        }
        if(p>0){
            if(l){
                while(p>-1){
                    s=to_string(p)+" "+s;
                                    p--;
                }
            } else{
                while(p>=0){
s=s+" "+to_string(p);
                p--;
                }

            }

        }
                cout<<s<<endl;
        }

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
