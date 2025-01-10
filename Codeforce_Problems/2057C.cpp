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
    int l,r;
    cin>>l>>r;
    ll res=0;
    ll a=0,b=0,c=0;

    for(int i=29;i>=0;i--){
        if(r-l+1>=(1ll<<i)){
            res+=(1ll<<i+1);
            int cc=0;
            
            if(min(a,min(b,c))==a){
                if(((a|(1<<i))<=r) && (a|(1<<i))!=b && (a|(1<<i))!=c && cc<1){
                    a|=(1<<i);
                    cc++;
                }
                if(min(b,c)==b){
                    if((((b|(1<<i))<=r) && (b|(1<<i))!=a && (a|(1<<i))!=c) && cc<1){
                        b|=(1<<i);
                        cc++;
                    }if(((c|(1<<i))<=r) && (c|(1<<i))!=a && (c|(1<<i))!=b  && cc<1){
                        c|=(1<<i);
                        cc++;
                    }
                }else {
                    if(((c|(1<<i))<=r) && (c|(1<<i))!=a && (c|(1<<i))!=b  && cc<1){
                        c|=(1<<i);
                        cc++;
                    }if((((b|(1<<i))<=r) && (b|(1<<i))!=a && (a|(1<<i))!=c) && cc<1){
                        b|=(1<<i);
                        cc++;
                    }
                }
            } else {
                if(min(b,c)==c){
                    if(((c|(1<<i))<=r) && (c|(1<<i))!=a && (c|(1<<i))!=b  && cc<1){
                        c|=(1<<i);
                        cc++;
                    }
                    if(min(a,b)==b){
                       if((((b|(1<<i))<=r) && (b|(1<<i))!=a && (a|(1<<i))!=c) && cc<1){
                        b|=(1<<i);
                        cc++;
                    }
                    if(((a|(1<<i))<=r) && (a|(1<<i))!=b && (a|(1<<i))!=c && cc<1){
                    a|=(1<<i);
                    cc++;
                }

                    } else {
                        if(((a|(1<<i))<=r) && (a|(1<<i))!=b && (a|(1<<i))!=c && cc<1){
                    a|=(1<<i);
                    cc++;
                }
                if((((b|(1<<i))<=r) && (b|(1<<i))!=a && (a|(1<<i))!=c) && cc<1){
                        b|=(1<<i);
                        cc++;
                    }
                    }
                } else {
                    if((((b|(1<<i))<=r) && (b|(1<<i))!=a && (a|(1<<i))!=c) && cc<1){
                        b|=(1<<i);
                        cc++;
                    }
                    
                    if(min(a,c)==c){
                       if(((c|(1<<i))<=r) && (c|(1<<i))!=a && (c|(1<<i))!=b  && cc<1){
                        c|=(1<<i);
                        cc++;
                    }
                    if(((a|(1<<i))<=r) && (a|(1<<i))!=b && (a|(1<<i))!=c && cc<1){
                    a|=(1<<i);
                    cc++;
                }

                    } else {
                        if(((a|(1<<i))<=r) && (a|(1<<i))!=b && (a|(1<<i))!=c && cc<1){
                    a|=(1<<i);
                    cc++;
                }
                if(((c|(1<<i))<=r) && (c|(1<<i))!=a && (c|(1<<i))!=b  && cc<1){
                        c|=(1<<i);
                        cc++;
                    }
                    }
                }
            }
           

        } else {
            if(((1ll<<i)&l) ^ ((1ll<<i)&r)){
                res+=(1ll<<i+1);
                int cc=0;
              if(min(a,min(b,c))==a){
                if(((a|(1<<i))<=r) && (a|(1<<i))!=b && (a|(1<<i))!=c && cc<1){
                    a|=(1<<i);
                    cc++;
                }
                if(min(b,c)==b){
                    if(((b|(1<<i))<=r) && (b|(1<<i))!=a && (a|(1<<i))!=c && cc<1){
                        b|=(1<<i);
                        cc++;
                    }if(((c|(1<<i))<=r) && (c|(1<<i))!=a && (c|(1<<i))!=b  && cc<1){
                        c|=(1<<i);
                        cc++;
                    }
                }else {
                    if(((c|(1<<i))<=r) && (c|(1<<i))!=a && (c|(1<<i))!=b  && cc<1){
                        c|=(1<<i);
                        cc++;
                    }if(((b|(1<<i))<=r) && (b|(1<<i))!=a && (a|(1<<i))!=c && cc<1){
                        b|=(1<<i);
                        cc++;
                    }
                }
            } else {
                if(min(b,c)==c){
                    if(((c|(1<<i))<=r) && (c|(1<<i))!=a && (c|(1<<i))!=b  && cc<1){
                        c|=(1<<i);
                        cc++;
                    }
                    if(min(a,b)==b){
                       if(((b|(1<<i))<=r) && (b|(1<<i))!=a && (a|(1<<i))!=c && cc<1){
                        b|=(1<<i);
                        cc++;
                    }
                    if(((a|(1<<i))<=r) && (a|(1<<i))!=b && (a|(1<<i))!=c && cc<1){
                    a|=(1<<i);
                    cc++;
                }

                    } else {
                        if(((a|(1<<i))<=r) && (a|(1<<i))!=b && (a|(1<<i))!=c && cc<1){
                    a|=(1<<i);
                    cc++;
                }
                if(((b|(1<<i))<=r) && (b|(1<<i))!=a && (a|(1<<i))!=c && cc<1){
                        b|=(1<<i);
                        cc++;
                    }
                    }
                } else {
                    if(((b|(1<<i))<=r) && (b|(1<<i))!=a && (a|(1<<i))!=c && cc<1){
                        b|=(1<<i);
                        cc++;
                    }
                    
                    if(min(a,c)==c){
                       if(((c|(1<<i))<=r) && (c|(1<<i))!=a && (c|(1<<i))!=b  && cc<1){
                        c|=(1<<i);
                        cc++;
                    }
                    if(((a|(1<<i))<=r) && (a|(1<<i))!=b && (a|(1<<i))!=c && cc<1){
                    a|=(1<<i);
                    cc++;
                }

                    } else {
                        if(((a|(1<<i))<=r) && (a|(1<<i))!=b && (a|(1<<i))!=c && cc<1){
                    a|=(1<<i);
                    cc++;
                }
                if(((c|(1<<i))<=r) && (c|(1<<i))!=a && (c|(1<<i))!=b  && cc<1){
                        c|=(1<<i);
                        cc++;
                    }
                    }
                }
            }
       

            }
        }
    }

    cout<<a<<' '<<b<<' '<<c;
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
