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
    int a[n];
    forn(i,n){
        cin>>a[i];
    }
    int d=a[0];
    bool allsame=true;
    for(int i=1;i<n;i++){
        if(a[i]!=a[i-1]){
            allsame=false;
            break;
        }
    }
    if(allsame){
    cout<<1<<endl;
    forn(i,n){
        cout<<1<<' ';
    }
    cout<<endl;
    return;
    }

    // int l=a[0];
    int c=0;
    bool there=false;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]){
            c=i;
            there=true;
            break;
        }
    }
    if(n%2==1){
        if(there){
        cout<<2<<endl;
        for(int i=0;i<n;i++){
            if(i>=c){
                cout<<1+(i)%2<<' ';
            } else {
                cout<<1+(i+1)%2<<' ';
            }
        }
        cout<<endl;
    } else {
        set<int> types;
        forn(i,n){
            types.insert(a[i]);
        }
        if(types.size()==2){
            cout<<2<<endl;
            forn(i,n){
                cout<<1+(i%2)<<' ';
            }
            cout<<endl;
        } else {
            cout<<3<<endl;
            forn(i,n-1){
                cout<<1+(i%3)<<' ';
            }
            if((n-1)%3==0){
                cout<<2<<' ';
            } else {
                cout<<1+((n-1)%3)<<' ';
            }
            cout<<endl;
        }
    }
    } else{
        cout<<2<<endl;
            forn(i,n){
                cout<<1+(i%2)<<' ';
            }
            cout<<endl;
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
