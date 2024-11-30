// C++ program to find the shortest possible route
// that visits every city exactly once and returns to
// the starting point using memoization and bitmasking

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

int totalCost(int mask, int curr, int n, 
              vector<vector<int>> &cost, vector<vector<int>> &memo) {
    
   // Base case: if all cities are visited, return the
    // cost to return to the starting city (0)
    if (mask == (1 << n) - 1) {
        return cost[curr][0];
    }

    if (memo[curr][mask] != -1)
        return memo[curr][mask];

    int ans = INT_MAX;

    // Try visiting every city that has not been visited yet
    for (int i = 0; i < n; i++) {
        if ((mask & (1 << i)) == 0) {
          
            // If city i is not visited, visit it and update 
           // the mask
        //    dbgv(cost[curr][i]);
            ans = min(ans, cost[curr][i] + 
                      totalCost((mask | (1 << i)), i, n, cost, memo));
                    // dbgv(ans);
        }
    }

    return memo[curr][mask] = ans;
}
 
int tsp(vector<vector<int>> &cost) {
    int n = cost.size();
    vector<vector<int>> memo(n, vector<int>(1 << n, -1));
  
    // Start from city 0, and only city 0 is visited
      // initially (mask = 1)
    int ans=20;
    for(int i=n-1;i>=0;i--){
        ans=min(totalCost((1<<i), i, n, cost,
                     memo),ans);
    }
    return ans;
}

// int main() {
  
//     vector<vector<int>> cost = {{0, 10, 15, 20}, 
//                                 {10, 0, 35, 25}, 
//                                 {15, 35, 0, 30}, 
//                                 {20, 25, 30, 0}};
 
//     int res = tsp(cost);
//     cout << res << endl;
//     return 0;
// }




void solve(){
    int n;
    cin>>n;
    map<string,vector<int>> gs;
    map<string,vector<int>> ws; 
    for(int i=0;i<n;i++){
        string g,w;
        cin>>g>>w;
        gs[g].push_back(i);
        ws[w].push_back(i);
    }

    vector<vector<int>> cost(n,vector<int> (n,1));
    // forn(i,n){
    //     forn(j,n){
    //         cost[i][j]=1;
    //     }
    // }
    for(auto it=gs.begin();it!=gs.end();it++){
        for(int i=0;i<it->second.size();i++){
            for(int j=0;j<it->second.size();j++){
                cost[it->second[i]][it->second[i]]=0;
            // if(i!=j){
                cost[it->second[i]][it->second[j]]=0;
                cost[it->second[j]][it->second[i]]=0;
                cost[it->second[i]][it->second[i]]=0;
                // }
        }    
        }
    }
    for(auto it=ws.begin();it!=ws.end();it++){
        for(int i=0;i<it->second.size();i++){
            for(int j=0;j<it->second.size();j++){
                cost[it->second[i]][it->second[i]]=0;
            // if(i!=j){
                cost[it->second[i]][it->second[j]]=0;
                
                cost[it->second[j]][it->second[i]]=0;
            // }
        }    
        }
    }
    forn(i,n){
        forn(j,n){
            cout<<cost[i][j]<<' ';
        }
        cout<<endl;
    }
    int res=tsp(cost);
    cout<<res<<endl;

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
