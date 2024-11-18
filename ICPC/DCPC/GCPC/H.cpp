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

// for string delimiter
vector<string> split(string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

// int main() {
//     std::string str = "adsf-+qwret-+nvfkbdsj-+orthdfjgh-+dfjrleih";
//     std::string delimiter = "-+";
//     std::vector<std::string> v = split (str, delimiter);

//     for (auto i : v) cout << i << endl;

//     return 0;
// }

void dfs(int i,map<int,vector<int>>&adj,vector<bool>& visited){
    visited[i]=true;
    // dbgv(i);
    // dbgv(visited.size());
    for(int j:adj[i]){
        // dbgv(j);
        if(!visited[j]){
            visited[j]=true;
            dfs(j,adj,visited);
        }
    }
}

void blowup(map<string,vector<int>>& package_methods,string packagename,map<int,vector<int>>& adj,vector<bool>& visited){
    for(int i=0;i<package_methods[packagename].size();i++){
        // dbgv
        dfs(package_methods[packagename][i],adj,visited);
    }
}



void solve(){
    int n;
    cin>>n;
    map<string,vector<int>> package_methods;
    map<string,int> packagetonum;
    map<int,string> numtopackage;
    map<int,vector<int>> adj;
    // vector<bool> tr(n);
    set<string> packs;
    vector<bool> visited(n+20);
    int i=1;
    for(int j=0;j<n;j++){
        string s;
        cin>>s;
        int v;
        cin>>v;
        // std::string s = "scott>=tiger";
        string delimiter = "::";
        vector<string> vals=split(s,delimiter);
        string packagename=vals[0];
        string methodname=vals[1];
        if(packagetonum[s]==0){
            while(numtopackage[i]!=""){
                i++;
            }
            numtopackage[i]=s;
            packagetonum[s]=i;
            i++;
        }        
        package_methods[packagename].push_back(packagetonum[s]);
        if(methodname=="PROGRAM"){
            packs.insert(packagename);
            // tr[packagetonum[s]]=true;
        }
        string bnmn;
        // dbgv(s);
        if(v!=0){
            for(int h=0;h<v;h++){
            string b;
            cin>>b;
            vector<string> vals=split(b,delimiter);
            string packagename=vals[0];
            string methodname=vals[1];
            if(packagetonum[b]==0){
                while(numtopackage[i]!=""){
                    i++;
                }
                numtopackage[i]=b;
                packagetonum[b]=i;
                i++;
            }
            
            
            package_methods[packagename].push_back(packagetonum[b]);
            // dbgv(v);
            // dbgv(b);
            adj[packagetonum[b]].push_back(packagetonum[s]);
            if(methodname=="PROGRAM"){
            packs.insert(packagename);
            // tr[packagetonum[s]]=true;
        }
        }
        }
        
    }

    // map<int,int> turnedon;
    for(string s:packs){
        // dbgv(s);
        dfs(packagetonum[s+"::PROGRAM"],adj,visited);
    }

    int c=0;
    for(bool x:visited){
        if(x)c++;
    }

    // dbga(packs,packs.size());
    // dbgv(packagetonum["B"]);
    // dbgv(adj[packagetonum["SuperGame::PROGRAM"]].size());
    // dbga(adj[packagetonum["SuperGame::PROGRAM"]],adj[packagetonum["SuperGame::PROGRAM"]].size());
    // dbgv(numtopackage[2]);
    // dbga(visited,visited.size());
    cout<<n-c;
    

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
