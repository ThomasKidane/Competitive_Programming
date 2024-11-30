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
    vector<set<int>> inds(3,set<int> ());
    // vector<priority_queue<int, vector<int>, greater<int>>> inds(3,priority_queue <int, vector<int>, greater<int>> ());
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        inds[a].insert(i);
    }
    bool zerodone=inds[0].size()==0?true:false;
    bool onedone=false;
    string res="";
    int c=0;
    for(int i=1;i<=n;i++){
        if(zerodone){
            // cout<<"Hrerre"<<endl;
            if(onedone){
                break;
            } else {
                auto it1=inds[1].begin();

                if(*it1==i){
                    // dbgv(i);
                    inds[1].erase(it1);
                    // inds[1].pop();
                    if(inds[1].empty()){
                        onedone=true;
                    }
                } else {
                    c++;
                    int p=*it1;
                    res+= to_string(*inds[2].begin())+" "+to_string(p)+endl;
                    
                    inds[1].erase(it1);
                    inds[2].erase(inds[2].begin());
                    inds[2].insert(p);
                    if(inds[1].empty()){
                        onedone=true;
                    }
                }
            }
        } else{
            if(i==*inds[0].begin()){
                inds[0].erase(inds[0].begin());
                if(inds[0].empty()){
                        zerodone=true;
                }
            } else {
                if(*inds[1].begin()==i){
                    c++;
                    int p=*inds[0].begin();
                    res+= (to_string(*inds[1].begin())+" "+to_string(p))+endl;
                    
                    inds[0].erase(inds[0].begin());
                    inds[1].erase(inds[1].begin());
                    inds[1].insert(p);
                    if(inds[0].empty()){
                        zerodone=true;
                    }
                } else{
                    // cout<<"Her"<<endl;
                    c+=2;
                    int p0=*inds[0].rbegin();
                    int p1=*inds[1].rbegin();
                    int p2=*inds[2].begin();
                    // if(p1>p0){
                        res+= (to_string(p2)+" "+to_string(p1))+endl;
                        res+= (to_string(p2)+" "+to_string(p0))+endl;
                        
                        inds[0].erase(prev(inds[0].end()));
                        inds[1].erase(prev(inds[1].end()));
                        inds[2].erase(inds[2].begin());
                        inds[1].insert(p0);
                        inds[2].insert(p1);
                        if(inds[0].empty()){
                            zerodone=true;
                        }
                    // } else {
                    //     c++;
                    //     res+= (to_string(p1)+" "+to_string(p0))+endl;
                    //     res+= (to_string(p2)+" "+to_string(p0))+endl;
                    //     res+= (to_string(p2)+" "+to_string(p1))+endl;
                        
                        
                    //     inds[0].erase(prev(inds[0].end()));
                    //     inds[1].erase(prev(inds[1].end()));
                    //     inds[2].erase(inds[2].begin());
                    //     inds[1].insert(p1);
                    //     inds[2].insert(p0);
                    //     if(inds[0].empty()){
                    //         zerodone=true;
                    //     }
                    // }
                    
            }
        }
    }

    
}
    if(c==0){
        cout<<0<<endl;
    } else {
        cout<<c<<endl;
        cout<<res<<endl;
    }



}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
