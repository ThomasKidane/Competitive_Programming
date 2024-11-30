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

const int MAXN=1e6;
int maxarray[MAXN];


// pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
//     if (a.first > b.first) 
//         return a;
//     if (b.first > a.first)
//         return b;
//     return make_pair(a.first, a.second + b.second);
// }

void build(int a[], int v, int tl, int tr,int t[]) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm,t);
        build(a, v*2+1, tm+1, tr,t);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

int get_max(int v, int tl, int tr, int l, int r,int t[]) {
    if (l > r)
        return -INFINITY;
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return max(get_max(v*2, tl, tm, l, min(r, tm),t), 
                   get_max(v*2+1, tm+1, tr, max(l, tm+1), r,t));
}

void update(int v, int tl, int tr, int pos, int new_val,int t[]) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val,t);
        else
            update(v*2+1, tm+1, tr, pos, new_val,t);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

void solve(){
    string s;
    cin>>s;
    int v[s.size()+1];
    v[0]=0;
    forn(i,s.size()){
        if(s[i]=='('){
            v[i+1]=v[i]+1;
        } else {
            v[i+1]=v[i]-1;
        }
    }

    // maxarray[4*(s.size()+1)];
    build(v,1,0,s.size(),maxarray);

    map<int,vector<int>> vals;
    for(int i=1;i<=s.size();i++){
       vals[v[i]].push_back(i);
    }

    ll c=0;
    for(auto it=vals.begin();it!=vals.end();it++){
        if(it->first!=0){
            for(int i=0;i<it->ss.size()-1;i++){
                int r=i;
                for(int step=it->ss.size()-i;step>0;step/=2){
                    if(r+step<it->ss.size()){

                        while(get_max(1,0,s.size()+1,it->ss[i],it->ss[r+step],maxarray)<=2*(it->first) && r+step<it->ss.size()){r+=step;}
                    }                    
                }
                c+=(r-i+1)*(r-i)/2;
                i=r;
            }

        }
    }
    cout<<c<<endl;

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
