#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<endl
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<'\n';

map<string,int> notemapping;


struct Vertex {
    int left, right;
    int sum = 0;
    Vertex *left_child = nullptr, *right_child = nullptr;

    Vertex(int lb, int rb) {
        left = lb;
        right = rb;
    }

    void extend() {
        if (!left_child && left + 1 < right) {
            int t = (left + right) / 2;
            left_child = new Vertex(left, t);
            right_child = new Vertex(t, right);
        }
    }

    void add(int k, int x) {
        extend();
        sum += x;
        if (left_child) {
            if (k < left_child->right)
                left_child->add(k, x);
            else
                right_child->add(k, x);
        }
    }

    int get_sum(int lq, int rq) {
        if (lq <= left && right <= rq)
            return sum;
        if (max(left, lq) >= min(right, rq))
            return 0;
        extend();
        return left_child->get_sum(lq, rq) + right_child->get_sum(lq, rq);
    }
};

void solve(){
    int m,n;
    cin>>n>>m;
    int a[n];
    forn(i,n){
        cin>>a[i];
    }

    pair<int,int> vals[m];
    forn(i,m){
        int d;
        cin>>d;
        string s;
        cin>>s;
        vals[i].ff=notemapping[s];
        
        vals[i].ss=d;
    }   
    int c=0;
    int cur_matching;

    vector<int> rights(8,-1);
    map<int,map<int,int>> ps;
    // vector<vector<int>> prefs(8,vector<int>(n+1,))
    vector<Vertex> segs(9,Vertex(0,int(1e9+20)));
    forn(i,n){
        // cout<<"Here"<<endl;
        if(i+1==vals[c].ss){
            cur_matching=vals[c].ff;
            c++;
        }
        rights[cur_matching]=a[i];
        ps[a[i]][cur_matching]++;
        segs[cur_matching].add(a[i],1);
    }

    int cc=1;
    ll res=0;
    for(auto it=ps.begin();it!=ps.end();it++){
        if(it->ff==rights[cc]){
            forn(j,8){
                if(j+1!=cc){
                    
                    res+=segs[j+1].get_sum(it->ff))
                }
                
            }
        }
    }

    cout<<segs[3].get_sum(19,21)<<endl;//Get Sum is end exclusive

    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    // map<int,int> notemapping;
    notemapping["ppp"]=1;
    notemapping["pp"]=2;
    notemapping["p"]=3;
    notemapping["mp"]=4;
    notemapping["mf"]=5;
    notemapping["f"]=6;
    notemapping["ff"]=7;
    notemapping["fff"]=8;

    
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
