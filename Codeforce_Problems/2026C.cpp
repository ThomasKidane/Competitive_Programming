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
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll cost=0;
    // deque<int> elems;
    ll R=0;
    // int c=0;
    deque<int> elems1; // The Paired but should be moved
    deque<int> elems2; // Unpaired
    deque<int> elems3; // Paired 2nd, will die
    vector<int> reallyD;
   

    // bool f=false;
    // int c=0;
    for(int i=n-1;i>=0;i--){    
        // dbgv(elems1.size());
        // dbgv(elems2.size());
        // dbgv(elems3.size());
        // dbgv(reallyD.size());
        if(s[i]=='1'){
            if(elems1.size()==0){
                if(elems2.size()>0){
                    elems3.push_front(elems2.back());
                    elems2.pop_back();
                    elems1.push_front(i+1);
                } else if(elems3.size()==0){
                    elems2.push_back(i+1);
                } else {
                    elems1.push_front(i+1);
                }
            } else {
                if(elems3.size()<elems1.size()){
                    elems3.push_front(elems1.back());
                    elems1.pop_back();
                    elems1.push_front(i+1);
                } else {
                    elems1.push_front(i+1);
                }
            }

        } else {
            if(elems3.size()>0){
                reallyD.push_back(elems3.back());
                elems3.pop_back();
                if(elems3.size()<elems1.size()){
                    elems3.push_front(elems1.back());
                    elems1.pop_back();
                    // elems1.push_front(i++);
                }
            } else if(elems1.size()>0){
                reallyD.push_back(elems1.back());
                elems1.pop_back();
            } else if(elems2.size()>0){
                reallyD.push_back(elems2.back());
                elems2.pop_back();
            }
        }
    }
    forn(i,reallyD.size()){
        // dbgv(reallyD[i]);
        R+=reallyD[i];
    }
    // dbgv
    for(int i=elems3.size()-1;i>=max(0ll,(ll)elems3.size()-(ll)min(elems1.size(),elems3.size()));i--){
        // dbgv(elems3[i]);
        R+=elems3[i];
    }
    
    cout<<((n)*(n+1))/2-R<<endl;
    
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
