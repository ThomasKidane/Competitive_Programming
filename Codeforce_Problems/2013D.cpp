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

ld getAvg(ld a[],int s,int e){
    ld S=0;
    for(int i=s;i<=e;i++){
        S+=a[i];
    }
    return S/(ld)abs(e-s+1);
}

void solve(){
    int n;
    cin>>n;
    ld a[n];
    forn(i,n){
        cin>>a[i];        
    }
    ld mx=a[0];
    ld mn=a[0];
    ld S=0;
    forn(i,n){
        if(mx<a[i])mx=a[i];
        if(mn>a[i])mn=a[i];
        S+=a[i];
    }

    if(n==1){
        cout<<0<<endl;
        return;
    } else if(n==2){
        if(a[0]<=a[n-1]){
            cout<<(ll)abs(a[n-1]-a[0])<<endl;
            return;
        } else {
            cout<<(ll)(a[0]-a[n-1])%2<<endl;
            return;
        }
    }
    else {
        if(a[n-1]==mx){
            if((ll)a[0]<(ll)getAvg(a,1,n-2)){
                cout<<(ll)(mx-a[0])<<endl;
            }
            else {
                cout<<(ll)(mx-(ll)getAvg(a,0,n-2))<<endl;
            }
        // cout<<(ll)ceil(mx-max(min(a[0],(ll)getAvg(a,1,n-2)),max(mn,(ll)getAvg(a,0,n-2))))<<endl;
        return;
    } else {
        if(a[0]==mn){
            // cout<<"Here"<<endl;
            cout<<(ll)min(max((ll)getAvg(a,1,n-2),(ll)a[n-1]),(ll)getAvg(a,1,n-1))-(ll)a[0]<<endl;
            return;
        } else {
            if(a[n-1]>a[0]){
                cout<<(ll)(abs(a[n-1]-floor(min((ll)a[0],min((ll)a[1],min((ll)getAvg(a,0,1),(ll)getAvg(a,1,n-2)))))))<<endl;
                return;
            } else {
                if((ll)getAvg(a,0,n-1)<=a[0] && (ll)getAvg(a,0,n-1)>=a[n-1]){
                    // cout<<"HERE"<<endl;
                    cout<<(ll)(ceil(ceil(getAvg(a,0,n-1))-(ll)floor(getAvg(a,0,n-1))))<<endl;
                } else if(ceil(getAvg(a,1,n-2))>a[0]){
                    
                    cout<<(ll)(ceil(abs(ceil(ceil(getAvg(a,1,n-1))))-a[0]))<<endl;
                } else {
                    
                    cout<<((ll)S%n==0?0:1)<<endl;
                }
                return;
            }
        }
    }
    }

    
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
