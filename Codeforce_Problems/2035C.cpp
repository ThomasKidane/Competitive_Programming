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

void printSeq(int n){
    if((n & (n - 1)) == 0){
        for(int i=1;i<=n;i++){
            if(i!=1 && i!=3 && i!=n-2 && i!=n-1 && i!=n){
                if(i!=n-3){
                    cout<<i<<' ';
                } else {
                    cout<<i;
                }
                
            }
        }
        cout<<" 1 3 "<<n-2<<' '<<n-1<<' '<<n;
    } else {
        for(int i=1;i<=n;i++){
            if(i!=n && i!=n-2 && i!=(1<<(int)(log2(n)))-1){
                cout<<i<<' ';
            }
            
        }
        cout<<n<<' '<<n-2<<' '<<(1<<(int)(log2(n)))-1;
    }
}

void solve(){
    int n;
    cin>>n;
    if(n%2==0){
        cout<<(ll)pow(2,(int)log2(n)+1)-1<<endl;
        printSeq(n);cout<<endl;
    } else {
        if(n==5){
            cout<<5<<endl;
            cout<<"2 1 3 4 5"<<endl;
        } else {
            cout<<n<<endl;
            printSeq(n-1);
            // cout<<' '<<n;
            cout<<' '<<n<<endl;
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
