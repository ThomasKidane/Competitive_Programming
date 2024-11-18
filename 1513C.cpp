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

vector<vector<ll>> mul(10,vector<ll> (10,0));
vector<vector<vector<ll>>> prefM;


// Matrix Exponentiation
vector<ll> multiply(int t,vector<ll> v){    
    forn(b,20){
        if((t>>b)&(1)){

            vector<ll> nv(10);
            for(int row=0;row<10;row++){
                    ll ans=0;
                    for(int i=0;i<10;i++){
                        ans+=prefM[b][row][i]*v[i];
                        ans%=(1000000007);
                    }
                    nv[row]=ans;
            }
            v=nv;
        }
    }    
    return v;
}

void solve(){
    string n;
    int m;
    cin>>n>>m;
    

    vector<ll> d(10);
    
    map<int,int> vals;
    forn(i,n.size()){
        vals[int(n[i]-'0')]++;
        d[int(n[i]-'0')]=vals[int(n[i]-'0')];
    }

    ll S=0;
    d=multiply(m,d);
    forn(i,10){
        S+=d[i];
        S%=(1000000007);
    }
    

    cout<<S<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    forn(i,10){
        if(i<=8){
            mul[i+1][i]=1;
        }
        if(i==9){
            mul[0][i]=1;
            mul[1][i]=1;
        }
    }



    vector<vector<ll>> w(10,vector<ll> (10,0));
    forn(i,10){
        forn(j,10){
            w[i][j]=mul[i][j];
        }
    }
    prefM.push_back(w);

    forn(i,32){
        vector<vector<ll>> nw(10,vector<ll> (10,0));
        forn(i,10){
            nw[i][i]=1;
        }
        for(int row=0;row<10;row++){
            for(int col=0;col<10;col++){
                ll ans=0;
                for(int i=0;i<10;i++){
                    ans+=w[row][i]*w[i][col];
                    ans%=(1000000007);
                }
                nw[row][col]=ans;
            }
        }
        w=nw;
        prefM.push_back(w);
    }

    
    



    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
