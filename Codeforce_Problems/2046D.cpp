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
    int b[n];
    map<int,int> freq;
    forn(i,n){
        cin>>a[i];
        b[i]=a[i];
        freq[a[i]]++;
    }

    deque<ll> tob;
    sort(b,b+n);
    deque<int> first;
    int j=0;
    for(int i=0;i<n;i++){
        // dbgv(j);
        if(j<n){
            if(b[j]==a[i]){
                freq[a[i]]--;
                j++;
                while(j<n){
                    if(freq[b[j]]<=0){
                        j++;
                    } else {
                        break;
                    }
                }
            first.push_back(a[i]);
            // if(j==n-1)
            } else {
                // dbgv(a[i]+1);
                tob.push_back(a[i]+1);
                freq[a[i]]--;
                // dbgv(freq[a[i]]);
                // freq[a[i]+1]++;
            }
        } else {
            tob.push_back(a[i]+1);
        }
        
    }
    sort(tob.begin(),tob.end());
    // dbga(tob,tob.size());
    // dbga(first,first.size());
    while(!tob.empty()){
        first.push_back(tob.front());
        tob.pop_front();
    }
    int p=first.back();
    vector<int> vals;
    vals.push_back(p);
    first.pop_back();
    while(!first.empty()){
        if(first.back()>p){
            vals.push_back(first.back()+1);
        } else {
            vals.push_back(first.back());
        }
        p=min(first.back(),p);
        first.pop_back();
    }
    sort(vals.begin(),vals.end());

    dbga(vals,vals.size());

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
