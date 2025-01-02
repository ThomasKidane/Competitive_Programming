#include<bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
// #define endl "\n";
#define ff first
#define ss second

#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<endl
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<'\n';

int p=333;
int k=2222;
int testanswer(int p,int k,int l,int r){
    // dbgv(p);
    // dbgv(l);
    // dbgv(r);
    // dbgv(k);
    if(p>=l && p<=r){
        if(r-l+1>=k){
            // cout<<"he"<<endl;
            return 0;
        } else {
            return 1;
        }
    } else {
        if(r-l+1>=k){
            return 1;
        } else {
            return 0;
        }
    }
}

int ask(int l,int r){
    // cout<<"? "<<l<<' '<<r<<endl;
    // int v;
    // cin>>v;
    return testanswer(::p,::k,l,r);
}



void solve(){
    int n;
    cin>>n;

    int p,k;
    cin>>p>>k;
    ::p=p;
    ::k=k;
    // dbgv(::p);
    // dbgv(::k);
    // dbgv(ask(1,2));
    // dbgv(ask(3,4));
    // dbgv(ask(1,n/2));


    if(ask(1,n/2)){
        // first one is one
        int v1=ask(1,n/4);
        int v2=ask(n/4+1,n/2);
        
        // no 1 and k<=n/2,k>n/4 if v1==0
        // dbgv(v1);
        // dbgv(v2);
        if(v1==v2){
            if(v1==0){
                int i=n/4;
                for(int step=n/8;step>0;step/=2){
                    if(i+step>=n/2){
                        continue;
                    }
                    while(ask(1,i+step)==0){
                        i+=step;
                        if(i+step>=n/2){
                            break;
                        }
                    }
                }
                // cout<<'h'<<endl;
                cout<<"! "<<i+1<<endl;
            } else {
                // k>n/4
                int i=1;
                for(int step=n/4;step>0;step/=2){
                    if(i+step>=n/2){
                        continue;
                    }
                    while(ask(1,i+step)==0){
                        i+=step;
                        if(i+step>=n/2){
                            break;
                        }
                    }
                }
                cout<<"! "<<i+1<<endl;
            }
            
            
        } else {
            // k>n/2
            int i=n/2+1;
            for(int step=n/4;step>0;step/=2){
                if(i+step>=n){
                    continue;
                }
                while(ask(1,(i+step))==1){
                    i+=step;
                    if(i+step>=n){
                        break;
                    }
                }
            }
            cout<<"! "<<i+1<<endl;
            // cout<<"Her"<<endl;
            // for(int step=n/4)
        }
    } else {
        int v1=ask(1,n/4);
        int v2=ask(n/4+1,n/2);
        if(v1==v2){
            // k>n/2
            int i=n/2-1;
            for(int step=n/4;step>0;step/=2){
                if(i+step>=n){
                    continue;
                }
                while(ask(n-(i+step),n)==1){
                    i+=step;
                    if(i+step>=n){
                        break;
                    }
                }
            }
            cout<<"! "<<i+2<<endl;
            
            
            
        } else {
            // k>n/2
            int i=1;
            for(int step=n/4;step>0;step/=2){
                if(i+step>=n/2){
                    continue;
                }
                while(ask(n-(i+step),n)==0){
                    i+=step;
                    if(i+step>=n/2){
                        break;
                    }
                }
            }
            cout<<"! "<<i+1<<endl;
            // cout<<"here"<<endl;
            // for(int step=n/4)
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
