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
    vector<string> strs(n);
    forn(i,n){
        cin>>strs[i];
    }
    // dbga(strs,n);
    vector<vector<int>> dp1(n,vector<int> {0,0,0});
    vector<vector<int>> dp2(n,vector<int> {0,0,0});
    int c=0;
    int p=0;
    // First row
    forn(i,n){
        if(strs[0][i]=='1'){
            c++;
        
            dp1[i][0]++;
            dp1[i][1]++;
            dp1[i][2]++;
            
        }
    }
    // cout<<"dp1"<<endl;
    // forn(i,n){
    //     forn(j,3){
    //         cout<<dp1[i][j];
    //     }
    //     cout<<' ';
    // }
    // cout<<endl;
    for(int i=1;i<n;i++){
    
        if(p%2==0){
            forn(j,n){
                if(j==0){
                    dp2[j][2]=0;
                    dp2[j][0]=dp1[j][0];
                    dp2[j][1]=0;
                    if(n>1){
                        dp2[j][0]+=dp1[j+1][1];
                        dp2[j][1]+=dp1[j+1][1];
                    }
                    // dp2[1]
                } else if(j==n-1){
                    dp2[j][0]=dp1[j][0];
                    dp2[j][0]+=dp1[j-1][2];
                    dp2[j][1]=0;
                } else {
                    dp2[j][0]=dp1[j][0];
                    dp2[j][0]+=dp1[j+1][1];
                    dp2[j][0]+=dp1[j-1][2];
                    dp2[j][1]=dp1[j+1][1];
                    // dp2[j][1]+=dp1[j-1][1];
                    // dp2[j][1]+=dp1[j+1][1];
                    dp2[j][2]=dp1[j-1][2];
                }
            }
            // cout<<"dp2"<<endl;
            //     forn(i,n){
            //         forn(j,3){
            //             cout<<dp2[i][j];
            //         }
            //         cout<<' ';
            //     }
            //     cout<<endl;
            forn(j,n){
                // if(strs[i][j]=='1'){
                //     c+=(dp2[j][0]+1)%2;
                // }
                // c+=(dp2[j][0]+(strs[i][j]=='1'))%2;

                if((dp2[j][0]+(strs[i][j]=='1'))%2){
                    // dbgv(j);
                    // dbgv(i);
                    dp2[j][0]++;
                    dp2[j][1]++;
                    dp2[j][2]++;
                    c++;
                }
            }
                // cout<<"dp2"<<endl;
                // forn(i,n){
                //     forn(j,3){
                //         cout<<dp2[i][j];
                //     }
                //     cout<<' ';
                // }
                // cout<<endl;
        } else {
            forn(j,n){
                if(j==0){
                    dp1[j][2]=0;
                    dp1[j][0]=dp2[j][0];
                    dp1[j][1]=0;
                    if(n>1){
                        dp1[j][0]+=dp2[j+1][1];
                        dp1[j][1]+=dp2[j+1][1];    
                    }
                    // dp2[1]
                } else if(j==n-1){
                    dp1[j][0]=dp2[j][0];
                    dp1[j][0]+=dp2[j-1][2];
                    dp1[j][1]=0;
                } else {
                    dp1[j][0]=dp2[j][0];
                    dp1[j][0]+=dp2[j+1][1];
                    dp1[j][0]+=dp2[j-1][2];
                    dp1[j][1]=dp2[j+1][1];
                    // dp2[j][1]+=dp1[j-1][1];
                    // dp2[j][1]+=dp1[j+1][1];
                    dp1[j][2]=dp2[j-1][2];
                }
            }
            // cout<<"dp1"<<endl;
            //     forn(i,n){
            //         forn(j,3){
            //             cout<<dp1[i][j];
            //         }
            //         cout<<' ';
            //     }
            //     cout<<endl;
            forn(j,n){
                // if(strs[i][j]=='1'){
                //     c+=(dp2[j][0]+1)%2;
                // }
                // c+=(dp1[j][0]+(strs[i][j]=='1'))%2;
                if((dp1[j][0]+(strs[i][j]=='1'))%2){
                    // dbgv(j);
                    // dbgv(i);
                    dp1[j][0]++;
                    dp1[j][1]++;
                    dp1[j][2]++;
                    c++;
                }
            }   
                // cout<<"dp1"<<endl;
                // forn(i,n){
                //     forn(j,3){
                //         cout<<dp1[i][j];
                //     }
                //     cout<<' ';
                // }
                // cout<<endl;
        }
        p++;
        // dbgv(c);
    }
    

    cout<<c<<endl;
}

int main() {
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
