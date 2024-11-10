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
void solve(int k){
    int n,m,q;
    cin>>n>>m>>q;
    int a[n];
    int b[m];
    forn(i,n){
        cin>>a[i];
    }
    forn(i,m){
        cin>>b[i];
    }
    int done[n+1];
    forn(i,n+1){
        done[i]=0;
    }
    int i=0;
    int j=0;
    // if(k==25){
    //     dbga(a,n);
    //     dbga(b,m);
    // }
    while(j!=m && i!=n){
        // dbgv(i);
        // dbgv(j);
        // dbgv(a[i]);
        // dbgv(b[j]);
        if(a[i]==b[j]){
            done[a[i]]=1;
            i++;
            j++;            
        } else{
            if(done[b[j]]==1){
                j++;
                continue;
            } else {
                cout<<"TIDAK"<<endl;
                return;
            }
        }
    } 
    cout<<"YA"<<endl;
}

int main() {
    int T = 1;
    cin >> T;
    int n=T;
    while(T--){
        solve(n-T);
    }
    return 0;
}
