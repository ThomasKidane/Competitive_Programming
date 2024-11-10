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

int mem[100015][2][7];//n,p,c-1based

int dfs(vector<string> &strs,int n,int p,int c,int (&mem)[][2][7]){
    // dbgv(n);
    // dbgv(p);
    // dbgv(c);
    if(n<0 && (c==1 || c==4)){
        return 0;
    } else if(n<0){
        return -1;
    }
    else if(mem[n][p][c]!=-2){
        
        return mem[n][p][c];
    }
    else {
        if(c==1){
            // cout<<"Called 1"<<endl;
            int ret1=0;
            int c1=0;
            int c2=0;
            // Straight line, p=0
            for(int i=n-2;i<=n;i++){
                if('A'==strs[p][i])c1++;
            }
            for(int i=n-2;i<=n;i++){
                if('A'==strs[p+1][i])c2++;
            }
            ret1+=(c1>=2)+(c2>=2);
            ret1+=max(dfs(strs,n-3,p,1,mem),dfs(strs,n-3,1,4,mem));
            // dbgv(c1);
            // dbgv(c2);
            // Curved
            int c=0;
            if(strs[p][n]=='A')c++;
            if(strs[p+1][n]=='A')c++;
            if(strs[p+1][n-1]=='A')c++;
            int ret2=(c>=2);
            ret2+=max(dfs(strs,n-3,p,1,mem),max(dfs(strs,n-1,p,2,mem),dfs(strs,n-3,1,4,mem)));
            // dbgv(ret2);

            mem[n][p][c]=max(ret1,ret2);
            return mem[n][p][c];
        } else if(c==2){
            // cout<<"Called 2"<<endl;
            // Curved
            int c=0;
            if(strs[p][n]=='A')c++;
            if(strs[p][n-1]=='A')c++;
            if(strs[p+1][n-1]=='A')c++;
            int ret2=(c>=2);
            ret2+=max(dfs(strs,n-2,p,1,mem),dfs(strs,n-2,1,4,mem));
            int ret=0;
            int c1=0;
            // Straight
            for(int i=n-2;i<=n;i++){
                if('A'==strs[p][i])c1++;
            }

            ret+=(c1>=2);
            ret+=dfs(strs,n-1,1,6,mem);
            mem[n][p][c]=max(ret,ret2);
            return mem[n][p][c];
        } else if(c==3){
            // cout<<"Called 3"<<endl;
            int ret=0;
            int c1=0;
            // Straight
            for(int i=n-2;i<=n;i++){
                if('A'==strs[p][i])c1++;
            }

            ret+=(c1>=2);
            ret+=dfs(strs,n-2,1,5,mem);
            mem[n][p][c]=ret;
            return mem[n][p][c];
        } else if(c==4){
            // cout<<"Called 4"<<endl;
            int ret1=0;
            int c1=0;
            int c2=0;
            // Straight line, p=0
            for(int i=n-2;i<=n;i++){
                if('A'==strs[p][i])c1++;
            }
            for(int i=n-2;i<=n;i++){
                if('A'==strs[p-1][i])c2++;
            }
            
            ret1+=(c1>=2)+(c2>=2);
            ret1+=max(dfs(strs,n-3,0,1,mem),dfs(strs,n-3,1,4,mem));
            
            // Curved
            int c=0;
            
            if(strs[p][n]=='A')c++;
            // cout<<"Her"<<endl;
            if(strs[p-1][n]=='A')c++;
            if(strs[p-1][n-1]=='A')c++;
            int ret2=(c>=2);
            
            ret2+=max(dfs(strs,n-3,0,1,mem),max(dfs(strs,n-1,p,5,mem),dfs(strs,n-3,1,4,mem)));

            mem[n][p][c]=max(ret1,ret2);
            return mem[n][p][c];
        } else if(c==5){
            // cout<<"Called 5"<<endl;
            // Curved
            int c=0;
            if(strs[p][n]=='A')c++;
            if(strs[p][n-1]=='A')c++;
            if(strs[p-1][n-1]=='A')c++;
            int ret2=(c>=2);
            ret2+=max(dfs(strs,n-2,0,1,mem),dfs(strs,n-2,1,4,mem));
            int ret=0;
            int c1=0;
            // Straight
            for(int i=n-2;i<=n;i++){
                if('A'==strs[p][i])c1++;
            }

            ret+=(c1>=2);
            ret+=dfs(strs,n-1,0,3,mem);
            mem[n][p][c]=max(ret,ret2);
            return mem[n][p][c];
        } else if(c==6){
            // cout<<"Called 6"<<endl;
            int ret=0;
            int c1=0;
            // Straight
            for(int i=n-2;i<=n;i++){
                if('A'==strs[p][i])c1++;
            }

            ret+=(c1>=2);
            ret+=dfs(strs,n-2,0,2,mem);
            mem[n][p][c]=ret;
            return mem[n][p][c];
        }
    }
}

void solve(){
    int n;
    cin>>n;
    vector<string> strs(2);
    cin>>strs[0];
    cin>>strs[1];
    forn(i,n){
        forn(j,2){
            forn(k,7){
                mem[i][j][k]=-2;
            }
        }
    }
    
    cout<<max(dfs(strs,n-1,0,1,mem),dfs(strs,n-1,1,4,mem))<<endl;
    // forn(i,5){
    //     forn(j,2){
    //         dbgv(i);
    //         dbgv(j);
    //         cout<<mem[i][j][1]<<' ';            
    //         cout<<endl;
    //     }
    //     cout<<endl;
    //     cout<<endl;
    // }
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
