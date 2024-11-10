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
    int k,n;
    cin>>n>>k;
    
    string inp;
    
    cin>>inp;
    // dbgv(inp);
    int l[k];
    int r[k];
    forn(i,k){
        cin>>l[i];
        l[i]--;
    }
    forn(i,k){
        cin>>r[i];
        r[i]--;
    }

    int q;
    cin>>q;
    
    vector<int> x(q);
    forn(i,q){
        cin>>x[i];
        x[i]--;
    }
    vector<int> rev(n);
    forn(i,n){
        rev[i]=0;
    }
    // dbgv(x[0]);
    // memset(rev,0,sizeof(rev));
    // dbgv(q);
    // cout<<"q"<<q<<endl;
    forn(i,q){
        int j=lower_bound(r,r+k,x[i])-r;
        rev[min(l[j]+r[j]-x[i],x[i])]++;
    }
    // string res;
    // forn(i,n){
    //     res+=' ';
    // }
    // forn(i,n){
    //     cout
    // }
    // dbga(rev,n);
    forn(v,k){
        int c=0;
        for(int i=l[v];i<(r[v]+l[v]+1)/2;i++){
            // dbgv(i);
            c+=rev[i];
            if(c%2==1){
                char temp=inp[i];
                inp[i]=inp[r[v]-(i-l[v])];
                inp[r[v]-(i-l[v])]=temp;
            }
        }
    }

    cout<<inp<<endl;

}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
