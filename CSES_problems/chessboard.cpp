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
bool check(vector<string> &board){
    // Row Check
    for(int i=0;i<8;i++){
        int c=0;
        for(int j=0;j<8;j++){
            if(board[i][j]=='?')c++;
        }
        if(c>1) return false;
    }
    // Column Check
    for(int i=0;i<8;i++){
        int c=0;
        for(int j=0;j<8;j++){
            if(board[j][i]=='?')c++;
        }
        if(c>1) return false;
    }
    // Diagonal Check from tl to br
    for(int j=0;j<8;j++){
        int c=0;
        for(int i=0;i<8-j;i++){
            if(board[i][j+i]=='?')c++;
        }
        if(c>1) return false;
    }
    // Diagonal Check from tr to bl
    for(int j=7;j>=0;j--){
        int c=0;
        for(int i=0;i<=j;i++){
            if(board[i][j-i]=='?')c++;
        }
        if(c>1) return false;
    }
    return true;
}

int validPaths(int left,vector<string> &board,int x,set<int>& y){
    // dbgv(left);
    int c=0;

    if(left<=0 && x==8){
        return 1;
    }

    for(int i=x;i<=x;i++){
        
            for(int j=0;j<8;j++){
                if(y.find(j)==y.end()){
                    if(board[i][j]=='.'){
                        board[i][j]='?';
                        if(check(board)){
                            // cout<<"Never";
                            y.insert(j);
                            c+=validPaths(left-1,board,x+1,y);
                            y.erase(j);
                        }
                        board[i][j]='.';  
                }
                }            
        }
        
    }
    // dbgv(c);
    return c;
}

void solve(){
    vector<string> board(8);
    forn(i,8){
        cin>>board[i];
    }
    set<int> x;
    set<int> y;
    cout<<validPaths(8,board,0,y);
}

int main() {
    int T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
