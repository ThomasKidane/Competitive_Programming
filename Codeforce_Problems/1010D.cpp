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

bool def(int i,map<int,int> &val,map<int,vector<int>>&adj,vector<int>&storage){
    if(val[i]==0){
        // cout<<"here"<<endl;
        return storage[i];
    } else if(val[i]==1) {
        storage[i]=def(adj[i][0],val,adj,storage)&&def(adj[i][1],val,adj,storage);
        // dbgv(storage[i]);
        // dbgv(def(adj[i][0],val,adj,storage));
        // dbgv(def(adj[i][1],val,adj,storage));
        return storage[i];
    } else if(val[i]==2) {
        storage[i]=def(adj[i][0],val,adj,storage)||def(adj[i][1],val,adj,storage);
        return storage[i];
    } else if(val[i]==3) {
        storage[i]=(def(adj[i][0],val,adj,storage))!=(def(adj[i][1],val,adj,storage));
        // dbgv(adj[i][0]);
        // dbgv(adj[i][1]);
        // dbgv(def(adj[i][0],val,adj,storage));
        // dbgv(def(adj[i][1],val,adj,storage));
        return storage[i];
    } else{
                // cout<<"here"<<endl;
    
        storage[i]=def(adj[i][0],val,adj,storage)==0;
        
        return storage[i];
    }
}

void changes(int i,map<int,int>&val,map<int,vector<int>>&adj,vector<int>&storage,string& res){
    if(val[i]==0){
        // cout<<"here"<<endl;
        res[i]='1';
    } else if(val[i]==1) {
        if(storage[adj[i][0]]==1 && storage[adj[i][1]]==1){
            changes(adj[i][0],val,adj,storage,res);
            changes(adj[i][1],val,adj,storage,res);
        } else if(storage[adj[i][0]]!=storage[adj[i][1]]){
            
            if(!storage[adj[i][0]]){
                
                changes(adj[i][0],val,adj,storage,res);
            } else {
                
                changes(adj[i][1],val,adj,storage,res);
            }
        }
        // cout<<"here"<<endl;
        // return def(adj[i][0],val,adj,storage)&&def(adj[i][0],val,adj,storage);
    } else if(val[i]==2) {
        if(storage[adj[i][0]]==0 && storage[adj[i][1]]==0){
            changes(adj[i][0],val,adj,storage,res);
            changes(adj[i][1],val,adj,storage,res);
        } else if(storage[adj[i][0]]!=storage[adj[i][1]]){
            if(storage[adj[i][0]]){
                changes(adj[i][0],val,adj,storage,res);
            } else {
                changes(adj[i][1],val,adj,storage,res); 
            }
           
            
        }
        // return def(adj[i][0],val,adj,storage)||def(adj[i][0],val,adj,storage);
    } else if(val[i]==3) {
        // if(!storage[i]){
            changes(adj[i][0],val,adj,storage,res);
            changes(adj[i][1],val,adj,storage,res);
        // }
    } else {
        changes(adj[i][0],val,adj,storage,res);
    }   
}

void solve(){
    int n;
    cin>>n;
    // 0 -> IN, 1 -> and, 2-> or, 3-> xor, 4-> Not
    map<int,int> val;
    map<int,vector<int>> adj;
    vector<int> storage(n);
    forn(i,n){
        string s;
        cin>>s;
        if(s=="IN") {
            int v;
            cin>>v;
            storage[i]=v;
            val[i]=0;
        } else if(s=="AND") {
            int a,b;
            cin>>a>>b;
            a--;
            b--;
            val[i]=1;
            adj[i].push_back(a);
            adj[i].push_back(b);
        } else if(s=="OR") {
            int a,b;
            cin>>a>>b;
            a--;
            b--;
            val[i]=2;
            adj[i].push_back(a);
            adj[i].push_back(b);
        } else if(s=="XOR"){
            int a,b;
            cin>>a>>b;
            a--;
            b--;
            val[i]=3;
            adj[i].push_back(a);
            adj[i].push_back(b);
        } else if(s=="NOT") {
            int a;
            cin>>a;
            a--;
            val[i]=4;
            adj[i].push_back(a);
            // adj[i].push_back(b);
        }
    }
    string res="";
    // dbga(storage,n);

    int defval=(int)def(0,val,adj,storage);
    forn(i,n){
        // if(val[i]==0){
            res+='0';
        // }else {
            // res+='0';
        // }
    }
    dbga(storage,n);

    changes(0,val,adj,storage,res);
    string r="";
    forn(i,n){
        if(val[i]==0)continue;
        cout<<(i==adj[i][0])<<endl;
    }
    // dbgv(defval);
    forn(i,n){
        if(val[i]==0 && res[i]=='1'){
            r+=to_string(!defval);
        }else if(val[i]==0){
            r+=to_string(defval);
        }
    }

    cout<<r<<endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
