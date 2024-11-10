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
    int a[n];
    cin>>n;
    vector<vector<int>> dc(120);

    forn(i,n){
        cin>>a[i];
        dc[a[i]].push_back(i);
        }
    int tw=0;
    // int thr=0;
    forn(i,110){
        if(dc[i].size()>=2){
            tw++;
        }
    }
    // cout<<"Here"<<endl;
    int r=1;
    int res[n];
    if(tw<2){
        cout<<-1<<endl;
        return;
    } else {
        forn(i,110){
            if(dc[i].size()>0){
                if(dc[i].size()==1){
                    res[dc[i][0]]=1;
                } else {
                    if(r==1){
                        res[dc[i].front()]=1;
                        forn(j,dc[i].size()-1){
                            res[dc[i][j+1]]=2;
                        }
                        r++;
                    } else {
                        res[dc[i].front()]=2;
                        forn(j,dc[i].size()-1){
                            res[dc[i][j+1]]=3;
                        }
                    }
                }
            }
        }
    }
    cout<<"Here"<<endl;
    // dbga(res,n);
    forn(i,n){
        cout<<res[i]<<' ';
    }
    return;
    
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
