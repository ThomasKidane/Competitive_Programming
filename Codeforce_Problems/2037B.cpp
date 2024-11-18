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

vector<int> printDivisors(int n)
{
    // Note that this loop runs till square root
    vector<int> res;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            // If divisors are equal, print only one
            if (n / i == i){
                res.push_back(i);
            }
                // cout << i << " ";
            else {
                res.push_back(i);
            }
                // cout << i << " " << n / i << " ";
        }
    }
    return res;
}

void solve(){
    int n;
    cin>>n;
    int a[n];
    map<int,int> vals;
    forn(i,n){
        cin>>a[i];
        vals[a[i]]++;
    }

    vector<int> devisors=printDivisors(n-2);
    forn(i,devisors.size()){
        if(vals[devisors[i]]&&vals[(n-2)/devisors[i]]){
            cout<<devisors[i]<<' '<<(n-2)/devisors[i]<<endl;
            return;
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
