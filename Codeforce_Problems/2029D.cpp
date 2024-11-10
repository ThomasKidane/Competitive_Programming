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
void solve(vector<bool> &is_prime){
    int n;
    cin>>n;
    int c=0;
    vector<int> a(n);
    int lp;
    forn(i,n){
        int d;
        cin>>d;
        if(is_prime[d]){c++;lp=d;}
        a[i]=d;
    }
    if(c>1){
        cout<<-1<<endl;
    } else if(c==1){
        
    } else {
        cout<<2<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n=100000;
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }

    vector<int,map<int,int>>aval;// Atmost one thousand entries


    int T = 1;
    cin >> T;
    while(T--){
        solve(is_prime);
    }
    return 0;
}
