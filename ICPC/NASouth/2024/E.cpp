#include <bits/stdc++.h>
using ll =long long;
using ld=long double;
using namespace std;
#define endl "\n";
#define ff first
#define ss second

#define forn(i,n) for(int i=0;i<n;i++)
#define dbgv(v) cout<<#v<<" "<<v<<endl
#define dbga(a,n) forn(i,n-1) {cout<<a[i]<<' ';} cout<<a[n-1]<<endl

const int N=int(1e5+20);

int component[int(1e5+20)];
vector<pair<int,int>> maxSize1(N);// Size and where it came from
int maxSize2[N];

vector<int> G[N];
// int component[N];
vector<int> dp(N);

bool comp(pair<int,int>& p1,pair<int,int>& p2){
    // if(p1.ff!=p2.ff){
        return p1.ff<p2.ff;
    // }
}

int dfsCandHeight(int s,int e,int i,vector<bool> &seen,int h){
    // Came from S and now at E
    // i is the connected component number
    seen[e]=true;
    component[e]=i;
    int v=0;
    int f=0;
    vector<pair<int,int>> lengths;// The height and where it came from
    int c=0;
    for(int n:G[e]){
        if(n!=s){
            c++;
            // if(f==0){
            pair<int,int> hv=make_pair(dfsCandHeight(e,n,i,seen,h+1),n);// Height and where it came from
                v=max(hv.ff,v);
                lengths.push_back(hv);
            // }
            
        }
    }
    sort(lengths.begin(),lengths.end(),comp);
    // dbgv(e);
    // dbgv(lengths.size());
    if(lengths.size()>1){
        maxSize2[e]=max(lengths[lengths.size()-2].ff,h);
    } else {
        maxSize2[e]=h;
    }
    if(lengths.size()>0){
        maxSize1[e]=make_pair(v,lengths.back().second);
    } else {
        // if(d)
        maxSize1[e]=make_pair(0,0);
    }

    return v+1;
}

void dfs(int s,int e,pair<int,int>& p,vector<bool> &seen){
    seen[e]=true;
    if(s==0){
        dp[e]=maxSize1[e].ff;
    } else {
        if(p.second==e){
            // if(maxSize2[s]==0)
            // if(maxSize1[e].ss){
            //     dp[e]=maxSize1[e].ff+max(maxSize2[s],1);
            // } else {
            dbgv(e);
            dbgv(s);
            dbgv(maxSize2[s]);
            dbgv(maxSize1[e].ff);
                dp[e]=max(maxSize2[s]+1,maxSize1[e].ff);
            // }
            
        } else {
            dp[e]=max(maxSize1[e].ff,maxSize1[s].ff+1);
        }
    }
    for(int n:G[e]){
        if(n!=s){
            // if(f==0){
            // pair<int,int> hv=make_pair(dfsCandHeight(e,n,i),n);// Height and where it came from
                // v=max(hv.ff,v);
                // lengths.push_back(hv);
            // }
            dfs(e,n,maxSize1[e],seen);
            
        }
    }
    // dfs(e,)
}


void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> cc(n+1,0);
    forn(i,n-3){
        int x,y;
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
        cc[x]+=1;
        cc[y]+=1;
    }
    vector<bool> seen(n+1,false);
    int c=1;
    // Find Connected Compoennets
    pair<int,int> thr=make_pair(0,0);
    for(int i=1;i<=n;i++){
        
        if(!seen[i] && cc[i]==1){
            dbgv(i);
            // cout<<"First Root "<<i<<endl;
            dfsCandHeight(0,i,c,seen,0);
            c++;
        }
        if(c==4){
            break;
        }
    }
    // map<int,int> c1=1;
    vector<bool> seen1(n+1,false);
    for(int i=1;i<=n;i++){
        if(!seen1[i]){
            dfs(0,i,thr,seen1);
            // c1++;
        }
        // if(c1==4){
        //     break;
        // }
    }
    // cout<<"Node 1"<<endl;
    // dbga(G[1],G[1].size());

    

    int A=0;
    int a=0;
    int B=0;
    int b=0;
    int C=0;
    int d=0;
    forn(i,n+20){
        if(component[i]){
            if(component[i]==1){
                A=max(dp[i]+1,A);
                a++;
            } else if(component[i]==2){
                B=max(dp[i]+1,B);
                b++;
            } else{
                C=max(dp[i]+1,C);
                d++;
            }
        }
    }
    dbga(dp,14);
    // forn(i,14){
    //     dbgv(i);
    //     cout<<maxSize1[i].ff<<" "<<maxSize1[i].ss;
    //     cout<<endl;
    // }
    // cout<<endl;
    dbga(maxSize2,15);
    // dbgv
    
    // dbgv(A);
    // dbgv(B);
    // dbgv(C);
    // dbga(component,15);
    // dbga

    forn(i,q){
        int x,y;
        cin>>x>>y;
        if((component[x]==1 && component[y]==2) || (component[x]==2 && component[y]==1)){
            cout<<C+dp[x]+dp[y]+2<<endl;
        } else if((component[x]==1 && component[y]==3) || (component[x]==3 && component[y]==1)){
            cout<<B+dp[x]+dp[y]+2<<endl;
        } else {
            cout<<A+dp[x]+dp[y]+2<<endl;
        }
    }


}

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}