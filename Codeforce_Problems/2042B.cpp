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

bool comp(vector<int> a,vector<int> b){
    return a[1]<b[1];
}

void solve(){
    int n;
    cin>>n;
    map<int,int> vals;
    forn(i,n){
        int d;
        cin>>d;
        vals[d]++;
    }

    deque<vector<int>> balls;
    for(auto it=vals.begin();it!=vals.end();it++){
        balls.push_back({it->first,it->second,1,0});
    }

    sort(balls.begin(),balls.end(),comp);
    
    int s=0;
    bool turn=true;
    while(!balls.empty()){
    //     for(int j=0;j<balls.size();j++){
    //     dbga(balls[j],3);
    // }
        if(turn){
            // dbgv(i);
            if(balls.front()[1]==1){
                if(balls.front()[2]==1){
                    s+=2;
                } else {
                    s++;
                }               
                balls.pop_front();

                turn=!turn;
            } else {
                // balls.front()[1]
                s+=1;
                if(balls.front()[2]==0){
                    balls.pop_front();
                } else {
                    balls.front()[3]=1;
                }
                turn=!turn;
            }
        } else {
            if(balls.front()[1]==1){
                balls.pop_front();
                // i++;
                turn=!turn;
            } else {
                // s+=1;
                if(balls.front()[3]==1){
                    balls.pop_front();   
                    // i++;
                } else {
                    balls.front()[1]-=1;
                    balls.front()[2]=0;
                    // i--;
                }
                
                turn=!turn;
            }
        }
    }

    cout<<s<<endl;
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
