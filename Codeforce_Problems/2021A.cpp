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

ll findM(vector<ll> v1){
    ll M=v1[0];
    forn(i,v1.size()){
        if(M<v1[i])M=v1[i];
    }
    return M;
}

// ll findMa(vector<ll> v1){
//     ll M=v1[0];
//     forn(i,v1.size()){
//         if(M<v1[i])M=v1[i];
//     }
//     return M;
// }

void solve(){
    int n;
    cin>>n;
    ll d;
    deque<ll> array;
    
    forn(i,n){
        cin>>d;
        array.push_back(d);
    }  
    sort(array.begin(),array.end());
    while(array.size()>2){
        ll a=array[0];
        ll b=array[1];
        // ll c=array.back();
        array.pop_front();
        array.pop_front();
        // array.pop_back();
        array.push_back((a+b)/2);
        // array.push_back(c);
        sort(array.begin(),array.end());
    }
    if(array.size()>1){
        cout<<(array[0]+array[1])/2<<endl;
    } else {
        cout<<array[0]<<endl;
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
