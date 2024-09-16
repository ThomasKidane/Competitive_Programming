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

map<char,int> narek1;
map<int,char> narek2;
set<char> canBe={'n','a','r','e','k'};

pair<int,int> getSandE(string str,char s){
    int j=narek1[s];
    j%=5;
    int its=j;
    int fx=0;
    forn(i,str.size()){
        if(str[i]==narek2[j]){
            its++;
            j++;j%=5;
        } else if(canBe.find(str[i])==canBe.end()){
            fx++;
        }
    }
    return make_pair((its/5)*5-(str.size()-(its/5)*5)+fx,j);
}

int getMf(vector<int> v){
    if(!v.empty()){return v.back();}
    else return 0;
}

void solve(){
    int n,m;
    cin>>n>>m;
    double dp[n+1][5]={-1*INFINITY};
    forn(i,n+1)forn(j,5)dp[i][j]=(-1*INFINITY);
    dp[0][0]=0;
    string strs[n];
    forn(i,n){
        cin>>strs[i];
    }
    vector<int> nss;
    vector<int> ass;
    vector<int> rss;
    vector<int> ess;
    vector<int> kss;
    for(int i=1;i<=n;i++){
        forn(j,5){
            if(getSandE(strs[i-1],narek2[j]).ss==0 && dp[i-1][j]!=(-1*INFINITY)){
                // cout<<"True"<<endl;
                // dbgv(dp[i-1][j]);
                // dbgv(i);
                // dbgv(j);
                // dbgv(getSandE(strs[i-1],narek2[j]).first);
                // dbgv(strs[i-1]);
                // dbgv(narek2[j]);
                dp[i][0]=max(getSandE(strs[i-1],narek2[j]).first+dp[i-1][j],max(dp[i][0],dp[i-1][0]));
            } else if(getSandE(strs[i-1],narek2[j]).ss==1 && dp[i-1][j]!=(-1*INFINITY)){
                dp[i][1]=max(getSandE(strs[i-1],narek2[j]).first+dp[i-1][j],max(dp[i][1],dp[i-1][1]));
            } else if(getSandE(strs[i-1],narek2[j]).ss==2 && dp[i-1][j]!=(-1*INFINITY)){
                dp[i][2]=max(getSandE(strs[i-1],narek2[j]).first+dp[i-1][j],max(dp[i][2],dp[i-1][2]));
            } else if(getSandE(strs[i-1],narek2[j]).ss==3 && dp[i-1][j]!=(-1*INFINITY)){
                dp[i][3]=max(getSandE(strs[i-1],narek2[j]).first+dp[i-1][j],max(dp[i][3],dp[i-1][3]));
            }else if(getSandE(strs[i-1],narek2[j]).ss==4 && dp[i-1][j]!=(-1*INFINITY)){
                dp[i][4]=max(getSandE(strs[i-1],narek2[j]).first+dp[i-1][j],max(dp[i][4],dp[i-1][4]));
            }
        }
        forn(j,5){
            if(dp[i-1][j]!=(-1*INFINITY) && dp[i][j]==(-1*INFINITY)){
                dp[i][j]=dp[i-1][j];
        }
        }
        // sort(nss.begin(),nss.end());
        // sort(ass.begin(),ass.end());
        // sort(rss.begin(),rss.end());
        // sort(ess.begin(),ess.end());
        // sort(kss.begin(),kss.end());
        // dp[i-1][0]=max(getMf(nss)+dp[i-1][0],dp[i-1][0]);
        // if(dp[i-1][1]!=(-1*INFINITY) || !ass.empty()){
        //     dp[i][1]=max(getMf(ass)+dp[i-1][1],(ll)getMf(ass));
        // } else {
        //     dp[i][1]=(-1*INFINITY);
        // }
        // if(dp[i-1][2]!=(-1*INFINITY) || !rss.empty()){
        //     dp[i][2]=max(getMf(ass)+dp[i-1][2],(ll)getMf(rss));
        // } else {
        //      dp[i][2]=(-1*INFINITY);
        // }
        // if(dp[i-1][3]!=(-1*INFINITY) || !ess.empty()){
        //     dp[i][3]=max(getMf(ass)+dp[i-1][3],(ll)getMf(ess));
        // } else {
        //      dp[i][3]=(-1*INFINITY);
        // }
        // if(dp[i-1][4]!=(-1*INFINITY) || !kss.empty()){
        //     dp[i][4]=max(getMf(ass)+dp[i-1][4],(ll)getMf(kss));
        // } else {
        //     dp[i][4]=(-1*INFINITY);
        // }
        // nss.clear();
        // ass.clear();
        // rss.clear();
        // ess.clear();
        // kss.clear();
    }
    // forn(i,n+1){
    //     forn(j,5){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }

    cout<<max(dp[n][0],max(dp[n][1],max(dp[n][2],max(dp[n][3],dp[n][4]))))<<endl;
}

int main() {
    narek1['n']=0;
    narek1['a']=1;
    narek1['r']=2;
    narek1['e']=3;
    narek1['k']=4;
    narek2[0]='n';
    narek2[1]='a';
    narek2[2]='r';
    narek2[3]='e';
    narek2[4]='k';
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
