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

bool customS(pair<int,int> p1,pair<int,int> p2){
    if(p1.ss>p2.ss){
        return true;
    } else {
        if(p1.ss==p2.ss){
            return p1.ff>p2.ff;
        } else {
            return false;
        }
    }
}

void solve(){
    int n;
    cin>>n;
    // deque<pair<int,int>> sz;
    int maxX=0;
    int maxY=0;
    forn(i,n){
        int x,y;
        cin>>x>>y;
        if(x>maxX)maxX=x;
        if(y>maxY)maxY=y;
        // sz.push_back(make_pair(x,y));
    }
    // sort(sz.begin(),sz.end(),customS);
    // vector<pair<int,int>> actual;
    // actual.push_back(sz.front());
    // sz.pop_front();
    // int p;
    // if(n>1){
    //     p=2*actual.front().ss+sz.back().ff*2;
    // } else {
    //     p=2*actual.front().ss+actual.back().ff*2;
    // }
    
    // forn(i,n){
    //     if(sz.front().ff<=actual.back().ff){
    //         sz.pop_front();
    //     } else {
    //         actual.push_back(sz.front());
    //         sz.pop_front();
    //     }
    // }
    cout<<2*maxX+2*maxY <<endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
